# virtualMemory
This program takes in a virtual memory address as a decimal from the command line. We have the assumption that the system has a 64-bit virtual address with a 64-KB page size. The calculations for number of bits for the pageNumberSection and the pageOffsetSection are hard coded based on the assumption provided. To get the pageNumber, we will shift the bits that represent the virtual address to the right side by the number of bits in the value pageOffsetSection so that we drop those bits. The bits that are left will give the number for the pageNumber. To get the offset, we shift the bits that represent the virtual address to the left by the number of bits in the value of pageNumberSection so that we drop the bits that represent the pageNumber. Now we have the bits that represent the offset + many 0's. To correct this, we shift to the right by the number of bits in the value pageNumberSection. This will give many leading 0's (which are ignored) + the bits representing the offset, which is what we want. Then the program simply displays the required information.

How to compile:

Linux/UNIX & Mac OS X: Open terminal, cd to the directory where the source code file is stored. Run "gcc -o virtualMemory virtualMemory.c" (without quotes) on the terminal window. To run the program, simply do "./virtualMemory <virtual memory address>" (without quotes) (replace each <> with an actual integer number). Example: ./virtualMemory 199860000

Windows: It is recommended to compile and run this code using an IDE such as Code Blocks.
