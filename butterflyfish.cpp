#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "butterflyfish.h"


Butterflyfish::Butterflyfish(int capacity, std::string name): Fish::Fish(capacity, name)
{
	b_capacity = 2;
	num_chars = 0;
	unique_chars = new char[b_capacity];
	unique_chars_counter = new int[b_capacity];
	
}


Butterflyfish::Butterflyfish(const Butterflyfish &other): Fish::Fish(other),
unique_chars_counter(other.unique_chars_counter){}

Butterflyfish::~Butterflyfish()
{

	delete [] unique_chars;
	delete [] unique_chars_counter;

}


Butterflyfish& Butterflyfish::operator=(const Butterflyfish &other)
	
	{
		if(this != &other)
		{
			Fish::operator = (other);
			unique_chars = other.unique_chars;
			unique_chars_counter = other.unique_chars_counter;
			
			return *this;
		}
	

	return *this;
	
	}

void Butterflyfish::remember(char c)
{
	Fish::remember(c);
	int i = 0;
	bool seenCAlready = false;
	for(i = 0; i < num_chars; i++)
	{
		if(unique_chars[i] == c) 
		{
			unique_chars_counter[i]++;
			seenCAlready = true;

		}

	}

	if(!seenCAlready)
	{
		unique_chars[i] = c; 
		unique_chars_counter[i] = 1;
		num_chars++; //


	}


	if(num_chars == b_capacity)
	{
		b_capacity = 2 * b_capacity;

		char* temp = unique_chars; 
		int* temp_2 = unique_chars_counter;
		unique_chars = new char[b_capacity];
		unique_chars_counter = new int[b_capacity];

		for(int j = 0; j < num_chars; j++)
		{

			unique_chars[j] = temp[j];
			unique_chars_counter[j] = temp_2[j];

		}

	

		delete [] temp;
		delete [] temp_2;
	}


}

void Butterflyfish::printMemory() const
{

	Fish::printMemory();	

	std::cout << "I'm Obnoxious!" << std::endl;	
	std::cout << "I've seen:" << std::endl;
	
	for(int i = 0; i< num_chars; i++)
	{	
		std::cout << "  " << unique_chars[i] << "  " << unique_chars_counter[i] << " times"<< std::endl;
	

	}	

}



