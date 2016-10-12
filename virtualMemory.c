// Daniel Hernandez
// 4/18/16
// CSC 341
// Extra Credit Project

/* Extra Credit Project: This program takes in a virtual memory address as a decimal from the command line. We have the assumption that the system has a 64-bit virtual address with a 64-KB page size. The calculations for number of bits for the pageNumberSection and the pageOffsetSection are hard coded based on the assumption provided. To get the pageNumber, we will shift the bits that represent the virtual address to the right side by the number of bits in the value pageOffsetSection so that we drop those bits. The bits that are left will give the number for the pageNumber. To get the offset, we shift the bits that represent the virtual address to the left by the number of bits in the value of pageNumberSection so that we drop the bits that represent the pageNumber. Now we have the bits that represent the offset + many 0's. To correct this, we shift to the right by the number of bits in the value pageNumberSection. This will give many leading 0's (which are ignored) + the bits representing the offset, which is what we want. Then the program simply displays the required information.
*/

//Required include statements
#include <stdio.h>
#include <stdlib.h>
#include <math.h>	// Required for use of math functions (log2())

int main(int argc, char * argv[])
{
	long unsigned int enteredAddress = 0; 	// required to store address passed in (64 bits)
	long unsigned int pageNumberSection = 64 - log2(65536); // 48 bits, based on assumptions
	long unsigned int pageOffsetSection = log2(65536); 	// 16 bits, based on assumptions
	
	long unsigned int pageNumber;		// used to store the calculated page number
	long unsigned int offset;		// used to store the calculated offset
	
	// Checks to make sure that a virtual memory address is being passed in
	if(argc != 2)
	{
		fprintf(stderr, "Usage: <virtual memory address>\n");
		return -1;
	}
	
	// convert from characters to integer representation
	enteredAddress = atoi(argv[1]);
	
	// the following three lines perform bit manipulation which results in page number and offset
	pageNumber = enteredAddress >> pageOffsetSection; // get portion that represetns page number
	offset = enteredAddress << pageNumberSection; // get portion that represents offset
	offset = offset >> pageNumberSection; // allign bits to correct position with leading 0s
	
	// Output calculations
	printf("The address %lu contains:\npage number = %lu\noffset = %lu\n", enteredAddress, pageNumber, offset);
	
	return 0;
}
