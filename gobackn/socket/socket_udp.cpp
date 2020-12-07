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

#include <iostream>
#include "socket_udp.h"

socket_udp::socket_udp(const string &addr, const unsigned int port) {
#ifdef PLATFORM_LINUX
    this->_port = htonl(port);
    in_addr temp{};
    inet_aton(addr.c_str(), &temp);
    this->_addr = temp.s_addr;
    try {
        this->_socket_id = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (this->_socket_id < 0) {
            throw "socket create error!";
        }

        sockaddr_in p_addr{};
        p_addr.sin_family = AF_INET;
        p_addr.sin_addr.s_addr = this->_addr;

        int result = ::bind(this->_socket_id, reinterpret_cast<sockaddr *>(&p_addr), sizeof(p_addr));
        if (result != 0) {
            throw "socket bind error!";
        }
    } catch (const char *e) {
        std::cout << *e << std::endl;
    }
#endif //PLATFORM_LINUX
}

socket_udp::~socket_udp() {
    this->close();
}

size_t socket_udp::read(char *buff, const size_t &len) {
    if (len == 0) {
        return len;
    }
#ifdef PLATFORM_LINUX
    try {
        auto result = ::read(this->_socket_id, buff, len);
        if (result == -1) {
            throw "Read error!";
        }
        return result;
    } catch (const char *e) {
        std::cout << *e << std::endl;
    }
#endif //PLATFORM_LINUX
}

void socket_udp::write(const char *buff, const size_t &len) {
#ifdef PLATFORM_LINUX
    ::write(this->_socket_id, buff, len);
#endif //PLATFORM_LINUX
}

void socket_udp::close() {
#ifdef PLATFORM_LINUX
    ::close(this->_socket_id);
#endif //PLATFORM_LINUX
}






