#include <stdio.h>
#include<string.h>

#define VALUENUM 100    //max size of values
#define MAXCHARNUM 1000 //max size of polynom

char mychararray[MAXCHARNUM] = { 0 };//polynom
double value[VALUENUM];//x values storage

double funct(char arr[] , double x){  /* polynom calculator */
   
    int size = strlen(arr);
    double res = 0;  /* result */
    double temp = 0;  /* temp number carrier */
    int dotnum = 1;  /* number of after dot +1 */
    int dotseen = 0; /* is dot seen */
    int sign = 1;  /* + or - */
    
    for (int i = 0; i < size; i++) {
       
        if (arr[i] == 'x') {
            double tempres = x;
           
            if (i + 1 < size && arr[i + 1] == '^') {    /* if ve have ^ we have to check right side to */
                int temp2 = 0;
                i += 2;
               
                for (; i < size; i++) {
                    if (arr[i] == '+' || arr[i] == '-')break;
                   
                    temp2 *= 10;
                    temp2 += arr[i] - '0';
                }
               
                i--;
               
                for (int j = 0; j < temp2-1; j++) {
                    tempres *= x;
                }

            }
            if (temp == 0) {
                temp = 1;
            }
            for (int i = 1; i < dotnum; i++) temp /= 10;
            tempres *= temp;
            temp = 0;
            dotnum = 1;
            dotseen = 0;
            
            if (sign == 1) res += tempres;
            else res -= tempres;

        }
    
        else if (arr[i] == '-') {   /* add temp to res than make sign - */
            for (int i = 1; i < dotnum; i++) temp /= 10;
           
            if (sign == 1) res += temp;
            else res -= temp;
            
            temp = 0;
            sign = 0;
            dotseen = 0;
            dotnum = 1;
        }
        else if (arr[i] == '+') {  /* add temp to res than make sign + */
            for (int i = 1; i < dotnum; i++) temp /= 10;
            if (sign == 1) res += temp;
            else res -= temp;
           
            temp = 0;
            sign = 1;
            dotseen = 0;
            dotnum = 1;
        }
        else if (arr[i] == '.') {   /* make dotseen 1 */
            dotseen = 1;
        }
        else {  /* add temp to res */
            temp *= 10;
            temp += arr[i] - '0';
            if (dotseen == 1)dotnum++;
        }
    }
    /*  if we have value in temp we have to add to res */
    if (sign == 1) res += temp;
    else res -= temp;

    return res;
}

void readingandremovespacepolifunc(char arry[]) /* read polinom to arr */
{
    FILE* ppoli = fopen("polynomial.txt", "r"); /* opening file */
    
    int i = 0;  /*index */
    char letter = 0;    /* temp letter */

    while (!feof(ppoli))
    {
        fscanf(ppoli, "%c", &letter);
        if (letter != ' ')
        {
            arry[i] = letter;   /* save temp letter to array */
            i++;
        }
    }
    arry[i-2] = '\0';   /*make last index end of file */
    
 fclose(ppoli); /* close file */
}

void readingvaluesfunc(int size) /* reading x values to value */
{  
    FILE * pevaluations=fopen("evaluations.txt","w");
    FILE * pvalue=fopen("values.txt","r");  /* opening file */
    int i=0;  /* index */
   
    while(!feof(pvalue))
    {
        fscanf(pvalue,"%lf",&value[i]);  /* read float */
         i++;
    }
   
    int  j ;    /* x array index */
    
    for(j = 0;j<i-1;j++){
        fprintf(pevaluations,"%.2lf\n", funct(mychararray, value[j]));  /* print result of equavalation */
    }
    fclose(pvalue); /* close file */
 }

int main(){
    
    readingandremovespacepolifunc(mychararray);//call polynom reading function
    readingvaluesfunc(VALUENUM);//read values an

    return 0;
}