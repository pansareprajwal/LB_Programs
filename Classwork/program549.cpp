#include<stdio.h>
#include<stdlib.h>

int main()
{
    #ifdef _WIN32           // conditional preprocessing
        system("dir");

    #else
        system("ls");

    #endif

    return 0;
}