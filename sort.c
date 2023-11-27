#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 20000000
#define MAX_ARRAY_VALUE 10000
#define RAND_MULTIPLIER 1e-2
#define MAX_NUM_ITERATIONS 1000000
#define DUMMY_SORT_CYCLE 1000
#define MAX_PRINT_LEN 10

void two_arrays_generate(double * arr1, double *arr2, int len);
void dummy_sort(double * arr, int len);
int sort_check(double * arr, int len);
void print_arr(double * arr, int len, const char * str);
int cmp(const void * a, const void * b);
void quick_sort(double * arr, int len);

void print_arr(double * arr, int len, const char * str)
{
	printf("\n%s:\n", str);
	for (int i=0; i < len; i++) printf("arr[%d] = %.2lf\n", i, arr[i]);
	printf("\n");
}

void two_arrays_generate(double * arr1, double *arr2, int len)
{
	double value;
	srand(time(NULL));                            
	for (int i = 0; i < len; i++)
	{
		value = ((rand() % (2 * MAX_ARRAY_VALUE + 1)) - MAX_ARRAY_VALUE) * RAND_MULTIPLIER;
		//value = rand();
		arr1[i] = value;
		arr2[i] = value;
	}
}

int sort_check(double * arr, int len)
{
	for (int i=0; i < len - 1; i++)
	{
		if (arr[i] > arr[i + 1]) return 0;
	}
	return 1;
}

void dummy_sort(double * arr, int len)
{
	int iter_num = 0, timer = 0, cycle_num, index1, index2; double temp;
	
	if (len <= MAX_PRINT_LEN) print_arr(arr, len, "Array before sorting"); else print_arr(arr, MAX_PRINT_LEN, "Array before sorting");
	timer -= clock();
	while (iter_num < MAX_NUM_ITERATIONS && !sort_check(arr, len))
	{
		iter_num++;
		for (cycle_num = 0; cycle_num < DUMMY_SORT_CYCLE; cycle_num++)
		{
			index1 = rand() % len;
			index2 = rand() % len;
			if ((index1 < index2 && arr[index1] > arr[index2]) || (index1 > index2 && arr[index1] < arr[index2]))
			{
				temp = arr[index1];
				arr[index1] = arr[index2];
				arr[index2] = temp;	
			}
		}
	}
	timer += clock();
	if (len <= MAX_PRINT_LEN) print_arr(arr, len, "Array after sorting"); else print_arr(arr, MAX_PRINT_LEN, "Array after sorting");
	if (sort_check(arr, len))
	{
		printf("\nArray is sorted\nRequired time for sorting %d elements is %lf seconds\n", len, (double)timer / CLOCKS_PER_SEC);
	}
	else printf("Array isn't sorted");
}

int cmp(const void * a, const void * b)
{ 
	if (*(const double *)a > *(const double *)b) return 1; 
	else if (*(const double *)a < *(const double *)b) return -1;
	return 0;
}

void quick_sort(double * arr, int len)
{
        int timer = 0;
	if (len <= MAX_PRINT_LEN) print_arr(arr, len, "Array before sorting"); else print_arr(arr, MAX_PRINT_LEN, "Array before sorting");
	timer -= clock();
	qsort(arr, len, sizeof(double), cmp);
	timer += clock();
	if (len <= MAX_PRINT_LEN) print_arr(arr, len, "Array after sorting"); else print_arr(arr, MAX_PRINT_LEN, "Array after sorting");
	if (sort_check(arr, len))
	{
		printf("\nArray is sorted\nRequired time for sorting %d elements is %lf seconds\n", len, (double)timer / CLOCKS_PER_SEC);
	}
	else printf("Array isn't sorted");
}

int main(void)
{
        int len;
	double *arr1 = NULL, *arr2 = NULL;
        printf("Enter lenght of array: ");
	scanf("%d", &len);
	if (len < 1 || len > MAX_LEN) 
	{
		printf("Incorrent array length");
		return -1;
	}
	
	arr1 = (double *)malloc(len * sizeof(double));
	arr2 = (double *)malloc(len * sizeof(double));
	two_arrays_generate(arr1, arr2, len);
	dummy_sort(arr1, len);
	quick_sort(arr2, len);
	free(arr1);
	free(arr2);
	return 0;
}

