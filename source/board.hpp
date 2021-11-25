//
// board.hpp
//
// created at 24/11/2021 16:45:51
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


#if !defined(BOARD_HPP)
#define BOARD_HPP

enum PinType {
	GPIO,

	// SPI
	MISO,
	MOSI,
	SCK,
	CS,

	// I2C
	SCL,
	SDA,

	// POWER
	GND,
	5V,
	3V,
	VIN,
	RESET,


	SERIAL,
	SERIAL1,
	SERIAL2
}

struct Pin {
	unsigned int pinNo;
	std::string name;
	PinType type;

	double voltage; // GPIO only


	bool isPWM;
	bool isAnalog;
	bool isInt;
};

class Board {
private:
	bool isRunning;
	std::string name;
	unsigned int numPins;
	Pin pins[];

};

#endif // BOARD_HPP
