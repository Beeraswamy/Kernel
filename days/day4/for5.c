#include<stdiro.h>
int main()
{
 int i,j,a=2,b=1,c;
 c=add(a,b);
 for(i=0;i<2;i++)
 {
  printf("%d\n",i);
  for(j=0;j<2; )
   {
    printf("%d\n",j);
    if(1)
    break;
    printf("%d\n",i*j);
   }
  printf("%d\n",i+j);
 }
}
add(int a,int b)
{
int c;
c=a+b;
printf("c=%d",c);
}
