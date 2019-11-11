#include <stdio.h>

main()
{
	int array[10] = {11,22,33,44,55,66,77,88,99,117};
	int first=0, last=10, middle, found, key;
	found = 0;
	
	printf("Enter the element to search\n");
	scanf("%d",&key);	
	while((first <= last) && !found)
	{
		middle = (last+first)/2;
		printf("last %d\n",last);
		printf("middle: %d\n", middle);
		if(array[middle]==key)
			found = 1;
		else if(array[middle]<key)
			first = middle + 1;
		else 
			last = middle -1;
	}
	if(found)
	{
		printf("Element found at %d\n",array[middle]);
	}
	else
		printf("Element not found\n");
	
}
		
