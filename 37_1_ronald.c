#include <stdio.h>
int fibo (int a)
{
    if(a==0 || a==1)
    {
        return a;
    }
    else
    {
        return fibo (a-2) + fibo (a-1);
    }
}

void main()
{
    int n; int a=0; int count = 0 ; int i;
    printf("Enter a number");
    scanf("%d",&n);
    for (i=0; i<=n;i++)
    {
        if (fibo(a)==n)
        {
            count++;
            break; 
        }
        a++;
    }
    if(count!=0)
    {
        printf("Fibonacci number");
    }
    else
    {
        printf("Not a Fibonacci number");
    }
}