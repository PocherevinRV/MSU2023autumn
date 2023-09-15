#include "sum_func.h"

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
