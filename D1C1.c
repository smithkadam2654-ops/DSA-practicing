#include <stdio.h>
#include <string.h>

// Define a structure to store student details
struct Student {
    char name[50];
    int rollNo;
    float marks;
};


void displayTopper(struct Student students[], int count) {
    if (count <= 0) {
        printf("No student data available.\n");
        return;
    }

    int topperIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].marks > students[topperIndex].marks) {
            topperIndex = i;
        }
    }

    
    printf("Name   : %s\n", students[topperIndex].name);
    printf("Roll No: %d\n", students[topperIndex].rollNo);
    printf("Marks  : %.2f\n", students[topperIndex].marks);
}

int main() {
    int n;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    struct Student students[n];

   
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", students[i].name); 

        printf("Roll No: ");
        if (scanf("%d", &students[i].rollNo) != 1) {
            printf("Invalid roll number.\n");
            return 1;
        }

        printf("Marks: ");
        if (scanf("%f", &students[i].marks) != 1) {
            printf("Invalid marks.\n");
            return 1;
        }
    }

    displayTopper(students, n);

    return 0;
}
