#include "vect.h" 
Vect::Vect()
{
	len = 0;
	data = NULL;	
}
Vect::Vect(int num)
{
	len = num;
	data = new int[num];
	for (int k = 0; k < len; ++k) data[k] = rand() % 1000;
	std::cout << "Constructor for " << *this << std::endl;
}
Vect::~Vect() 
{
	std::cout << "Destructor for " << *this << std::endl;
	delete []data;
}
Vect Vect::operator+(const Vect &vect)
{
	Vect result(len);
	for (int k = 0; k < len; ++k) 
		result.data[k] = data[k] + vect.data[k];
	return result;
}
Vect::Vect(const Vect &vect) : Vect(vect.len)
{
	for (int k = 0; k < len; ++k) data[k] = vect.data[k];
	std::cout << "Copy constructor" << *this << std::endl;	
}
Vect& Vect::operator= (const Vect &vect)
{
	if (this == &vect) return *this;
	len = vect.len;
	for (int k = 0; k < len; ++k) data[k] = vect.data[k];
	return *this;
}
std::ostream& operator<<(std::ostream &out, const Vect& vect)
{
	out << "(";
	for (int k = 0; k < vect.len; ++k)
		out << vect.data[k] << ", ";
	out << ")" << std::endl;
	return out;
}
