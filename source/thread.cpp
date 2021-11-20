//
// thread.cpp
//
// created at 27/07/2021 18:03:48
// written by llamaking136
//


#include "thread.hpp"

Thread::Thread(void (*threadFunctionPointer)()) {
	this->threadFunctionPointer = threadFunctionPointer;
	this->running = false;
	this->shouldStop = false;
}

Thread::~Thread() {
	if (this->running)
		std::cout << "detaching\n";
		this->threadRef.detach();
}

void Thread::threadFunction() {
	this->running = true;
	this->startTime = std::time(0);
	this->threadRef = std::thread(this->threadFunctionPointer);
	this->endTime = std::time(0);
	this->running = false;
}

void Thread::start() {
	this->threadFunction();
}

void Thread::waitUntilFinish() {
	if (!this->running)
		return;
	this->threadRef.join();
}

void Thread::stop() {
	this->shouldStop = true;
}
