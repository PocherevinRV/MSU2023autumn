#include <iostream>
#include "vect.h"

int main(void)
{
	Vect a(3), b(3), d;
	d = a + b;
	std::cout << d << std::endl;
	return 0;
}