/*
step 1: Understand the problem statement
step 2: Write the algorithm
step 3: Decide the programing language
step 4: Write the Program
step 5: Test the Program
*/

/*
    Algorithm

    START
       Accept first number as no1
       Accept second number as no2
       Perform Addition of no1 and no2
       If the input in negative then convert it into positive
       Display the addition on screen
    STOP

*/

#include<stdio.h>

float AdditionTwoNumbers(float fNo1,float fNo2)
{
    float fSum = 0.0f;

    if(fNo1 < 0.0f)       // Updator 
    {
        fNo1 = -fNo1;
    }

    if(fNo2 < 0.0f)       // Updator
    {
        fNo2 = -fNo2;
    }

    fSum = fNo1 + fNo2;     // Business Logic

    return fSum;
}

int main()
{
    float fValue1=0.0f,fValue2=0.0f,fRet=0.0f;

    printf("Enter first number : \n");
    scanf("%f",&fValue1);

    printf("Enter second number : \n");
    scanf("%f",&fValue2);

    fRet = AdditionTwoNumbers(fValue1,fValue2);

    printf("Addition is : %.2f\n",fRet);

    return 0;
}