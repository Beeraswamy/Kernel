/*C-language treats parts of the arrays as arrays. Each row of two dimensional array can be thought of as a one dimensional array. This is very important if we wish to access array elements of two dimensional array using pointers. 
Thus s[4][2] can be thought of as a setting up of two dimensional array of 8 elements each of which is a one dimensional array 2 elements longs.
-> We refer to the one dimensional array using single subscript.
-> s[0] gives the address of the zeroeth one dimensional array.
->s[1] gives the address of the first one dimensional array.*/

main()
{
	int s[4][2]={{1234,56},
			{1212,33},
			{1434,80},
			{1312,78}};
	int i,j;
	for(i=0;i<=3;i++)
		//printf("Address of %d the 1-D array 0x%x 0x%x\n",i,s[i],s+i);
		//printf("Element of %d the 1-D array %u %u\n",i,*(s[i]),**(s+i));
	printf("0x%x 0x%x %u\n",(s+i),*(s+i),**(s+i));
		
}
			
/*The compiler knows that s is an integer array. So each element of this array occupies 4 Bytes. Thus each row starts 8 bytes further along than the last one.Since each row is one dimensional array starts 8 bytes further along the last one.
The compiler knows how many columns are there in the array s, since we specified this in the array declaration. So it interprets the expression s[0] as s+0, and s[1] as (s+1). Now we have been able to reach individual row. What remains is to refer to element of each row. Suppose we want to refer to the element s[2][1] using pointers. We know from the above program that s[2] would give the address, the address of the second one dimensional array.s[2]+1 gives you the address of 2 rows first element.and the value at this address can be obtained by using *(s[2]+1). But we have already studies that the while learning one dimensional array that s[2] is *(s+i). Similarly *(s[2]+1) is same as *(*(s+2)+1). Thus all the following expressions refer to the same element
	s[2][1]
	*(s[2]+1)
	*(*(s+2)+1) */ 			


