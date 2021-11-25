//
// io.cpp
//
// created at 24/11/2021 17:19:31
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


#include "io.hpp"

extern "C" {

int eval_pin(PinNo pin) { // turns voltage to value
	if ((double)pin >= board->pin_high) return HIGH;
	else return LOW;
}

int pin_eval(Mode value) { // turns value to voltage
	if (value == HIGH) return board->pin_high;
	else if (value == LOW) return board->pin_low;
	else return -1;
}

void pinMode(PinNo pin, Mode mode) {
	if (mode != INPUT && mode != OUTPUT) return;
	std::cout << board << "\n";
	board->pins[pin - 1].mode = mode;
}

int digitalRead(PinNo pin) {
	return eval_pin(board->pins[pin - 1].voltage);
}

void digitalWrite(PinNo pin, Mode value) {
	board->pins[pin - 1].voltage = pin_eval(value);
}

} // extern "C"
