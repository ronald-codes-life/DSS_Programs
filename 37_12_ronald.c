#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#define Size 5

int queue [Size];
int front,rear;

/*functio prototype*/

void init();
void enqueue(int);
void dequeue();
void display();

/*initialization method*/
void init()
{
front=0;
rear=-1;
}
/*end of initialization method*/

/*enqueue method*/
void enqueue(int x)
{
   if (rear==Size-1) //rear is point to last element in the queue
       printf("queue overflow");
   else
   {
   rear=rear +1;
   queue[rear]=x;
   }
}
/*end of enqueue method*/
void dequeue()
{
  if (rear<front)
      printf("\n queue is empty");
      else
      {
      printf("\n %d is deleted",queue[front++]);
      }
}
/*end of dequeue method*/

void display()
{
   int i;
  if(rear<front)
      printf("\nqueue overflow");
  else
   for(i=front;i<=rear;i++)
   {
       printf("\n%d",queue[i]);
   }
}
/*end of display method*/
void main()
{
int ch;
int x;
init();

while(1)
{
//clrscr();
printf("\n----Queue operation---");
printf("\n1. enqueue element");
printf("\n2. dequeue element");
printf("\n3. Display the queue elements");
printf("\n4 .Exit");

printf("\n Enter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("\n Enter the elemets to be enqueued");
       scanf("%d",&x);
       enqueue(x);
       break;
       
case 2:dequeue();
       //getch();
       break;
       
case 3:display();     
       //getch();
       break;
       
case 4:exit(1);

default:printf("\n Wrong choice ");
        break;
}

}
}
