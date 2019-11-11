main()
{
	int a,*b,**c,***d,****e;
	a=10;
	b=&a;
	c=&b;
	d=&c;
	e=&d;
	
	printf("%d %d %d %d %d\n",a,*b,**c,***d,****e);
}
