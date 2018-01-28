#include "../utils/utils.h"
#include "../sort/sort.h"

TEST(selectsort)
{
	int a[10] = {0,3,4,1,5,8,7,9,6,2};
	selectsort(a, 10);
	printarray(a, 10);
}