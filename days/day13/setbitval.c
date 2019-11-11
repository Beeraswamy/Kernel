main()
{
	int bitNumber=10;
	int bitvalue=0; //1 or 0
	int val = 0xF00;
	
	if(bitvalue)
		val = val | (1<<bitNumber);
	else
		val = val & ~(1<<bitNumber);

	printf("0x%x",val);
}
		
