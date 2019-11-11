main()
{
	char str[]="national institute of micro small and medium enterprise";
	char *ptr;
	int i;
	printf("\nPrinting string using percentile s\n");	
	printf("%s",str);
	printf("\nPrinting string using percentile c\n");
	for(i=0;str[i]!='\0';i++)
		printf("%c",str[i]);
	printf("\nPrinting String using pointers:\n");
	ptr = str;
	for(i=0;*ptr;i++)
	{
		printf("%c",*ptr);
		ptr++;
	}
}
