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
	int a[10] = {0,3,4,1,5,8,7,9,6,2};
	insertsort(a, 10);
	printarray(a, 10);
}