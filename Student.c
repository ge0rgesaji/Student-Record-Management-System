#include <stdio.h>
#include "Student.h"
#include <string.h>
void addstud(){
  FILE *fptr =fopen("Stud.dat","ab");
  if(!fptr){
    printf("Data file not found");
    return;
  }
  Stud s;
  printf("Enter the Roll no:");
  scanf("%d",&s.rollno);
  getchar();   // Clear input buffer
  printf("Enter the Student's first name: ");
  fgets(s.fname, sizeof(s.fname), stdin); // Remove newline
  s.fname[strcspn(s.fname, "\n")] = '\0'; 
  printf("Enter the Student's last name: ");
  fgets(s.lname, sizeof(s.lname), stdin); 
  s.lname[strcspn(s.lname, "\n")] = '\0'; 
  printf("Enter the Course: ");
  fgets(s.course, sizeof(s.course), stdin);
  s.course[strcspn(s.course, "\n")] = '\0';
  printf("Enter the Marks:");
  scanf("%f",&s.mark);
  fwrite(&s,sizeof(Stud),1,fptr);
  fclose(fptr);
  printf("Student added Successfully");
}
void viewstud(){
  FILE *fptr=fopen("Stud.dat","rb");
  if(!fptr){
    printf("File not found");
    return;
  }
  Stud s;
    printf("\n%-10s %-10s %-10s %-10s %-10s\n", "RollNo", "First-Name", "Last-Name", "Course", "Marks");
    printf("----------------------------------------------------------\n");
    while (fread(&s, sizeof(Stud), 1, fptr)) {
        printf("%-10d %-10s %-10s %-10s %-10.2f\n", s.rollno, s.fname, s.lname, s.course, s.mark);
    }
    fclose(fptr);
}
void searchstud(int rollno) {
    FILE *fptr = fopen("Stud.dat", "rb");
    if (!fptr) {
        printf("File not found!\n");
        return;
    }
    Stud s;
    int found = 0;
    while (fread(&s, sizeof(Stud), 1, fptr)) {
        if (s.rollno == rollno) {
            printf("Student found!\n");
            printf("Roll No:%d First-Name:%s Last-Name:%s Course:%s Marks:%.2f\n", s.rollno, s.fname, s.lname, s.course, s.mark);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Roll No %d not found.\n", rollno);
    }

    fclose(fptr);
}
void delstud(int rollno) {
    FILE *fptr= fopen("Stud.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!fptr || !temp) {
        printf("Error opening file!\n");
        return;
    }

    Stud s;
    int deleted = 0;
    while (fread(&s, sizeof(Stud), 1, fptr)) { //Reading all data from data file expect specified roll no
        if (s.rollno != rollno) {
            fwrite(&s, sizeof(Stud), 1, temp); //Writing to a temp file 
        } else {
            deleted = 1;
        }
    }

    fclose(fptr);
    fclose(temp);
    remove("Stud.dat"); //removing data file 
    rename("temp.dat", "Stud.dat"); //renaming temp file to same name as data file

    if (deleted)
        printf("Student deleted successfully.\n");
    else
        printf("Student not found.\n");
}
