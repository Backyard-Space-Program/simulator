//
// thread.hpp
//
// created at 27/07/2021 18:03:48
// written by llamaking136
//


#if !defined(THREAD_HPP)
#define THREAD_HPP

#include <ctime>
#include <thread>
#include <iostream>

class Thread {
private:
	std::time_t startTime;
	std::time_t endTime;
	void threadFunction();
	void (*threadFunctionPointer)();
	std::thread threadRef;
	bool running;
	bool shouldStop;
public:
	 Thread(void (*)());
	~Thread();

	void start();
	void waitUntilFinish();
	void stop();
	inline bool isRunning() const { return this->running; }
	inline std::time_t getStartTime() const { return this->startTime; }
	inline std::time_t getEndTime() const { return this->endTime; }
	inline std::time_t getTotalTime() const { if (this->running) return std::time(0) - this->startTime; return this->endTime - this->startTime; }
};

#endif // THREAD_HPP
