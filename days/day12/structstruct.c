struct date
{
	int day;
	int month;
	int year;
};

struct student
{
	int id_no;
	char name[20];
	struct date drec;
};

main()
{
	struct student stud={20,"satish",{1,12,1980}};
	printf("%d %s Day:%d Mon:%d Yr:%d\n",stud.id_no,stud.name,stud.drec.day,stud.drec.month,stud.drec.year);
}
	
	


