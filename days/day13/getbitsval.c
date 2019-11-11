main()
{
	unsigned int mask;
	int startBitNumber = 8;
	int noOfBits =5;
	int val = 0xF1e00;   //change the value and check
	int temp;
	mask = (1<<noOfBits)-1;
	temp = (val >> startBitNumber) & mask;
	printf("0x%x\n",val);
}
