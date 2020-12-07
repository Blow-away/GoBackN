/**
 * @copybrief
 * The MIT License (MIT)
 * Copyright(c) 2020-2020 Blow-away
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
 * */

#include "go_back_n.h"

using std::cin;
using std::cout;

go_back_n::~go_back_n() = default;

go_back_n::go_back_n(const string &addr, const unsigned int port) : _socket(addr, port),
                                                                    _data_expected(0), _next_data_to_send(0),
                                                                    _ack_expected(0), _nbuffered(0),
                                                                    _buffer_index(0){}

void go_back_n::receive(data& data) {
    char *temp = new char[MAX_BUFFER];
    int result = _socket.read(temp, MAX_BUFFER);
    string rcv_string(temp);
    delete[] temp;
    if (result == 0){
        data._seq = MAX_SEQ; // 表示收到的是空data
        data._ack = MAX_SEQ;
        data._data = "";
    }else{
        data._seq = rcv_string[0];
        data._ack = rcv_string[1];
        data._data = rcv_string.substr(2);
    }
}

void go_back_n::send(const data &data) {
    string snd_string;
    snd_string.push_back(data._seq);
    snd_string.push_back(data._ack);
    snd_string+=data._data;
    _socket.write(snd_string.c_str(), sizeof(snd_string.c_str()));
}

void go_back_n::start() {
    while (true) {
        cout << "Please input the data you want to send: (enter to skip || 'q' to quit) \n";
        string snd_data;
        cin >> snd_data;
        if (!snd_data.empty()) {
            if (snd_data == "q")
                break;
            this->_datas.push(snd_data);
            if(this->_nbuffered<=MAX_SEQ){
                this->_buffer[this->_buffer_index] = _datas.front();
                _datas.pop();
                //linux timer
                #ifdef PLATFORM_LINUX

                #endif // PLATFORM_LINUX

            }

        } else {
            struct data rev_data;
            receive(rev_data);


//#ifdef PLATFORM_LINUX
//
//#endif // PLATFORM_LINUX

        }
    }
}
