#include<stdio.h>

void Display(int Arr[])              // Replacing pointer (*Arr) with array Arr[]
{
    int iCnt = 0;

    for(iCnt = 0; iCnt < 4; iCnt++) 
    {
        printf("%d\n",Arr[iCnt]);    // Pointer can be treated as array
    }
}

int main()
{
    int Brr[] = {10,20,30,40};     

    Display(Brr);   // Display(100); -- Array always pass base address of first element
    

    return 0;
}
