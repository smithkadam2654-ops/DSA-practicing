#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNo;
    float marks;
};


void displayTopper(struct Student students[], int count) {
    if (count <= 0) {
        printf("No students to evaluate.\n");
        return;
    }

    int topperIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].marks > students[topperIndex].marks) {
            topperIndex = i;
        }
    }

    printf("\n--- Topper Details ---\n");
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
    getchar(); 

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Name: ");
        if (fgets(students[i].name, sizeof(students[i].name), stdin) != NULL) {
            students[i].name[strcspn(students[i].name, "\n")] = '\0'; 
        }

        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
        getchar(); 
    }

    displayTopper(students, n);

    return 0;
}
