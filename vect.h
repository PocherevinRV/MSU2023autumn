#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ostream>
class Vect
{
private:
	int len;
	int* data;
public:
	// default constructor
	Vect();
	// constructor
	Vect(int num);
	// destructor
	~Vect();
	Vect operator+(const Vect &vect);
	Vect(const Vect &b);
	Vect& operator= (const Vect &vect);
	// output operator
	friend std::ostream& operator<<(std::ostream &out, const Vect& vect);
};




#endif