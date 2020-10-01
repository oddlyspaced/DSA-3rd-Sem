/* Author: Shreeyans Bahadkar */

/* Create an array of student structure to store the roll no, name and marks in 3 subjects. Input the details of N students into the array and display the name and % of marks for the first two toppers [Sorting not allowed] */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct student_record {
    char name[25];
    int rollno;
    float sub_marks[3];
    float percentage;
}stud[100];


void get_data(struct student_record s[], int n);
void calc_percentage (struct student_record s[], int n);
void display_data (struct student_record s[], int n);


void main() {
    int max1=0,max2=0; // Variables for percentage comparison
    int max_loc_1=0,max_loc_2=0;  // Location of toppers in stud[100]
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Code to input records
    system("cls");

    // Code to input student records
    for (int i = 0; i < n; i++)
    {
        printf("---------------------------\nInput details for Student %d\n---------------------------\n", i+1);
        get_data(stud, i);
        calc_percentage(stud, i);
    }

    // Code to calculate toppers
    for (int i = 0; i < n; i++)
    {
        if (max1 < stud[i].percentage)
        {
            max1 = stud[i].percentage;
            max_loc_1 = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if ((max2 < stud[i].percentage) && (i != max_loc_1))
        {
            max2 = stud[i].percentage;
            max_loc_2 = i;
        }
    }
    
    // Code to display toppers
    system("cls");
    printf("-----------------Topper 1-----------------\n");
    display_data(stud, max_loc_1);
    printf("-----------------Topper 2-----------------\n");
    display_data(stud, max_loc_2);


}


void get_data(struct student_record s[], int n) {

    printf("Enter name of Student: \n");
    getchar();
    gets(s[n].name);
    printf("Enter roll number of Student: \n");
    scanf("%d", &s[n].rollno);
    for(int j=0; j<3;j++) {
        printf("Enter marks in Subject %d out of 20: \n", j+1);
        scanf("%f", &s[n].sub_marks[j]);
    }
    system("cls");
}

void calc_percentage (struct student_record s[], int n) {
    s[n].percentage = (s[n].sub_marks[0] + s[n].sub_marks[1] + s[n].sub_marks[2])/60*100;
}


void display_data (struct student_record s[], int n) {
    printf("Name: %s\n", s[n].name);
    printf("Percentage: %.2f %%\n", s[n].percentage);
}

