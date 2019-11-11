main()
{
	char *name[]={"january",
				"february",
				"March",
				"April",
				"May",
				"June",
				"July"};
	char *temp;
	
	printf("Original %s %s\n",name[0],name[1]);
	temp=name[0];
	name[0]=name[1];
	name[1]=temp;
	printf("Value %s %s\n",name[0],name[1]);
}
		
