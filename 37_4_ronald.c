#include<stdio.h>
#include<string.h>
struct student{
    int rollno;
    char name[100];
    float p;
};
void main(){
    int i,j,t=0;
    printf("\nEnter the Student info: \n");
    for(i=0;i<5;i++){
        printf("Student No. %d\n",i+1);
        printf("Enter Roll No.");
        scanf("%d",&s[i].rollno);
        printf("Enter Name:");
        scanf("%s",&s[i].name);
        printf("Enter Percentage:");
        scanf("%f",&s[i].p);
    }
    for(i=0;i<5;i++){
        for(j=0;j<i+1;j++){
            if(s[i].rollno<s[j].rollno){
                t=s[i].rollno;
                s[i].rollno=s[j].rollno;
                s[j].rollno=t;
            }
        }
    }
    printf("Student List:\n");
    for(i=0;i<5;i++){
        printf("\nRoll No. : %d",s[i].rollno);
        printf("\nName: %s",s[i].name);
        printf("\nPercentage: %f",s[i].p);
    }
}