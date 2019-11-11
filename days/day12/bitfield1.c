//Controlling the alignment of bits.

#if 
struct str
{
	unsigned int a:5;
	unsigned int b:5;
	unsigned int : 6;
	unsigned int c:5;
}; //4Bytes
#endif

#if 0
struct str
{
	unsigned int a:5;
	unsigned int b:5;
	//unsigned int : 0;
	unsigned int c:5;
}; //4Bytes
#endif

#if 0
struct str
{
	unsigned short a:5;
	unsigned short b:5;
	unsigned short : 0;
	unsigned short c:5;
}; //4Bytes
#endif
main()
{
 struct str str1={1,2,3};
	printf("%d %d %d\n",str1.a,str1.b,str1.c);
	printf("%d\n",sizeof(struct str));
	//printf("0x%x 0x%x 0x%x\n",&str1.a,&str1.b,&str1.c);
}
