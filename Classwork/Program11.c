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

//////////////////////////////////////////////////////////////
//
//  Required Header file
//
//////////////////////////////////////////////////////////////

#include<stdio.h>

//////////////////////////////////////////////////////////////
//
//  Function name : AdditionTwoNumbers
//  Description :   It is use to perform addition
//  Input :         float,float
//  Output :        float
//  Author :        Prajwal Sanjay Pansare
//  Date :          09/10/2025
//
//////////////////////////////////////////////////////////////

float AdditionTwoNumbers(
                            float fNo1,         // first input
                            float fNo2          // second input
                        )
{
    float fSum = 0.0f;                          // To store the result

    if(fNo1 < 0.0f)                             // Updator 
    {
        fNo1 = -fNo1;
    }

    if(fNo2 < 0.0f)                             // Updator
    {
        fNo2 = -fNo2;
    }

    fSum = fNo1 + fNo2;                         // Business Logic

    return fSum;
}   // End of AdditionTwoNumbers

//////////////////////////////////////////////////////////////
//
//  Entry point function for the application
//
//////////////////////////////////////////////////////////////

int main()
{
    float fValue1=0.0f,fValue2=0.0f;            // To accept user input
    float fRet=0.0f;                            // To store result

    printf("Enter first number : \n");
    scanf("%f",&fValue1);

    printf("Enter second number : \n");
    scanf("%f",&fValue2);

    fRet = AdditionTwoNumbers(fValue1,fValue2); // Method call

    printf("Addition is : %.2f\n",fRet);

    return 0;
}   // End of main

//////////////////////////////////////////////////////////////
//
//  Test successfully handled by the application
//
//  Input1 : 10.5       Input2 : 3.2      Output : 13.7   
//  Input1 : -10.5      Input2 : 3.2      Output : 13.7   
//  Input1 : 10.5       Input2 : -3.2     Output : 13.7   
//  Input1 : -10.5      Input2 : -3.2     Output : 13.7   
//
//////////////////////////////////////////////////////////////