#ifndef YELLOWTANG_H
#define YELLOWTANG_H

#include "fish.h"
#include <iostream>



class Yellowtang :public Fish
{
	public:
		Yellowtang(int capacity, std::string name); // Constructor
		Yellowtang(const Yellowtang &other); // Copy Constructor
		Yellowtang &operator=(const Yellowtang &other); // Assignment Operator
		// Overridden functions
		virtual void remember(char c);
		virtual void printMemory() const;
		virtual void forget();
	private:
		int bubbles_counter;
};

#endif //YELLOWTANG_H