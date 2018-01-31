#include "../utils/utils.h"
#include "../sort/sort.h"

TEST(bubblesort)
{
	int a[10] = {0,3,5,1,4,8,7,9,6,2};
	bubblesort(a, 10);
	printarray(a, 10);
}

TEST(selectsort)
{
	int a[10] = {0,3,4,1,5,8,7,9,6,2};
	selectsort(a, 10);
	printarray(a, 10);
}

TEST(insertsort)
{
	int a[10] = {0,9,7,1,5,8,4,3,6,2};
	insertsort(a, 10);
	printarray(a, 10);
}

TEST(mergesort)
{
	int a[10] = {0,9,7,1,5,8,4,3,6,2};
	mergesort(a, 10);
	printarray(a, 10);
}

TEST(heapsort)
{
	int a[10] = {0,9,4,1,5,8,7,3,6,2};
	heapsort(a, 10);
	printarray(a, 10);
}