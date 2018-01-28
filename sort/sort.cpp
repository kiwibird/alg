#include "sort.h"

void swap_hlp(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void bubblesort(int a[], int len)
{
	int i,j;
	for (i = 0; i < len; ++i)
	{
		bool bFinish = true;
		for (j = 0; j < len - 1 - i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap_hlp(&a[j], &a[j + 1]);
				bFinish = false;
			}
		}
		if (bFinish)
		{
			break;
		}
	}
}

void selectsort(int a[], int len)
{
	int i,j;
	for (i = 0; i < len; ++i)
	{
		for (j = i + 1; j < len; ++j)
		{
			if (a[i] > a[j])
			{
				swap_hlp(&a[i], &a[j]);
			}
		}
	}
}

void insertsort(int a[], int len)
{
	int i,j,temp;
	for (i = 1; i < len; ++i)
	{
		temp = a[i];
		for (j = i; j > 0 && a[j - 1] > temp; --j)
		{
			a[j] = a[j-1];
		}
		a[j] = temp;
	}
}