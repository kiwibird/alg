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

void mergeorderarray(int a[], int first, int mid, int last, int temp[])
{
	int i = first;
	int j = mid + 1;
	int k = 0;
	
	while(i <= mid && j <= last)
	{
		if (a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	while (j <= last)
	{
		temp[k++] = a[j++];
	}
	for (i = 0; i < k; ++i)
	{
		a[i + first] = temp[i];
	}
}

void mergesort_hlp(int a[], int first, int last, int temp[])
{
	if (last - first < 2)
	{
		return;
	}

	int mid = first + (last - first)/2;
	mergesort_hlp(a, first, mid, temp);
	mergesort_hlp(a, mid + 1, last, temp);
	mergeorderarray(a, first, mid, last, temp);
}

void mergesort(int a[], int len)
{
	int *ptemp = new int[len];
	mergesort_hlp(a, 0, len - 1, ptemp);
	delete [] ptemp;
}