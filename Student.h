#ifndef STUDENT_H
#define STUDENT_H
   typedef struct {
    int rollno;
    char fname[25];
    char lname[25];
    float mark;
    char course[30];
} Stud;  
void addstud();
void viewstud();
void searchstud(int rollno);
void delstud(int rollno);
#endif