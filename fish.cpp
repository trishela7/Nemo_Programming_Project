#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "yellowtang.h"
#include "fish.h"
#include "butterflyfish.h"
#include "aquarium.h"


using namespace std;

Fish::Fish(int capacity, std::string name)
{
	m_current = 0;
	m_name = name;
	if(capacity < 0)
	{
		capacity = 3;
	}
	m_capacity = capacity;

	memory  = new char[capacity];

	for(int i = 0; i < capacity; i++)
		{	
			memory[i] = '.';

		}


}


Fish::Fish(const Fish &other)
{
	m_name = other.getName();

	//explicitly telling computer that you want to copy everything/deep copy vs. shallow copy
	m_capacity = other.getCapacity();
	memory = new char [other.getCapacity()];
	const char* other_m = other.getMemory();
	for(int i = 0; i < m_capacity; i++)
	{
		memory[i] = other_m[i];

	}
	//update m_current
	m_current = other.getAmount();

}	



Fish::~Fish()
{

	delete[] memory;

}


Fish& Fish::operator=(const Fish &other)
{

	m_name = other.getName();
	m_capacity = other.getCapacity();
	const char* other_m = other.getMemory();
	for(int i = 0; i < m_capacity; i++)
	{
		memory[i] = other_m[i];

	}
	//update 
	m_current = other.getAmount();

//return the Fish itself 
	return *this;

}


void Fish::remember(char c)
{
	if(m_current == m_capacity)
	{	
		//
		for(int i = 0; i < m_capacity-1; i++)
		{	

			memory[i] = memory[i+1]; 

		}

		//accessing a character itself, going through elements of the memory//memory is char*, and with array index[], 
		//it's a char
		memory[m_capacity-1] = c;

	}

	memory[m_current] = c;
	m_current++;

}


void Fish::forget()
{
	for(int i = 0; i < m_capacity; i++)
		memory[i] = '.';

}

void Fish::printMemory() const
{
	for(int i = 0; i < m_capacity; i ++)
	{
		std::cout << memory[i];

	}	

	std::cout << std::endl;
}


std::string Fish::getName() const
{
	return m_name;

}


const char* Fish::getMemory() const
{

	return memory;

}

int Fish::getAmount() const
{
	return m_current;

}

int Fish::getCapacity() const
{
	return m_capacity;

}




