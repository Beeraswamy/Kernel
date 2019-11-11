main()
{
	int m1,m2,m3,m4,m5,per;
	printf("Enter marks in five subjects\n");
	scanf("%d %d %d %d %d",&m1,&m2,&m3,&m4,&m5);
	per = (m1+m2+m3+m4+m5)/5;
	//scanf("%d",&per);	
	if(per >= 60)
		printf("First Division\n");
	else
	{
		if(per >= 50)
			printf("Second Division\n");
		else
		{
			if(per >= 40)
				printf("Third Division\n");
			else
				printf("Fail\n");
		}
	}
}

/*Observe the program uses nested if-elses. This leads to three disadvantages
	a) As the number of conditions go on increasing the level of indentations also goes on increasing. As a result the whole program creeps to the right.
	b) Care needs to be exercised to match the corresponding if's and else's.
	c) Care needs to be exercised to match the coresponding pair of braces.*/
