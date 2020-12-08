//
// Created by zcy on 2020/12/7.
//

#ifndef GOBACKN_TIMER_H
#define GOBACKN_TIMER_H
#include <iostream>
#include <thread>
#include <chrono>
class timer {
    bool clear = false;
public:
    template<typename T>
    void setTimeout(T function, int delay);
    inline void stop(){
        this->clear = true;
    }

};

template<typename T>
void timer::setTimeout(T function, int delay) {
    this->clear = false;
    std::thread t([=]() {
        if (this->clear) return;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        if (this->clear) return;
        function();
    });
    t.detach();
}
#endif //GOBACKN_TIMER_H
