#if 0
struct data{
	unsigned rollno:4;
	unsigned marks:4;
}; //4
#endif
#if 0
struct data{
	unsigned char rollno:4;
	unsigned char marks:5;
}
#endif
#if 0
struct data{
	unsigned short rollno:4;
	unsigned short marks: 4;
	//unsigned short a:7;
	//unsigned short b:7;
}
#endif
#if 1
struct data{
	unsigned int rollno:4;
	unsigned int marks:4;
}
#endif
main()
{
	struct data d={15,25};
	printf("0x%x 0x%x %d\n",d.rollno,d.marks,sizeof(struct data));
}
