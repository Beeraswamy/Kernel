#include <stdio.h>

#define PI 3.14159
#define CIRCLE_AREA(x) PI*(x)*(x)

main()
{
	float radius,area;
//	int c=2;
	printf("Enter Radius of the circle\n")
	scanf("%f",&radius);
	area = CIRCLE_AREA();
	printf("Area of the Circle with %f radius is %f\n",radius,area);
}	
