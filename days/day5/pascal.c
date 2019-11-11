#include <stdio.h>

int factorial( int n )
{
     if ( n <= 1 )
          return 1;
     else
          return n * factorial( n - 1 );
}

int main()
{
     int n;
     int r;
     int value = 0;

     do {
               n = 0;
               r = 0;
               printf( "Input the row#: " );
               scanf( "%d", &n );
               printf( "Input the value's position within the row: " );
               scanf( "%d", &r );

               if ( r > n )
                    printf( "That is not a valid position within Pascal's Triangle\n" );
     } while ( r > n );

     value = factorial( n ) / (factorial( r ) * factorial( n - r ));

     printf( "The value at row-%d, position-%d is %d\n", n, r, value );

     return 0;
}

