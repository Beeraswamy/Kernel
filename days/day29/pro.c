#include<stdio.h>
int main()
{
int id;
id=fork();
if(id==0)
{
printf("this is child\n");
}
else
{
id=fork();
printf("this is parent\n");
}
}
