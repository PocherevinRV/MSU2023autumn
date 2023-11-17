#include <stdio.h>

void binary_print(int number);
void binary_print(int number)
{
	int index = 8 * sizeof(int) - 1;
	unsigned int mask = 1 << index;
	for (; index >= 0; index--, mask >>= 1)
	{
		if (number & mask) printf("1"); else printf("0");
		if (index % 8 == 0) printf(" "); 
	}
}

int read_two_numbers(int *number1, int *number2);
int read_two_numbers(int *number1, int *number2)
{
	printf("\nEnter two numbers: ");
	if (scanf("%d %d", number1, number2) == 0) return -1;
	return 0;
}

int main(void)
{
	int number1, number2, shift_number;
	binary_print(7);
	if (read_two_numbers(&number1, &number2))
	{
		printf("Input error");
		return 0;
	}
	binary_print(number1);
	printf("= number1 = %d\n", number1);
	binary_print(number2);
	printf("= number2 = %d\n", number2);
	binary_print(number1 & number2);
	printf("= number1 & number2 = %d\n", number1 & number2);
	binary_print(number1 | number2);
	printf("= number1 | number2 = %d\n", number1 | number2);

	printf("\n");
	binary_print(number1);
	printf("= number1 = %d\n", number1);
	binary_print(~number1);
	printf("= ~number1 = %d\n", ~number1);
	
	printf("Enter shift number: ");
	if (scanf("%d", &shift_number))
	{
		
		binary_print(number2);
		printf("= number2 = %d\n", number2);
		binary_print(number2 >> shift_number);
		printf("= number2 >> %d = %d\n", shift_number, number2 >> shift_number);
		binary_print(number2 << shift_number);
		printf("= number2 << %d = %d\n", shift_number, number2 << shift_number);
		
	}  
	return 0;
}