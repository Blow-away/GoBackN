cmake_minimum_required(VERSION 3.10)
project(gobackn)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-D PLATFORM_LINUX)

link_libraries(pthread)

add_executable(client
        platforms/platforms.h
        platforms/linux.h
        protocol/go_back_n.cpp protocol/go_back_n.h socket/socket_udp.cpp socket/socket_udp.h chui_proto.h
        protocol/timer.h
        1.cpp)
add_executable(server
        platforms/platforms.h
        platforms/linux.h
        protocol/go_back_n.cpp protocol/go_back_n.h socket/socket_udp.cpp socket/socket_udp.h chui_proto.h
        protocol/timer.h
        2.cpp)