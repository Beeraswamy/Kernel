/*
i want that if matrix is
1234
4567
8901
2345
then i want to print lower triangle
that is
1
45
890
2345
and upper triangle
1234
567
01
5 


If you are just starting, might be easiest to use a 2D array; declare an mxn array of integers (or whatever data type you need to hold, where m = number of rows, n = number of columns). If you are dealing strictly with square matrices, then m = n.

For the upper triangular one:
Simply loop through and print out the first n entries of row 1, (n-1) entries of row 2, (n-2) entries of row 3, ... , (n - (m-1)) = (n - m + 1) entries of row m.

If you are a little heavier on the math side, you could also try to implement it using a 1D array, (after all, a rectangular 2D array is really just a 1D array in disguise).

Ummm, the lower triangular one is very similar, if you can see the pattern then you should be on track to solving it now.. 
*/


#include<stdio.h>


int a[10][10]={	{0,1,2,3,4,5,6,7,8,9},
		{0,1,2,3,4,5,6,7,8,9},
		{0,1,2,3,4,5,6,7,8,9},
		{0,1,2,3,4,5,6,7,8,9},
		{0,1,2,3,4,5,6,7,8,9},
		{0,1,2,3,4,5,6,7,8,9},
		{0,1,2,3,4,5,6,7,8,9},
		{0,1,2,3,4,5,6,7,8,9},
		{0,1,2,3,4,5,6,7,8,9},
		{0,1,2,3,4,5,6,7,8,9}};
	

main()
{
	int i,j,r=10,c=10;//,a[10][10];
	/*
	printf("Enter the r and c value:");
	scanf("%d%d",&r,&c);
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}*/
	printf("given matrix");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<r;i++)
	{
		printf("\n");
		
		for(j=0;j<=i;j 
		{
			if(i>=j)
			{
				printf("(%d %d) %d ",i,j,a[i][j]);
				//printf("%d ",a[i][j]);
			}
		}
	}
	printf("\n\n");
	for(i=0;i<r;i++)
	{
		printf("\n");
		for(j=0;j<c;j++)
		{
			if(j>=i)
			{
				printf("%d ",a[i][j]);
			}
			else
			{
				printf("(%d %d)  ",i,j);
			}
		 printf("\n");
		}
	}
}




