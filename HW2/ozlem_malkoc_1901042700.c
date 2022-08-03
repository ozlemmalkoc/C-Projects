#include <stdio.h>

#define p1 0.5	/* Constant value to use in the equation. */
#define p2 20	/* Constant value to use in the equation. */

int main()
{
	float n = 0.0,b = 0.0,a = 0.0;	/* N is the number to be added and a is the average of the chunk. If n is added to the current chunk the average becomes b. */
	int i = 2;	/* Number of elements in chunk. */
	FILE *readp = fopen("input.txt","r");	/* File is opened to read data and assigned to pointer. */
	FILE *writep = fopen("output.txt","w");	/* The file is opened for writing data and assigned to the pointer. */

	fscanf(readp,"%f",&n);	/* First data is read from file. */
	
	while(!feof(readp))	/* Data is read until it reaches the end of the file. */
	{
		fprintf(writep,"%.4f ",n);	/* It prints the first element of the chunk. */
		a = n;

		while(fscanf(readp,"%f",&n) != EOF)	/* Data is read until it reaches the end of the file. */
		{
			b = (a * (i - 1) + n) / i;	/* The new average is calculated using the old average and the last value read. */
			
			if(!(b > a * (1 + p1) || b < a * (1 - p1) || a > n * p2 || a < n / p2))	/* if condition is true ,transactions within the if block are executed. */
			{
				fprintf(writep,"%.4f ",n);	/* it prints the new element(n) of the chunk. */
				i++;	/* The number of data in the chunk is increased. */
				a = b;	/* The new average(b) calculated for the chunk is assigned as the old average(a). */
			}
			
			else  /* If the condition in the if block is not satisfied, this block is entered.*/
			{
				i = 2;	/* The number of elements in the chunk (i) is assigned as 2, since the new line will be passed. */
				break;	/* The inner loop is terminated to move to the new line. */
			}	
   		 }
	
		fprintf(writep,"average: %.4f",a);	/* Chunk taki sayıların ortalaması yazdırılır. */
		fprintf(writep,"\n");	/* It passes to the bottom line for the new chunk. */
		a = 0.0;	/* The value of a is reset to be able to correctly calculate the new value of a.*/
		b = 0.0;	/* The value of a is reset to be able to correctly calculate the new value of a.*/
	}

	fclose(readp);	/* File opened to read data is closed. */
	fclose(writep);	  /* File opened to write data is closed.*/

	return 0;
}