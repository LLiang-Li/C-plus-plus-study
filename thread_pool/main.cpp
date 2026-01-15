#include <iostream>
#include <unistd.h>
#include "thread_pool.hpp"


int main(int, char**){
    ThreadPool st;
    st.Start();
    st.AddTask([](int i){std::cout << "thread: " << i << "-----\n";});
    st.AddTask([](int i){std::cout << "thread: " << i << "-----\n";});
    st.AddTask([](int i){std::cout << "thread: " << i << "-----\n";});
    st.AddTask([](int i){std::cout << "thread: " << i << "-----\n";});
    st.AddTask([](int i){std::cout << "thread: " << i << "-----\n";});
    st.AddTask([](int i){std::cout << "thread: " << i << "-----\n";});
    st.AddTask([](int i){std::cout << "thread: " << i << "-----\n";});
    st.AddTask([](int i){std::cout << "thread: " << i << "-----\n";});
    st.AddTask([](int i){std::cout << "thread: " << i << "-----\n";});
    return 0;
}
