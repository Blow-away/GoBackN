/**
 * @copybrief
 *
 * MIT License
 * Copyright (c) 2020 chui
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * */

#include "go_back_n.h"

using std::cin;
using std::cout;
void go_back_n::stop_timer(unsigned ack_expected) {
    timers[ack_expected].stop();
    std::cout<<"stop_timer: "<<ack_expected<<"\n";
}

void go_back_n::start_timer(unsigned next_data_to_send) {
    timers[next_data_to_send].setTimeout([this] {
        timeout();
    }, 10000);
    std::cout<<"start_timer: "<<next_data_to_send<<"\n";
}

void go_back_n::timeout() {
    _next_data_to_send = _ack_expected;
    for (int i = 0; i < _nbuffered; ++i) {
        std::cout << "已重发序号为" << _next_data_to_send << "的data\n";
        send_data(_buffer[_next_data_to_send]);
        _next_data_to_send = (_next_data_to_send + 1) % (MAX_SEQ + 1);
    }
}
go_back_n::~go_back_n() = default;

go_back_n::go_back_n(const string &source_addr,
                     const unsigned int source_port, const string &target_addr,
                     const unsigned int target_port) : _socket(source_addr, source_port, target_addr, target_port),
                                                       _data_expected(0), _next_data_to_send(0),
                                                       _ack_expected(0), _nbuffered(0) {
}

void go_back_n::receive(data &data) {
    char temp[1024];
    int result = _socket.read(temp, 1024);
    string rcv_string;
    for(int i=0;i<result;++i){
        rcv_string += temp[i];
    }
    if (result == 0||rcv_string.empty()) {
        std::cout<<"未收到数据"<<std::endl;
        return;
    } else {
        data._seq = rcv_string[0];
        data._ack = rcv_string[1];
        data._data = rcv_string.substr(2);
    }
}

void go_back_n::send(const data &data) {
    string snd_string;
    // ack,seq最大为7，只占一位
    snd_string.push_back(data._seq);
    snd_string.push_back(data._ack);
    snd_string += data._data;
    _socket.write(snd_string.c_str(), snd_string.size());
}


void go_back_n::send_data(struct data &data) {
    data._seq = static_cast<int>(_next_data_to_send);
    //发送最后收到的序号的ack，即为data_expected-1
    data._ack = (static_cast<int>(_data_expected) + MAX_SEQ) % (MAX_SEQ + 1);
    send(data);
    _buffer[_next_data_to_send] = data;
    start_timer(_next_data_to_send);
}

void go_back_n::start() {
    std::thread([this]{
        while(1){
            struct data rev_data;
            receive(rev_data);
            if (rev_data._seq == _data_expected) {
                std::cout << "接收到序号正确的信息： " + rev_data._data + "\n";
                data temp;
                temp._ack = _data_expected;
                send(temp);
                        //inc data_expected
                _data_expected = (_data_expected + 1) % (MAX_SEQ + 1);
            }
            while (between(_ack_expected, rev_data._ack, _next_data_to_send)) {
                _nbuffered--;
                std::cout<<"第"<<_ack_expected<<"号data已确认\n";
                stop_timer(_ack_expected);
                _ack_expected = (_ack_expected + 1) % (MAX_SEQ + 1);
            }
        }
    }).detach();
    while (true) {
        cout << "Please input the data you want to send: (enter to skip || 'q' to quit) \n";
        char temp[MAX_BUFFER];
        cin.getline(temp, MAX_BUFFER);
        string snd_data = temp;
        struct data data;
        data._data = snd_data;
        if (!snd_data.empty()) {
            if (snd_data == "q")
                break;
            this->_datas.push(snd_data);
            if (this->_nbuffered <= MAX_SEQ) {
                _nbuffered++;

                data._data = _datas.front();
                _datas.pop();

                std::cout << "已发送";

                send_data(data);
                // inc _next_data_to_send
                _next_data_to_send = (_next_data_to_send + 1) % (MAX_SEQ + 1);
            }
        }
    }
}


