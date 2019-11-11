main()
{
	//int y=20;		
	int x=10;
		
	int *p=&x;
		
	printf("0x%x\n",p);
	printf("%d\n ",*p++);
	printf("%d 0x%x\n ",*p,p);	
	
	
	//printf("0x%x\n ",++*p);
	//printf("0x%x 0x%x\n ",*p,p);
}
