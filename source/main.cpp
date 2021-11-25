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

AutoreleasePool global_pool;

Board* global_board;
Pin* global_pins;

void pool_drain() {
	close_libs();
	if (global_board) delete global_board;
	if (global_pins) delete[] global_pins;
	lib::log("Pool Drained");
}

int usage() {
	std::cerr << "usage: " << PROGNME << " [args]\n";
	return 1;
}

int main(int argc, char** argv) {
	global_pool = AutoreleasePool();
	global_pool.appendReleaseFunction(pool_drain);

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

	Board* std_board = (Board*)load_symbol("board", argv[1]);
	std_board = global_board;

	void (*std_pinMode)(PinNo, Mode) = (void(*)(PinNo, Mode))load_symbol("pinMode", argv[1]);

	std_pinMode(1, OUTPUT);

	lib::log(std::to_string(std_board->pins[0].mode));

	return 0;
}
