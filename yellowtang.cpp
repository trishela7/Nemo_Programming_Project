#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "yellowtang.h"


Yellowtang::Yellowtang(int capacity, std::string name) : Fish::Fish(capacity,name)
{	
  
  int bubbles_counter = 0;

}

Yellowtang::Yellowtang(const Yellowtang &other): Fish::Fish(other), bubbles_counter(other.bubbles_counter)
{}


Yellowtang& Yellowtang::operator=(const Yellowtang &other) 
{
	
	if(this != &other)
	{
		
		Fish::operator=(other);
		bubbles_counter = other.bubbles_counter;
		return *this;

		
	}
	
	return *this;

}


void Yellowtang::remember(char c) 
{
	if(c == 'o')
    	bubbles_counter = Fish::getCapacity();

    else
    {	Fish::remember(c);
  		bubbles_counter--;
				
  	}	
}



void Yellowtang::printMemory() const 
{
	
	if(bubbles_counter > 0)
		std::cout << "BUBBLES!" << std::endl;	
	else 
    	Fish::printMemory();


}		



void Yellowtang::forget()
{
	Fish::forget();
	bubbles_counter = 0;

}

