//program to find the val starting from abit position
#include<stdio.h>


main()
{
  unsigned int num;
  unsigned int bitpos;
  unsigned int temp;
  printf("Enter num in hex\n");
  scanf("%x",&num);
  printf("Enter bit position\n");
  scanf("%d",&bitpos);
  temp=(num>>bitpos)&1;
  printf("Bitpos value in the number: %d\n",temp);

}
