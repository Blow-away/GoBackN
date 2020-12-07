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

#ifndef GOBACKN_GO_BACK_N_H
#define GOBACKN_GO_BACK_N_H

#include "../socket/socket_udp.h"
#include <queue>
#include <iostream>
class go_back_n {
    static constexpr int MAX_SEQ = 7;
    static constexpr int MAX_BUFFER = 1024;
    using seq_nr = unsigned;
public:
    go_back_n(const string &addr,
              const unsigned int port);
    void start();
    ~go_back_n();

private:
    struct data{
        seq_nr _seq;
        seq_nr _ack;
        string _data;
    };
    void send(const data &data);

    void receive(data &data);

    static constexpr bool between(const seq_nr a, const seq_nr b, const seq_nr c) {
        return ((a <= b) && (b < c)) || ((c < a) && (a <= b)) || ((b < c) && (c < a));
    }

    unsigned _data_expected;
    unsigned _next_data_to_send;
    unsigned _ack_expected;
    seq_nr _nbuffered;
    seq_nr _buffer_index; // 指向第一个可以发送的buffer

    std::queue<string> _datas;
    string _buffer[MAX_SEQ+1];
    socket_udp _socket;
};


#endif //GOBACKN_GO_BACK_N_H
