#include <stdio.h>
#include <string.h>
struct employee
{
	int emp_id;
	char name[25];
	char department[10];
	float salary;
};
struct employee display(struct employee emp);
void main()
{
	static struct employee empl={12,"sadanand","computer",7500.00};
	
	/*sending entire employee structure*/
	empl=display(empl);
	printf("%d %s %s %f\n",empl.emp_id,empl.name,empl.department,empl.salary);
}

struct employee display(struct employee emp)
{
	printf("%d %s %s %f\n",emp.emp_id,emp.name,emp.department,emp.salary);
	emp.emp_id = 20;
	strcpy(emp.name,"satish");
	strcpy(emp.department,"mangement");
	emp.salary=8000.00;
	printf("%d %s %s %f\n",emp.emp_id,emp.name,emp.department,emp.salary);
	return emp;
	
}
