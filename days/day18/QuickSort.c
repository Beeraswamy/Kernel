//Implementation of Quick Sort

#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

#define N 8

int partition(int arr[], int low, int high) 
 {
	int i, pivotloc = low, pivotkey, temp;

	temp=arr[low];		//Swaping of pivotloc with low
	arr[low]= arr[(low+high)/2];
	arr[(low+high)/2]=temp;
	pivotkey = arr[low];

	for(i=low+1; i<=high; i++)  {
		if(arr[i] < pivotkey)  {
	  	//swap(++pivotloc, i, arr);
	  		++pivotloc;
			temp = arr[i];
			arr[i] = arr[pivotloc];
			arr[pivotloc] = temp;
		}
	}

	//swap(low,pivotloc,arr);
	temp = arr[low];
	arr[low] = arr[pivotloc];
	arr[pivotloc] = temp;
	
	return pivotloc;
}

void quicksort(int arr[], int low, int high)
{
	int pivotloc;
	if(low < high)  {
		pivotloc = partition(arr, low, high);
		quicksort(arr, low, pivotloc-1);
		quicksort(arr, pivotloc+1, high);
	}
}


int main()  {
	int i;
	int arr[]= {23, 89, 4, 90, 70, 60, 50, 65};
	//clrscr();

	printf("\nUnsorted elements are ::");
	for(i=0; i<N; i++)  {
		printf( " %d ", arr[i]);
	}

	quicksort(arr, 0, N-1);

	printf("\nSorted elements are ::");
	for(i=0; i<N; i++)  {
		printf( " %d ", arr[i]);
	}
	
	printf("\n\n");
	return 0;
	//getch();
}
