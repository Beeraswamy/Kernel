#include<stdio.h>
main()

{

int y,r1,r2;

printf("Enter a year");

scanf("%d",&y);

r1=y%4;

if (r1 == 0)

{

         r2=y%100;


         if(r2 == 0)

                printf("The given year is not a leap year");

         else

                printf("The given year is a leap year");

}

else

printf("The given year is not a leap year");

} 
