/*(f)Write a program to produce the following output:
       A B C D E F G F E D C B A
       A B C D E F   F E D C B A
       A B C D E       E D C B A
       A B C D           D C B A
       A B C               C B A
       A B                   B A
       A                       A  
       */

#include <stdio.h>

int main()
{
	int i,j,k,count1,count2=0;//count1 and count 2 for spaces
   
	for(i=104;i>=97;i--)
  	{
       		for(j=97;j<=104;j++)
       		{
       	 		if(i>=j)	/*In 1st loop print character from 97-104 
                  			In 2nd loop print character from 97-103 
                  			{i(103)>=j(104) fails } and so on.*/
        		printf("%c ",j);//prints characters
       		}
       		for(count1=0;count1<count2;count1++)
                /*for managing space in 1st line we don't need space so 
		count1(0<count2(0) fails and spaces don't get  printed*/                                                 
       		{
         		if(i==103)  	// in 2nd line we need 1 space for each loop.
                     			// so i==103 condition of 2nd line
                        	printf(" ");
               		if(i!=103)//2 spaces are needed. and spaces
                  		// increases by 2 for each line after 2nd line
               			printf("  ");
       		}
       		for(k=104;k>=97;k--)
       		{
         		if(k<=i&&k!=104)
         			printf("%c ",k);
       		}
       		if(i==103)   //for managing spaces 
       			count2=count2+1;
		else         //for managing spaces
			count2=count2+2;
       
		printf("\n");  //new line for each i.
	}

  //getch();
  return 0;
}  

/*
           
*/
