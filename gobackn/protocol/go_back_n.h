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

#ifndef GOBACKN_GO_BACK_N_H
#define GOBACKN_GO_BACK_N_H

#include "../socket/socket_udp.h"
#include <queue>
#include <iostream>
#include "timer.h"
class go_back_n {
    static constexpr int MAX_BUFFER = 1024;
    using seq_nr = unsigned;
public:
    static constexpr int MAX_SEQ = 7;
    go_back_n(const string &source_addr,
              const unsigned int source_port, const string &target_addr,
              const unsigned int target_port);

    void start();

    ~go_back_n();

private:
    struct data {
        int _seq = -1;
        int _ack = -1;
        string _data = "";
    };

    void send(const data &);

    void receive(data &);

    void timeout();

    void send_data(struct data &);

    static constexpr bool between(const seq_nr a, const seq_nr b, const seq_nr c) {
        return ((a <= b) && (b < c)) || ((c < a) && (a <= b)) || ((b < c) && (c < a));
    }

    unsigned _data_expected;
    unsigned _next_data_to_send;
    unsigned _ack_expected;
    seq_nr _nbuffered;

    std::queue<string> _datas;
    struct data _buffer[MAX_SEQ + 1];
    socket_udp _socket;
    timer timers[MAX_SEQ+1];
    void start_timer(unsigned int next_data_to_send);
    void stop_timer(unsigned int);

};


#endif //GOBACKN_GO_BACK_N_H
