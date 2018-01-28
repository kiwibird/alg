#include <stdlib.h>
#include <stdio.h>
#include "utils\utils.h"
#include "sort\sort.h"

int main()
{
	int a[10] = {0,3,4,1,5,8,7,9,6,2};
	selectsort(a, 10);
	printarray(a, 10);
	
	printf("hello world first test!\n");
	return 0;
}