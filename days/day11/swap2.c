main()
{
	int a=10;
	int b=20;
	
	swapr(&a,&b);
	
	printf("a=%d\n",a);
	printf("b=%d\n",b);
}

swapr(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}

