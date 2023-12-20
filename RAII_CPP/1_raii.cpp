#include <mutex>
#include <thread>
#include <iostream>

std::mutex my_mutex;

// func to be run on multiple threads
void print_func(){
    my_mutex.lock();
    std::cout << "printing from thread" << std::endl;
    my_mutex.unlock();
}

// raii print func 
// mutex gets unlocked automatically when it gets out of scope
void raii_print_func() {
    std::lock_guard<std::mutex> g(my_mutex);
    std::cout << "printing from better thread" << std::endl;
}

int main() {
    std::thread t1(print_func);
    std::thread t2(print_func);
    t1.join();
    t2.join();

    std::thread t3(raii_print_func);
    std::thread t4(raii_print_func);
    t3.join();
    t4.join();
}