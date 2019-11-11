main()
{
	int num,start,final=0,digit;
	scanf("%d",&num);
	start = num;	
	while(num>0)
	{
		digit=num%10;
		num = num/10;
		final = (final*10)+digit;
	}
	if(start == final)
		printf("the number is equal\n");
	else
		printf("the number is not equal\n");
}
