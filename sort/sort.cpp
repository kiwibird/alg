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

/* a 被划分为两个有序部分，合并 */
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
	/* 递归出口条件是只有一个元素 */
	if (first < last)
	{
		int mid = first + (last - first)/2;
		mergesort_hlp(a, first, mid, temp);
		mergesort_hlp(a, mid + 1, last, temp);
		mergeorderarray(a, first, mid, last, temp);
	}
}

void mergesort(int a[], int len)
{
	int *ptemp = new int[len]; /* 弱点：空间复杂度比较高 */
	mergesort_hlp(a, 0, len - 1, ptemp);
	delete [] ptemp;
}

void heapify(int a[], int len, int pos)
{
	int r,c;
	for (r = pos; 2*r + 1 <= len - 1; r = c)
	{
		c = 2*r + 1;
		if (c + 1 <= len - 1 && a[c] < a[c + 1])
		{
			c += 1;
		}
		if (a[r] > a[c])
		{
			break;
		}
		swap_hlp(&a[r], &a[c]);
	}
}

void heapsort(int a[], int len)
{
	int i = len/2 - 1;
	for (; i >= 0; --i)
	{
    	heapify(a, len, i);
	}
	for (i = len - 1; i > 0; --i)
	{
		swap_hlp(&a[0], &a[i]);
		heapify(a, i, 0);
	}	
}