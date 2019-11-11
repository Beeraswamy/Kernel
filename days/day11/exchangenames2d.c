main()
{
	char name[][10]={"january",
				"february",
				"March",
				"April",
				"May",
				"June",
				"July"};
	int i;
	char t;	
	printf("Original: %s %s\n",&name[0][0],&name[1][0]);
	
	for(i=0;i<=9;i++)
	{
		t=name[0][i];
		name[0][i]=name[1][i];
		name[1][i]=t;
	}
	printf("New: %s %s\n",&name[0][0],&name[1][0]);
}
				
				
