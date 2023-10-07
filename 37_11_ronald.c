#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>

int stack[5];
int top=-1; // Stack initialization condition
/*Function Prototype*/
//push method is used to insert element into the stack//
void push(int);

//pops method is used to delete elements from the stack//
void pop();

//display method is used to traverse and print all the elements from the stack//
void display();

/*Main Method*/
void main()
{
int ch; //This is used to store user choice 
int n1;

while (1)
{
//clrscr();

printf("\n----Stack operation---");
printf("\n1. Push an element into the stack");
printf("\n2. Pop out an element from the stack");
printf("\n3. Display the stack elements");
printf("\n4 .Exit");

printf("\n Enter your choice");
scanf("%d",&ch);

switch(ch)
{
case 1:printf("\n Enter the elemets to be pushed into the stack");
       scanf("%d",&n1);
       push(n1);
       break;
       
case 2:pop();
       //getch();
       break;
       
case 3:display();      
       //getch();
       break;
       
case 4:exit(1);

default:printf("\n Wrong choice ");
        break;
} //end of switch 
}
/*end of main method*/
/*push method*/
void push(int x)
{
if (top==4)
   {
       printf("stack is FULL");
   }
   else
   {
   top++;
   stack[top]=x;
   }
}
/*end of push method*/

/*pop method*/
void pop()
{
   int a;
   if (top==-1)
   {
       printf("stack is EMPTY"); 
   }
   else
   {
       a= stack[top];
   top--;
       printf("\n %d element poppedd out of the stack",a);
   }   
}
/*end of pop method*/
 /*display method*/
 void display()
 {
 int i;
 if(top==-1)
     printf("stack is empty");
 else
 {
     printf("\nelements i the stack are");
     for(i=top;i>=0;i--)
     {
         printf("\n %d",stack[i]);
     }
 }
 }
   /*end of display method*/
}
