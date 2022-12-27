#include <iostream>

// #define _BOOST_THREAD_
#ifdef _BOOST_THREAD_
#define BOOST_THREAD_VERSION 5
#include <boost/thread.hpp>

#include <boost/thread/lock_factories.hpp>
#include <boost/thread/lockable_adapter.hpp>
#include <boost/thread/thread_guard.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <boost/thread/shared_lock_guard.hpp>
#endif

#define _BOOST_TCP_UDP_
#ifdef _BOOST_TCP_UDP_
#include <boost/asio/ip/tcp.hpp>
#endif

int main(int, char**) {
    std::cout << "Hello, world!\n";
}
