#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <functional>
#include <mutex>

class Timer
{
	std::mutex m_mutex;
	std::condition_variable cv {};
	std::chrono::seconds m_delay;
	std::function <void(void)> m_callback;
	std::thread m_waitThread{ [this]() {waitThenCall(); } };
public:
	/*Ctor*/
	Timer(size_t timeDelay, const std::function<void(void)>& f);

	/*Deleter*/
	~Timer();

private:
	/*Callback function*/
	void waitThenCall();
};

#endif // !TIMER_H