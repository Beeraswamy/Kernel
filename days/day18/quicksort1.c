#include <stdio.h>

//int array[25]={23, 89, 4, 90, 70, 60, 50, 65};
int array[25]={38,8,16,6,79,57,24,56,2,58};
main()
{
	int num=10, i = 0;
	
	printf( "\nThe elements Before sorting are: " );
	//for(i=0; i < num; i++)
	//	printf("%d ", array[i]);
	//printf("\n");	
	quicksort(0, num -1);
for(i=0; i < num; i++)
		printf("%d ", array[i]);
	printf("\n");	
}
quicksort(int low, int high)
{
	int pivotpos;	
	printf("QS low %d high %d\n",low,high);	
	if( low < high )
	{
		printf("low %d high %d",low,high);
		pivotpos = partition(low, high + 1);
		printf("pivotpos %d\n\n",pivotpos);		
		quicksort(low, pivotpos - 1);
		quicksort(pivotpos + 1, high);
	}
}
partition(int low, int high)
{
	int pivot = array[low],temp;
	int i=0,num=10;
	printf("\npivot %d:   ",pivot);
	int up = low, down = high;
	for(i=0; i < num; i++)
		printf("%d ", array[i]);	
	do
	{
		do
			up = up + 1;
		while(array[up] < pivot && up < num-1);
		
		do
			down = down - 1;
		while(array[down] > pivot && down > 0);
		if(up < down)
{			
temp = array[down];
	array[down] = array[up];
	array[up] = temp;
}
	} while(up < down);
	array[low] = array[down];
	array[down] = pivot;
	printf("\nModified to ");
		return down;
}
	

