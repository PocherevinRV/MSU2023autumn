#include <math.h>
#include "sum_func.h"


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
		double result = sum_with_condition(f);
		if (fabs(result - N) < eps) printf("Special answer: %lf\n", N);
		else printf("Answer: %lf\n", result);
		return 0;
	}
}