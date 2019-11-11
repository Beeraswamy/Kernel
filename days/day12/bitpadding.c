/*struct data
{
	char a;
	int b;
	char c;
	int d;
};*/ //16Bytes
/*
struct data
{
	char a;
	char b;
	int c;
	int d;
};*/ //12Bytes

struct data
{
	char a;
	short b;
	char c;
	short d;
}; //8Bytes
/*
struct data
{
	char a;
	char b;
	short c;
	short d;
}; *///6Bytes

main()
{
	struct data d;
	printf("%d\n",sizeof(struct data));
}	
