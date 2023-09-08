#include <stdio.h>

// Program solves the problem to count the sum of numbers in sequence that greater than previous numbers

double sum_with_condition(FILE *f);

double sum_with_condition(FILE *f)
{
        
	double sum = 0., current = 0., previous = 0.;
	if (fscanf(f, "%lf", &current) != 1)
	{
		printf("File is empty");
		return 0.;
	}
	while (fscanf(f, "%lf", &current) == 1)
	{
		if (current > previous) sum += current;
		previous = current;
	}
	return sum;	
}


int main(void)
{
        FILE *f = fopen("input_data.txt", "r");
	if (f == NULL)
	{
		printf("File error");
		return -1;
	}
	else
	{
		printf("Answer: %lf", sum_with_condition(f));
		return 0;
	}
}