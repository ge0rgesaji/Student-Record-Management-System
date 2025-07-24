#include <stdio.h>
#include "Student.h"
#include "Student.c"
int main(){
    int ch,rollno;
    do
    {
        printf("\n------------------------STUDENT RECORD MANAGEMENT SYSTEM------------------------\n");
        printf("1.Add Student\n");
        printf("2.View all Students\n");
        printf("3.Search Student\n");
        printf("4.Delete Student\n");
        printf("0.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
            case 0:
            printf("Exiting");
            printf("\nThank you! Have a nice day");
            break;
            case 1:
            addstud();
            break;
            case 2:
            viewstud();
            break;
            case 3:
            printf("Enter the Roll no:");
            scanf("%d",&rollno);
            searchstud(rollno);
            break;
            case 4:
            printf("Enter the Roll no:");
            scanf("%d",&rollno);
            delstud(rollno);
            break;     
            default:
            printf("Invaild Input!Please try again");
            break;
        }
    }while(ch !=0); 
    return  0;
} 