main()
{
	void *ptr;
	int x=20;
	//char *cptr;	
	ptr = &x;
	printf("%d",*(int*)ptr);
}
