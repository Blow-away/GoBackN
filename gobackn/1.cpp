#include "chui_proto.h"
int main(){
    go_back_n s1(   "127.0.0.1",
                    12345,
                    "127.0.0.1",
                    2333);
    s1.start();
//    socket_udp s1(   "127.0.0.1",
//                    12345,
//                    "127.0.0.1",
//                    2333);
//    while(1) {
//        char buff[1024];
//        s1.read(buff, 1024);
//        std::cout << buff << "\n";
//    }
}