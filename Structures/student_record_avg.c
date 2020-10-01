/* Author: Shreeyans Bahadkar */

/* Create a student record with name, roll no, marks of 3 subjects (m1, m2, m3). Display the details of the students in ascending order of their average marks. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student_record {
    char name[25];
    int rollno;
    int sub_marks[3];
    float avg_marks;
}stud[100],temp;

void get_data(struct student_record s[], int n);
void calc_avg_marks(struct student_record s[], int n);

void main() {
    // Code to input records
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    system("cls");
    for (int i = 0; i < n; i++)
    {
        printf("---------------------------\nInput details for Student %d\n---------------------------\n", i+1);
        get_data(stud, i);
        calc_avg_marks(stud, i);
    }
    
    // Code to sort structure variables according to average marks

    for(int i=0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(stud[i].avg_marks > stud[i+1].avg_marks)
            {
                temp = stud[i];
                stud[i] = stud[i+1];
                stud[i+1] = temp;
            }
        }
    }
    
    // Code to display records

    for (int i = 0; i < n; i++) {
        printf("----------------------Details of Student %d----------------------\n", i+1);
        printf("Name: %s\n", stud[i].name);
        printf("Roll No: %d\n", stud[i].rollno);
        for(int j = 0; j < 3; j++) {
            printf("Marks in Subject %d: %d\n", j+1, stud[i].sub_marks[j]);
        }
        printf("\n");
    }


}

void get_data(struct student_record s[], int n) {

    printf("Enter name of Student: \n");
    getchar();
    gets(s[n].name);
    printf("Enter roll number of Student: \n");
    scanf("%d", &s[n].rollno);
    for(int j=0; j<3;j++) {
        printf("Enter marks in Subject %d: \n", j+1);
        scanf("%d", &s[n].sub_marks[j]);
    }
    system("cls");
}

void calc_avg_marks(struct student_record s[], int n) {
    s[n].avg_marks = (s[n].sub_marks[0] + s[n].sub_marks[1] + s[n].sub_marks[2])/3;
}

