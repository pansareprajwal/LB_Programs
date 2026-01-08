#include<stdio.h>
#include<stdbool.h>

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

bool CheckEvenOdd(int iNo)
{
    int iRem = 0;

    iRem = iNo % 2;

    if(iRem == 0)
    {
        return true;
    }
    else
    {
        return false;  
    }
}

int main()
{
    int iValue = 0;
    bool bRet = false;

    printf("Enter number:");
    scanf("%d",&iValue);

    bRet = CheckEvenOdd(iValue);

    printf("Result is : %d\n",bRet);

    return 0;
}