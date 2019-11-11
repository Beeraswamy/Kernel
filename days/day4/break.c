#include <stdio.h>
int main() 
{
	char c;
	for(;;) 
	{
      		printf( "Press any key, Q to quit: " );
		// Convert to character value
		scanf("%c", &c);
      		if (c == 'Q')
          		break;
   	}
} // Loop exits only when 'Q' is pressed

