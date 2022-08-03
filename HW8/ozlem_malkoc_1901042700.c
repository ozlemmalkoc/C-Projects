#include <stdio.h>
#include <stdlib.h>
 
#define SIZE 512	/* Row and column value for array */
#define HIGH -1		/* Value assigned to values greater than L */
#define LOW -2		/* Value assigned to values lower than L */
#define STARTINGPOINT -9	/* Value assigned to  the island's starting point */

int arr[SIZE][SIZE]={0};	/* A two-dimensional array is defined for terrain coordinates. */
int i=0,j=0,counter=0;	/* Counter = The variable to hold the number of islands */

void assigmentLevel(int indicator){	/* The value in each coordinate is compared with the value of L. If the value in the coordinate is greater than the L value, the value HIGH is assigned to that coordinate, otherwise the value LOW is assigned.Indicator = L value */

for(i=0;i<SIZE;i++)
{	for(j=0;j<SIZE;j++)
	{	
		if(arr[i][j]>indicator)
		arr[i][j]=HIGH;
		else 
		arr[i][j]=LOW;	
	}
}
}
void assignStartingPoint(){  /*Starting points of islands are partially assigned*/ 

for(i=0;i<SIZE;i++)
{	for(j=0;j<SIZE;j++)
	{	
		if(arr[i][j]==HIGH)	/*If the value in the coordinate we are examined is HIGH, it is entered in this block.*/
		{	
			if(i==0 && (arr[i][j-1]==LOW || j==0)) /*If the value of i is 0 and the value to the left of the coordinate we are examining is LOW, or if the value of j is 0, the value STARTİNGPOİNT is assigned to the value in the place we are examining */
				arr[i][j]=STARTINGPOINT;
			
			if(arr[i-1][j]==LOW && arr[i][j-1]==LOW) /*If the value in the upper left cross of the coordinate we are examining is LOW, then the STARTINGPOINT value is assigned instead of the value in the coordinate we examined.*/
				arr[i][j]=STARTINGPOINT;
		 }
	}
}
}

void fixStartingPoint(){ /* In the assignStartingPoint function, we assigned all the starting points when assigning STARTINGPOINT, but some points lose the ability to be STARTINGPOINT because it is part of the island near it.So instead of this coordinate value, we throw the LOW value again.*/

for(i=0;i<SIZE;i++)
{	for(j=0;j<SIZE;j++)
	{	
		if(arr[i][j]==STARTINGPOINT) /*If the coordinate value we are examining is STARTINGPOINT*/
		{
			if(arr[i-1][j+1]==STARTINGPOINT && (arr[i][j+1]==HIGH || arr[i-1][j]==HIGH)) /* If the value on the right or above the value we are examining is HIGH and the value on the top right cross is STARTINGPOINT, a HIGH value is assigned to the value we are examining. */
				arr[i][j]=HIGH;
		 }
	}
}
}

void koordinatePrint(FILE * fp){	/*The coordinates of the islands are printed */

for(i=0;i<SIZE;i++)
{	for(j=0;j<SIZE;j++)
	{	
		if(arr[i][j]==STARTINGPOINT)
		fprintf(fp,"%d %d\n",i+1,j+1);
		
	}
}
}

int findTotalIslandNumber(){	/* The total number of islands is found */

for(i=0;i<SIZE;i++)
{	for(j=0;j<SIZE;j++)
	{	
		if(arr[i][j]==STARTINGPOINT)
		counter++;
	}
}
return counter;
}

int main(){

FILE * inputptr=fopen("input.txt","r");	/* To read from the file, the file is opened in read mode and assigned to the FILE pointer */
FILE * outputptr=fopen("output.txt","w");	/*To write to the file, the file is opened in write mode and assigned to the FILE pointer */

int number=0;	/*Initial value to be read from input file = L */
	
fscanf(inputptr,"%d",&number);	/* First value is read from input file */

for(i=0;i<SIZE;i++)
{	for(j=0;j<SIZE;j++)
	{	
		fscanf(inputptr,"%d",&arr[i][j]);	/*Values in coordinates are read from the file and these values are stored in arr array*/
	}
}

assigmentLevel(number); /* The value in each coordinate is compared with the value of L. If the value in the coordinate is greater than the L value, the value HIGH is assigned to that coordinate, otherwise the value LOW is assigned.Indicator = L value = number*/
assignStartingPoint();	/*Starting points of islands are partially assigned*/ 
fixStartingPoint();	/* In the assignStartingPoint function, we assigned all the starting points when assigning STARTINGPOINT, but some points lose the ability to be STARTINGPOINT because it is part of the island near it.So instead of this coordinate value, we throw the LOW value again.*/

fprintf(outputptr,"\n\n");		/*To write the number of islands to the beginning of the file, space is reserved from the beginning of the file before the coordinates*/
koordinatePrint(outputptr);	/*The coordinates of the islands are printed */

fseek(outputptr, 0, SEEK_SET);	/*The FILE pointer is returned to the starting address */
fprintf(outputptr,"%d",findTotalIslandNumber());	/*The number of islands is written to the output file */

fclose(outputptr);	/* File opened for reading are closed */
fclose(inputptr);	/* File opened for writing are closed */

return 0;
}