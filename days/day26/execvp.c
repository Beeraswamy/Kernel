int main()
{
	char *args[4];
	printf("I am going to exec an 'ls' program in current process\n");
	
	args[0]="cp";
	args[1]="balu.c";
	args[2]="swamy.c";
	args[3]=0;
	execvp("cp",args);
	printf("I have run an exec program\n");
	printf("I have run an exec program\n");
}

