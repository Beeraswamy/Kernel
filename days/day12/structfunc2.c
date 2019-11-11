#include <stdio.h>
#include <string.h>
struct employee
{
	int emp_id;
	char name[25];
	float salary;
};

void main()
{
	static struct employee empl={12,"sadanand",7500.00};
	
	/*sending entire employee structure*/
	display(&empl);
	printf("%d %s %f\n",empl.emp_id,empl.name,empl.salary);
}

display(struct employee *emp)
{
	printf("%d %s %f\n",emp->emp_id,emp->name,emp->salary);
	emp->emp_id = 20;
	strcpy(emp->name,"satish");
	emp->salary=8000.00;
	printf("%d %s %f\n",emp->emp_id,emp->name,emp->salary);
	
}
