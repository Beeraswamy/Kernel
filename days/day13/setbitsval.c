/*Program to set a group of bits*/
main()
{
	unsigned int mask;
	int val=0xF;
	
	int startBitNumber = 20;
	int bitsVal = 0x1F;
	int noOfBits = 5;
	
	mask = (1<<noOfBits) - 1;
	val = val & ~(mask << startBitNumber);  //Clear bits from 20th bit to 24th bit.
	val = val | (bitsVal<<startBitNumber);	//Setting bits starting from 20th bit to 24th bit.
	printf("Value 0x%x\n",val);
}


