#include "chui_proto.h"
int main(){
    go_back_n s1(   "127.0.0.1",
                    2333,
                    "127.0.0.1",
                    12345);
    s1.start();
//    socket_udp s1(   "127.0.0.1",
//                    2333,
//                    "127.0.0.1",
//                    12345);
//    while(1){
//        string temp{};
//        std::cin>>temp;
//        s1.write(temp.c_str(),temp.size());
//    }
}