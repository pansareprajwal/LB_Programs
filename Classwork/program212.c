#include<stdio.h>

int main()
{
    char Name[50] = {'\0'};

    printf("Enter your name : \n");
    scanf("%s",Name);                   // scanf limitation 

    printf("Hello : %s\n",Name);

    return 0;
}

// Input : Rahul Pati
// Output : Rahul