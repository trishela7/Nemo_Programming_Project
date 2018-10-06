#ifndef BUTTERFLYFISH_H
#define BUTTERFLYFISH_H


#include "fish.h"
#include <iostream>


class Butterflyfish :public Fish
{
	public:	
		Butterflyfish(int capacity, std::string name); // Constructor
		Butterflyfish(const Butterflyfish &other); // Copy Constructor
		Butterflyfish &operator=(const Butterflyfish &other); // Assignment Operator
		virtual ~Butterflyfish(); // Destructor
		// Overridden Functions
		virtual void remember(char c);
		virtual void printMemory() const;
	private:
		char* unique_chars; 
		int* unique_chars_counter;
		int b_capacity;
		int num_chars;

};


#endif //BUTTERFLYFISH_H