/* Implementation of circular queue using array in C */

#include<stdio.h>
#include<stdlib.h>
# define N 5  //N = Maximum Size of the Q 
int cq[N];   //cq = Circular Queue
int front=-1;  
int rear=-1; 

void enqueue(int item);
int dequeue();
int isEmpty();
int isFull();

void enqueue(int item)  
{  
    if(isFull())  
    {  
        printf("Queue Overflow\n");
        exit(1);
    }
    if(front == -1){
        front=0;  
    }  
    rear=(rear+1)%N;       // rear is incremented  
    cq[rear]=item;     // assigning a value to the queue at the rear position.  
} 
  
int dequeue()  
{  
    int deleted_item;
    if(isEmpty()) 
    {  
        printf("Queue Underflow\n");  
	    exit(1);		 // To show Failure Exit. 
    }  
    deleted_item = cq[front];
    if(front==rear)  // cq has only 1 element
    { 
       front=-1;  
       rear=-1;  
    }   
    else  
    {  
       front = (front + 1)%N;
    }  
    
    return deleted_item;
}  

int isEmpty(){
    return ( (front == -1) ? 1 : 0); 
}

int isFull(){
    return ( ( (rear + 1)%N == front) ? 1 : 0); 
}

void display()  
{  
    int i;
    if(isEmpty())  
    {  
        printf("Queue Underflow\n.");  
	return;
    }  
   i = front;
        if(front < rear){
            while(i<=rear)  
            {  
                printf("%d,", cq[i]);  
                i=i+1;  
            }
        }
        else{
            while(i != rear)  
            {  
                printf("%d,", cq[i]);  
                i=(i+1)%N;  
            }
            printf("%d,", cq[i]);
        }
    
}  

int main()  
{
    // Insert elements : 42, 66, 35, 59, 17
    enqueue(42);
    enqueue(66);
    enqueue(35);
    enqueue(59);
    enqueue(17);
    display();
    // Delete first 2 elements
    printf("Deleted Element is: %d\n",dequeue());
    printf("Deleted Element is: %d\n",dequeue());
    display();
    // Insert 10
    enqueue(10);
    display();
    return 0;  
} 
