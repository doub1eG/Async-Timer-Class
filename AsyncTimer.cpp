#include "AsyncTimer.hpp"

Timer::Timer(size_t timeDelay, const std::function<void(void)>& f)
    : m_delay{ std::chrono::seconds{timeDelay} }
    , m_callback{ f } {}

Timer::~Timer()
{
    cv.notify_one();
    m_waitThread.join();
}

void Timer::waitThenCall()
{
    std::unique_lock<std::mutex> lck{ m_mutex };
    cv.wait_for(lck, m_delay);

    m_callback();
}