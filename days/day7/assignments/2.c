//W.A.P. to print larger and smaller elements of an array

int main()
{
	int a[20],min,max;
	int n;
	printf("enter the num of elements\t:");
	scanf("%d",&n);

	printf("enter the elements\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(i==0)
		{
			min=max=a[i];
		}
		if(a[i]<min)
			min=a[i];
		else if(a[i]>max)
			max=a[i];
	}
	printf("Biggest element is %d and Smallest element 
is %d ",max,min);
}

#if 0 	

#include<stdio.h>
int main()
{
 int a[]= {4,3,6,7};
 int l.n = 0;
 int s.n = 9;
 int i=0;
 while(a[i] != '\0') 
 {
   if(a[i]>= l.n)
   l.n = a[i];
   else if(a[i]<=s.n)
   s.n = a[i]
   i++;
 }
  printf("%d %d",s.n,l.n) ;

}
#endif

#if 0
#include<stdio.h>
#include<stdlib.h>

int main() {
  int n, *arr, i, min, max, tmin, tmax, start=2;
  printf("How many elements:");
  scanf("%d", &n);
  arr = (int *) malloc(sizeof(int) * n);

  printf("Enter %d Elements:", n);
  for (i=0; i<n; i++)
          scanf("%d", &arr[i]);

  if(arr[0] < arr[1]) { // 1 comparison
    min = arr[0];
    max = arr[1];
  } else {
    min = arr[1];
    max = arr[0];
  }

  tmin = min;
  tmax = max;

  if(n%2) {
        if(arr[2] < min)
                min = arr[2];
        if(arr[2] > max)
                max = arr[2];
        start = 3;
  }


  for(i=start; i < n; i+=2)                             //
(n-2)/2 elements
     {
        if(arr[i] < arr[i+1]) {                 // 1 comparison
            min = arr[i];
            max = arr[i+1];
        } else {
            min = arr[i+1];
            max = arr[i];
        }

        if(tmin < min)                          // +1
                min = tmin;
        if(tmax > max)                          // +1 = 3
                max = tmax;                     // Total
comparisons = 3(n-2)/2
     }

  printf("Min: %d \nMax: %d\n", min, max);

}



Note: This gives a slightly better running time.

#endif

