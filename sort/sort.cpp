#include "sort.h"

void swap_hlp(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void movebackbypos(int a[], int k, int pos)
{
	int i;
	for (i = k; i >= pos; --i)
	{
		a[i] = a[i-1];
	}
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
			return;
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
	int i,j;
	int k = 1;
	int temp = a[len - 1];

	for (i = 0; i < len - 1; ++i)
	{
		bool bflag = false;
		for (j = 0; j < k; ++j)
		{
			if (temp < a[j])
			{
				movebackbypos(a, len - 1, j);
				a[j] = temp;
				bflag = true;
				break;
			}
		}
		if (!bflag)
		{
			movebackbypos(a, len - 1, j);
			a[j] = temp;
		}
		temp = a[len - 1];
		++k;
	}	
}