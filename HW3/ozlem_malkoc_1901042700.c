#include <stdio.h>
#include <string.h>

#define ROW 100
#define COLUMN 250
#define MAXWORDSLENGTH 10

int main(){

	FILE* pinput1=fopen("input1.txt","r");	/* File(input1.txt) is opened to read data and assigned to pointer. */
	FILE* pinput2=fopen("input2.txt","r");	/* File(input2.txt) is opened to read data and assigned to pointer. */
	FILE* poutput=fopen("output.txt","w");	/* The file(output.txt) is opened for writing data and assigned to the pointer. */

	char input2[ROW][COLUMN] = {};	/* Two-dimensional array created. */
	char input1[MAXWORDSLENGTH] = {};	/* One-dimensional array created.*/
	int i=0,j=0,n=0,result=0,k=0,counter=0,l,flag;

	for(i=0;i<ROW;i++)	
		fgets(input2[i],COLUMN,pinput2);	/* The data read from the file(input2.txt) is saved in a two-dimensional array. */

	while(fgets(input1,MAXWORDSLENGTH,pinput1))	/* Each time to the loop is entered, data from the file is saved inside the one-dimensional array. */
	{
		counter = k = n = l = flag = 0;

		n=strlen(input1);	/* N value is 1 longer than the length of the new word read from input1.txt (we get the length of the word by subtracting 1 the value of the '\n' character at the end of the word). */
		
		for(i=0;i<ROW;i++)
		{	
			for(j=0;j<COLUMN;j++)
			{
				flag=0;
				
				if(input2[i][j]==input1[l])	/* The character in the input2.txt file is compared with the first characters in the input1.txt file. If the characters are the same, it enters this block. */
				{	
					counter++;	/* Variable that holds the  number of same characters in words. */
					result=strncmp(&input2[i][j],input1,n-1);	/* The characters of words in  input1 and Horizontal word starting at address i, j are compared. If the word in input1 and the word starting at address i, j are the same, the result returns zero. */
					
					if(result==0)
					{
						if(input1[strlen(input1)-1] == '\n')	/* If the last character of the word read from input1 is '\ n', it enters into if. */
							input1[strlen(input1)-1] = '\0';	/* Makes the trailing character '\ n' zero.Thus, the position and the direction of the sequence and the name of the word are written on the same line. */
						
						fprintf(poutput,"%s (%d,%d) horizontal\n",input1,i+1,j+1);
					}
					
					else
					{
						for(k=1;k<n;k++)
						{
							if(input2[i+k][j]==input1[k])	/* The characters of the words are compared, if the characters are the same, the counter value is increased. */
							{	
								counter++;
								flag=1;	/* If the vertical word and the word in input1 are the same, flag is 1. */
							}
						}
					
						if(counter==n-1 && flag)	/* If the number of characters in the word and the counter is the same value and the flag value is 1 (ie vertical comparison is made) it makes this block. */
						{
							if(input1[strlen(input1)-1] == '\n')	/* If the last character of the word read from input1 is '\ n', it enters into if. */
								input1[strlen(input1)-1] = '\0';	/* Makes the trailing character '\ n' zero.Thus, the position and the direction of the sequence and the name of the word are written on the same line. */
							
							fprintf(poutput,"%s (%d,%d) vertical\n",input1,i+1,j+1);
							break;
					    }
						
						else if(counter != n-1 && flag)	/* If the number of characters in the word and the counter is the same value and the flag value is 1 (ie vertical comparison is made) it makes this block. */
							counter = 0;
					}
				}	
			}
		}
	}

	fclose(pinput1);	/* File opened to read data is closed. */
	fclose(pinput2);	/* File opened to read data is closed. */
	fclose(poutput);	/* File opened to write data is closed.*/

	return 0;
}