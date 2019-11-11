// Implementetion of selection Sort

#include<stdio.h>
#include<stdlib.h>
/*
void selectionsort(int arr[], int n)
{	int i, temp, j;
	for(i=1; i<n; i++)
	{
		temp=arr[i];
		for(j=i; j>0 && arr[j-1] > temp; j--)
		{
			arr[j]=arr[j-1];
			arr[j-1]=temp;
		}
	}
}
*/

void selectionsort(int arr[],int n)
{
	int x,y,index_of_min;

	for(x=0; x<n; x++)
	{
		int index_of_min = x;
		for(y=x; y<n; y++)
		{
			if(arr[index_of_min]>arr[y])
			{
				index_of_min = y;
			}
		}
		int temp = arr[x];
		arr[x] = arr[index_of_min];
		arr[index_of_min] = temp;
	}
}

int main()
{
	int i, n = 5;
	int arr[] = {89, 56, 90, 45, 23} ;
	//clrscr();
	printf("\nElements in the array after before sorting :");
	for(i = 0; i <= 4; i++)
	{
	  	printf(" %d", arr[i]);
	}

	selectionsort(arr, n);
	printf("\nElements in the array after sorting :");
	for(i = 0; i <= 4; i++)
	{
	  	printf(" %d", arr[i]);
	}
	
	printf("\n\n");
	return 0;
	//getch();
}

