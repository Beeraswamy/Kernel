struct data{
	unsigned rollno:4;
	unsigned marks: 5;
};

main()
{
	//struct data d={25,25};
	struct data d={15,25};
	printf("%d %d\n",d.rollno,d.marks);
}
