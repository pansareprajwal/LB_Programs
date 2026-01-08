//  Best way to get array address 

#include<stdio.h>

int main()
{
     int Arr[] = {10,20,30,40};

     printf("%d\n",Arr);            // Best use
     printf("%d\n",&Arr);
     printf("%d\n",&(Arr[0]));

     printf("%lu\n",sizeof(Arr));

    return 0;
}
