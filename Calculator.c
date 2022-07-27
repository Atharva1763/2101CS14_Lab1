#include <stdio.h>
#include<math.h>

void addition( double a , double b );
void substract( double a , double b );
void multiplication( double a, double b);
void division( double a , double b );
void modulo(double a,double b);

int main()
{
    while(1)
    {
        printf("\nEnter the number corresponding to the opperation that you want to perform\n");
        printf("0 : Exit \n");
        printf("1 : Add  \n");
        printf("2 : Substract\n");
        printf("3 : Multiplication\n");
        printf("4 : Division\n");
        printf("5 : Modulo\n");

        int Operation;
        printf("Operation Number : ");
        scanf("%d",&Operation);
        if(Operation > 5)                               //If Operation > 5 then it is an invalid command
        {
            printf("\nWrong operation command.Please try again\n");
            continue;
        }
        if(Operation == 0)                              //To terminate the program
        {
            break;
        }
        
        double num1 , num2 ; 
        printf("Enter the 2 operands\n");

        printf("Enter number 1: ");
        scanf("%lf",&num1);
        printf("Enter number 2: ");
        scanf("%lf",&num2);
        
        switch(Operation)
        {
            case 1:
                addition(num1,num2);
                break;
            case 2:
                substract(num1,num2);
                break;
            case 3:
                multiplication(num1,num2);
                break;
            case 4:
                division(num1,num2);
                break;
            case 5:
                modulo(num1,num2);
                break;
        }
    }
    return 0;
}

void addition( double a , double b )                   //Function made for addition 
{
    printf("\n%lf + %lf = %lf\n\n\n" ,a,b,a+b );
}

void substract( double a , double b )                    //Function made for substraction
{
    printf("\nEnter 1 for Number1 - Number2 \nEnter 2 for Number2 - Number1\n");
    int op; 
    scanf("%d",&op);

    switch(op)
    {
        case 1:
            printf("%lf - %lf = %lf\n\n\n",a,b,a-b);
            break;
        case 2:
            printf("%lf - %lf = %lf\n\n\n",b,a,b-a);
            break;
        default:
            printf("\nWrong command, please try again\n");
            substract(a,b);
            break;
    }
}

void multiplication( double a , double b )                  //Function made for multiplication
{
    printf("\n%lf * %lf = %lf\n\n\n", a, b ,a*b );
}

void division( double a , double b )                          //Function made for division
{
    printf("\nEnter 1 for Number1/Number2 \nEnter 2 for Number2/Number1\n");
    int op; 
    scanf("%d",&op);

    switch(op)
    {
        case 1:
            printf("%lf / %lf = %lf\n\n\n",a,b,a/b);
            break;
        case 2:
            printf("%lf / %lf = %lf\n\n\n",b,a,b/a);
            break;
        default:
            printf("\nWrong command, please try again\n");
            division(a,b);
            break;
    }
}

void modulo( double a,double b )                                //Function made for modulo
{
    printf("\nEnter 1 for Number1 modulo(Number 2) : \nEnter 2 for Number2 modulo(Number1) :\n");
    int op; 
    scanf("%d",&op);

    switch(op)
    {
        case 1:
            printf("%lf modulo %lf = %lf\n\n\n",a,b,remainder(a,b));
            break;
        case 2:
            printf("%lf modulo %lf = %lf\n\n\n",b,a,remainder(b,a));
            break;
        default:
            printf("\nWrong command, please try again\n");
            modulo(a,b);
            break;
    }
}
