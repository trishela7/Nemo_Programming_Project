#ifndef FISH_H
#define FISH_H


class Fish 
{
	public:
		Fish(int capacity, std::string name);// Constructor
		Fish(const Fish &other); // Copy Constructor
		virtual ~Fish(); // Destructor
		Fish &operator=(const Fish &other); // Assignment Operator
		virtual void remember(char c); // Remember c
		virtual void forget(); // Clears memory by filling in '.'
		virtual void printMemory() const;// Prints memory
		std::string getName() const;
	protected:
		const char* getMemory() const;// Returns memory
		int getAmount() const; // Returns amount remembered
		int getCapacity() const; // Returns memory capacity
	private:
		char* memory;
		std::string m_name;
		int m_capacity;
		int m_current;
};

#endif //FISH_H