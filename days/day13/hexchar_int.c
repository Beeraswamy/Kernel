#include <stdio.h>
#include <string.h>

main()
{

	char a[10]="0AB";
	int len,i=0,j=0,k=0;
	printf("Enter the hexadecimal numbers in lower case\n");
	scanf("%s",a);
		
	len = strlen(a);
	printf("%d",len);
	len--;	
	while(len>=0)
	{
		if(a[len] >= 'a' && a[len] <= 'f')
		{
			j= a[len]-87; //value range 97-102
		}
		if(a[len] >= '0' && a[len] <= '9')
		{
			j= a[len] - 48;
		}
		//printf("j %d",j);		
		k=k+(j*pow(16,i));	
		i++;
		len--;
	}
	printf("Hex string equavalent value : %d\n",k);
}
