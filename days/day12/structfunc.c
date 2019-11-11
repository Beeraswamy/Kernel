#include <stdio.h>
struct emp
{
	int emp_id;
	char name[25];
	char dempartment[10];
	float salary;
};

void main()
{
	struct emp emp1={125,"sampath","operator",7500.00};
	
	/*pass only emp_id and name to display function*/
	display(emp1.emp_id,emp1.name);
	printf("main: %d %s\n",emp1.emp_id,emp1.name);	
}

display(int e_no,char e_name[])
{
	printf("%d %s\n",e_no,e_name);
	e_no=200;
	
	e_name[0]='A';	
	e_name[1]='B';	
	printf("%d %s\n",e_no,e_name);
}
	


