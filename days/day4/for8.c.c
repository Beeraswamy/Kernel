#include<stdio.h>
int main()
{
 int i,j;
 for(i=0;i<2;i++)
 {
  printf("%d\n",i);
  for(j=0;j<2;j++)
  {
   printf("%d\n",j);
   if(1)
   continue;
    printf("%d\n",i*j);
  }
 printf("%d\n",i+j);
 }
}
