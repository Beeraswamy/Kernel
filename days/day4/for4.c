#include<stdio.h>
int main()
{
 int i,j;
 for(i=0,j=0;i<0,j<7;i++,j++)
 {
  printf("%d\n",i);
  printf("%d\n",j);
  if(1)
  continue;
  printf("%d\n",i+j);
 }
}
