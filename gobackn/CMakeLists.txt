cmake_minimum_required(VERSION 3.16)
project(gobackn)

set(CMAKE_CXX_STANDARD 14)

add_definitions(-D PLATFORM_LINUX)

add_executable(GoBackN
        main.cpp
        platforms/platforms.h
        platforms/linux.h
        protocol/go_back_n.cpp protocol/go_back_n.h socket/socket_udp.cpp socket/socket_udp.h chui_proto.h)