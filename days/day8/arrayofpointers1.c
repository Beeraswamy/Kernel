#include <stdio.h>

int main()
{
	//int *arr[4]={1,2,3,4}; /*array of integer pointers*/	
	int i=31,j=5,k=19,l=71,m;
	int *arr[4]={&i,&j,&k,&l};
	/*arr[0]=&i;
	 arr[1]=&j;
	 arr[2]=&k;
          arr[3]=&l;*/
	for(m=0;m<4;m++)
		printf("\n%d 0x%x",*(arr[m]),arr[m]);
}
	
