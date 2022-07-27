#include <stdio.h>

void addition( double a , double b );

int main()
{
    while(1)
    {
        double num1 , num2 ; 
        //printf("Enter the 2 number on which you want to perform operations\n");
        printf("Enter number 1: ");
        scanf("%lf",&num1);
        printf("Enter number 2: ");
        scanf("%lf",&num2);

        printf("\nEnter the number corresponding to the opperation that you want to perform\n");

        printf("1 : Add  \n");

        int Operation;
        printf("Operation Number :");
        scanf("%d",&Operation);

        switch(Operation)
        {
            case 1:
                addition(num1,num2);
                break;
        }
    }
}

void addition( double a , double b )
{
    printf("%lf + %lf = %lf\n\n\n" ,a,b,a+b );
}