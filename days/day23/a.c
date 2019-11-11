#include<stdio.h>

struct stud
{
	char name[20];
	int no;	
	float marks;
}

main()
{
struct stud s1[3]={
		  	{"l",10,90.00},
			{"m",11,91.00},
			{"n",12,92.00},

		  };
struct stud s2;
s2=s1;
printf("%d\n",sizeof(s1));
printf("%d\n",sizeof(struct stud));
}
