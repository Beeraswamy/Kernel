#define DEBUG
main()
{
	#ifdef DEBUG
		printf("Debug Statement 1\n");
	#endif
	#ifdef DEBUG
		printf("Debug Statement 2\n");
	#endif
	#ifdef DEBUG
		printf("Debug Statement 3\n");
	#endif
}
