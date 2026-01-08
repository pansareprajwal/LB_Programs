/*
    START
        Accept number and store as no
        Divide no by 2
        If the the remainder is 0
            then display as Even
        Otherwise
            display as Odd
    STOP

*/

#include<stdio.h>

///////////////////////////////////////////////////////////////////////
//
//  Function Name :     CheckEvenOdd
//  Description :       It is used to chek even or odd
//  Input :             Integer
//  Output :            Boolean
//  Author :            Prajwal Sanjay Pansare
//  Date :              10/10/2025
//
///////////////////////////////////////////////////////////////////////

void CheckEvenOdd(int iNo)
{
    int iRem = 0;

    iRem = iNo % 2;

    if(iRem == 0)
    {
        printf("It is Even number\n");
    }
    else
    {
        printf("It is Odd number\n");  
    }
}

int main()
{
    int iValue = 0;

    printf("Enter number:");
    scanf("%d",&iValue);

    CheckEvenOdd(iValue);

    return 0;
}