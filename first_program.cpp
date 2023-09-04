// #include - preprocessor directive to include content of a file or library
// stdio.h - library to perform input/output operations
#include <stdio.h>
// math.h - library with common mathematical operations and transformations
#include <math.h>
// main function, program execution starts from here
// int - output type, void - parameter type
int main(void)
{	
	// Declaration of variables 
	// int - type of integer numbers
	int a, b, c;
	// printf - function for printing information on standard output stream (console)
	// " " - string notation
	printf("Enter number a: ");
	// scanf - function for reading information from standard input stream (console)
	// %d - integer number format specification 
	scanf("%d", &a);

	printf("Enter number b: ");

	scanf("%d", &b);
	// assignment operation
	c = a + b;

	printf("%d + %d = %d", a, b, c);
	// returning program execution code
	return 0;
}