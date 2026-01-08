// Input : 12   2       Output : true
// Input : 12   3       Output : false
// Input : 12   5       Output : false
// Input : 12   12      Output : true
// Input : 12   7       Output : false

#include<stdio.h>
#include<stdbool.h>

bool Checkdivisible(int iNo1, int iNo2)
{
    if(iNo1 % iNo2 == 0)
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
    int iValue1 = 0, iValue2 = 0;
    bool bRet = false;

    printf("Enter first number : \n");
    scanf("%d",&iValue1);

    printf("Enter second number : \n");
    scanf("%d",&iValue2);

    bRet = Checkdivisible(iValue1,iValue2);

    if(bRet == true)
    {
        printf("It is completely divisible\n");
    }
    else
    {
        printf("It is not divisible\n");
    }

    return 0;
 }