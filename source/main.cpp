//
// main.cpp
//
// created at 19/11/2021 19:01:06
// written by Backyard Space Program
//

// MIT License
//     
// Copyright (c) 2021 Backyard Space Program
//     
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//     
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//     
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#include "main.hpp"

#include <io.hpp>

AutoreleasePool global_pool;

Board* global_board;
Pin* global_pins;

void signal_handler(int sig) {
	lib::log("Received signal " + std::to_string(sig));
	pool_drain();
	exit(sig);
}

void pool_drain() {
	close_libs();
	std::cout << global_board << "\n";
	if (global_board != nullptr) delete global_board;
	std::cout << "1\n";
	if (global_pins != nullptr) delete[] global_pins;
	lib::log("Pool Drained");
}

int usage() {
	std::cerr << "usage: " << PROGNME << " [args]\n";
	return 1;
}

int main(int argc, char** argv) {
	global_pool = AutoreleasePool();
	global_pool.appendReleaseFunction(pool_drain);

	for (int i = 1; i < 6; i++) {
		signal(i, signal_handler);
	}

    int return_value = parseargs(argc, argv);
    if (return_value != 0) {
        return return_value;
    }

	unsigned int num_pins = 64;

	global_pins = new Pin[num_pins];
	global_board = new Board;

	global_board->name = "Not-A-Teensy";
	global_board->numPins = num_pins;
	global_board->pins = global_pins;

	global_board->pin_high = 2.0;
	global_board->pin_low = 0.0;

	setup();

	for (;;) {
		loop();
	}

	return 0;
}
