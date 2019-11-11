main()
{
	int val=0x80;
	int bitval=0x1F;

	/*1st step - Clear all the 5 bits in the value from 21st to 25th position*/
	val = val & ~0x3E00000;
	
	/*2nd-Step - Left Shift the bitval 21 times*/
	bitval = bitval << 21;
	
	/*3rd step - OR the value with the original value*/
	val = val | bitval;
	printf("0x%x\n",val);
}
	
