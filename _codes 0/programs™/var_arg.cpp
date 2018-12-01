#include<bits/stdc++.h>

using namespace std;

void varfun(int n, ...)
{
    int num;
    va_list ptr; // Type to hold information about variable arguments
    va_start(ptr, n); //Initialize a variable argument list  of size N
    num = va_arg(ptr, int); /* interpret as double, then convert to int */
    printf("%d\n",num);
    num = va_arg(ptr, int);
    printf("%d\n",num);
}

int main(int argc, char **argv)
{
    varfun(3,7,11,66);
    return 0;
}
