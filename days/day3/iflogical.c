#include<stdio.h>
main()
{
	int m1,m2,m3,m4,m5,per;
	printf("Enter marks in five subjects\n");
	scanf("%d %d %d %d %d\n",&m1,&m2,&m3,&m4,&m5);
	per = (m1+m2+m3+m4+m5)/5;
	if(per >= 60)
		printf("First Division\n");
	if((per >= 50) && (per < 60))
		printf("Second Division\n");
	if((per >= 40) && (per < 50))
		printf("Third Division\n");
	if(per < 40)
		printf("Fail\n");
}
/* All the three problems mentioned in ifrelational.c can be eliminated by usage of 'Logical Operators'
	&& opeators can be used to combine two conditions.If one of the conditions evaluate to be false then the whole thing is treated as false.
	Two advantages can be cited using the above program	
	a) The matching (or I say mismatching) of the if's with their corresponding else's get avaoided, since there are no else;s in this program.
	b) In the earlier program the statements wnen on creeping to the right. This effect becomes more pronounces as the number of conditions increases. This would make th task of mathing the ifs with their corresponding elses and matching of opening and closing breaces that much more difficult.*/
