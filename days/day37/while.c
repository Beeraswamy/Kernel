main()
{
	char *ch="string";
	printf("%s\n",ch);
	puts(ch);
	//ch[2]='a';
	display(ch);
}
display(char *ch)
{
	ch[2]='a';
}	
