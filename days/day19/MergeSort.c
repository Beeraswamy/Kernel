//Merge Sort

#include <stdio.h>
//#include <conio.h>

void merge(int array[], int temp[], int low, int mid, int high)
{
	int j = 0;

	int low1 = low;
	int high1 = mid-1;
	int n = high-low1 +1;

	while(low <= high1 && mid <= high)
		if(array[low] < array[mid] )
			temp[j++] = array[low++];
		else
			temp[j++] = array[mid++];

	while(low <= high1)
		temp[j++] = array[low++];

	while(mid <= high)
		temp[j++] = array[mid++];

	for(j=0; j<n; j++)
		array[low1+j] = temp[j];
}

void mergeSort(int a[], int temp[], int low, int high)
{
	int mid;

	printf("low %d high %d\n",low,high);
	if (high > low)
	{
		mid = (high + low) / 2;
		mergeSort(a, temp, low, mid);
		mergeSort(a, temp, mid+1, high);

		merge(a, temp, low, mid+1, high);
	}
}

void display(int *a, int p)
{
	int k;
	printf("\nElements after Merge Sort.......");
	for(k=0; k<p; k++)
	  printf("%d ", a[k]);
}

void main()
{
	int temp[50], a[50]={4,3,7,1,8,12,2,5};
	int i, p = 8, len;
	

/*
	printf("\nEnter the current length::");
	scanf("%d", &len);

	printf("\nEnter the elements for Merge Sort::");
	for(i = 0; i<len; i++)
	{
		p++;
		scanf("%d", &a[i]);
	}
*/
	mergeSort(a, temp, 0, p - 1);
	display(a, p);

	//getch();
}

