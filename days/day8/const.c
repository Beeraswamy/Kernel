main()
{
	int x=20;
	int y=30;
#if 1		
	int *const myPtr = &x;
	//myPtr = &y; 	//invalid
	*myPtr = 40; 	//valid
#endif
#if 0
	const int *myPtr = &x;
	//*myPtr = 60;	//invalid
	myPtr = &y;	//valid
#endif

#if 0
	const int *const myPtr = &x;
	*myPtr = 60;	//invalid
	myPtr = &y;	//invalid
#endif
}
