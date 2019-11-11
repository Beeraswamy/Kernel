// Implementetion of Insertion Sort

#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

void insertsort(int arr[], int n)
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

	insertsort(arr, n);
	printf("\nElements in the array after sorting :");
	for(i = 0; i <= 4; i++)
	{
	  	printf(" %d", arr[i]);
	}
	
	printf("\n\n");
	//return 0;
	//getch();
}

