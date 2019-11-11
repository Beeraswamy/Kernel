void display();
main()
{
	void (*fPtr)();
	fPtr=display;
	//display();
	(*fPtr)();
	fPtr();
}
void display()
{
	printf("Hello\n");
}
//you have to use ()-paranthsis between *fPtr otherwise the compiler confuses that with the function name.
