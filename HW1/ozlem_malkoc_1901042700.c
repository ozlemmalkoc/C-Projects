#include <stdio.h>

#define  NUMBER 20	/* The total number of points that can be entered for two classes */
 
int main() 
{
	int i = 1;
	float x = 0,y = 0,sumx = 0,sumy = 0,averagex1 = 0,averagey1 = 0;
	float averagex2 = 0,averagey2 = 0,midpointx = 0,midpointy = 0,slope = 0,seperatinglineslope = 0;
 	
    for(i = 1;i <= NUMBER/2;i++)	
    {
	 	scanf("%f%f",&x,&y);	/* User is prompted to enter points to create  class 1 */
	 	sumx += x;		/* X coordinate values of class 1 are summed */
	 	sumy += y;		/* Y coordinate values of class 1 are summed */
    }
    
    averagex1 = sumx / (NUMBER / 2);	/* Finds the average of the x coordinate values for Class 1 */
    averagey1 = sumy / (NUMBER / 2);	/* Finds the average of the y coordinate values for Class 1 */
    sumx = 0,sumy = 0;		/* The variables (sumx, sumy) taken from the loop are set to 0 for use in the data requested for class 2 */
    
    for(i; i <= NUMBER;i++)
    {
	 	scanf("%f%f",&x,&y);	/* User is prompted to enter points to create  class 2 */
	 	sumx += x;		/* X coordinate values of class 2 are summed */
	 	sumy += y;		/* Y coordinate values of class 2 are summed */
    }
   
    averagex2 = sumx / (NUMBER / 2);	/* Finds the average of the x coordinate values for Class 2 */
    averagey2 = sumy / (NUMBER / 2);	/* Finds the average of the y coordinate values for Class 1 */
    midpointy = (averagey2 + averagey1) / 2;	/* The middle y-point is determined using the y values of class 1 and class 2 */
    midpointx = (averagex2 + averagex1) / 2;	/* The middle x-point is determined using the x values of class 1 and class 2 */
	
	if(averagex2 - averagex1 == 0)
	{	
		averagex2 = averagex2 + 0.0000000001;	/* A very small number close to 0 was added to prevent undefined */
	}

	slope = (averagey2 - averagey1) / (averagex2 - averagex1);	/* Using the average values found for class 1 and class 2, the slope of the line passing through these points is calculated. */

	/*(y - averagey2 == slope * (x - averagex2)) The line connecting the two average points. */
	
	if(slope == 0)
	{
		slope = slope + 0.0000000001;	/* A very small number close to 0 was added to prevent undefined */
	}
	
	seperatinglineslope = -1 / slope;	/*The slope of the line perpendicular to the line passing through the midpoints is found */
	x = 0,y = 0;	/* The variables (sumx, sumy) taken from the loop are set to 0 for use in the data requested for class 2 */
	
	/* (y - midpointy == seperatinglineslope * (x - midpointx)) The perpendicular separating line which passes through the midpoint. */
	
	while(1)
	{
		if(scanf("%f%f",&x,&y) == 2)	/* If 2 float value is received successfully, it continues */
		{
			if(y - midpointy - (seperatinglineslope * (x - midpointx)) < 0)	  /* y-y0-(m*(x-xo))<0 If the equation is provided, the test value is in class 1 */
			{
				printf("class1\n");
        		}
	
			else if(y - midpointy - (seperatinglineslope * (x - midpointx)) > 0)		/* y-y0-(m*(x-xo))>0 If the equation is provided, the test value is in class 2 */	
			{
				printf("class2\n");
	    		}
	   	 }
	    else
	    break;	/* Exits loop if two float values are not successfully received (unwanted character input) */
	}
	
	return 0;
}
