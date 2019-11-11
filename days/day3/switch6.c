main()

{

char y;

clrscr();

printf(“Enter the code”);

scanf(“%c”,&y);

switch (y)

{

  case ‘N’ : printf(“North Direction”);

                   break;

  case ‘S’ : printf(“South Direction”);

                   break;

  case ‘E’ : printf(“East Direction”);

                   break;

  default : printf(“West Direction”);

                   break;

}
