// Implementation of bubble sort

#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

void display(int arr[])
{
	int i;
	printf("\nElements in the array after each step.. : ");
	for(i=0; i<=4; i++)  
	{
	  	printf(" %d", arr[i]);
	}
}
void bubblesort(int arr[], int n)
{
	int i, j, temp;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				display(arr);
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
/*
void bubblesort(int arr[], int n)
{
	int i, j, temp;

	for(i = 0; i < n-1; i++)
	{
		for(j = n-1; j > i; --j)
		{
			if(arr[j] < arr[j-1])
			{
				display(arr);
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
		}
	}
}
*/
int main()
{
	int i,n = 5;
	int arr[] = {34, 89, 67, 20, 43} ;
	//clrscr();
	printf("\nElements in the array before sorting :");
	for( i = 0; i <= 4; i++)
	{
	  	printf("%d ",arr[i]);
	}
	printf("\n");

	bubblesort(arr, n);
	printf("\n\nElements in the array after sorting : ");
	for(i = 0; i <= 4; i++)
	{
	  	printf(" %d",arr[i]);
	}

	printf("\n\n");
	return 0;
	//getch();
}


