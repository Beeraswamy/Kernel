char strA[80] = "A string to be used for demonstrations";
char strB[80];

int main(void)
{
	puts(strA);
	mystrcpy(strA,strB);	
	puts("After using mystrcpy function\n");	
	puts(strB);
	
		
	return 0;
}
		
mystrcpy(char *pA, char *pB)
{
	while(*pA != '\0')
	{
		*pB = *pA;
		pB++;
		pA++;
	}
*pB='\0';
}
