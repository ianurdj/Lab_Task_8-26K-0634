
#include <stdio.h>
#include <string.h>

void read(int *m1, int *m2, int *m3) {

    do {
        printf("Enter marks of Subject 1 (0-100): ");
        scanf("%d", m1);
    } while (*m1 < 0 || *m1 > 100);

    do {
        printf("Enter marks of Subject 2 (0-100): ");
        scanf("%d", m2);
    } while (*m2 < 0 || *m2 > 100);

    do {
        printf("Enter marks of Subject 3 (0-100): ");
        scanf("%d", m3);
    } while (*m3 < 0 || *m3 > 100);
}

void cal(int m1, int m2, int m3, int *total, double *avg, int *highest, int *lowest)
 {

    *total = m1 + m2 + m3;
    *avg = (double)*total / 3;

    *highest = m1;
    *lowest = m1;

    if (m2 > *highest)
        *highest = m2;

    if (m3 > *highest)
        *highest = m3;

    if (m2 < *lowest)
        *lowest = m2;

    if (m3 < *lowest)
        *lowest = m3;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void getgrace(int *mark, int grace) {

    if (*mark >= 35 && *mark <= 39) {
        *mark += grace;
    }
}

void findgrade(double avg, char *grade, char *remarks) {

    if (avg >= 80) {
        *grade = 'A';
        strcpy(remarks, "Excellent");
    }
    else if (avg >= 70) {
        *grade = 'B';
        strcpy(remarks, "Good");
    }
    else if (avg >= 50) {
        *grade = 'C';
        strcpy(remarks, "Good");
    }
    else {
        *grade = 'F';
        strcpy(remarks, "Needs Improvement");
    }
}

void value(int x) {
    x++;
}

void ref(int *x) {
    (*x)++;
}

int main() {

    int m1, m2, m3;
    int total, highest, lowest;
    int grace;
    double average;

    char grade;
    char remarks[30];

    for (int i = 1; i <= 5; i++) {

        printf("\n===== STUDENT %d =====\n", i);

        read(&m1, &m2, &m3);

        printf("\nEnter grace marks (0-5): ");
        scanf("%d", &grace);

        while (grace < 0 || grace > 5) {
            printf("Enter grace marks between 0 and 5: ");
            scanf("%d", &grace);
        }

        getgrace(&m1, grace);
        getgrace(&m2, grace);
        getgrace(&m3, grace);

        cal(m1, m2, m3, &total, &average, &highest, &lowest);

        if (m1 < m2)
            swap(&m1, &m2);

        if (m1 < m3)
            swap(&m1, &m3);

        if (m2 < m3)
            swap(&m2, &m3);

        findgrade(average, &grade, remarks);

        printf("\nSorted Marks: %d %d %d\n", m1, m2, m3);

        printf("Total: %d\n", total);
        printf("Average: %.2lf\n", average);
        printf("Highest: %d\n", highest);
        printf("Lowest: %d\n", lowest);
        printf("Grade: %c\n", grade);
        printf("Remarks: %s\n", remarks);
    }

    printf("\n===== INCREMENT COMPARISON =====\n");

    int num = 10;

    printf("Original Value: %d", num);

    value(num);

    printf("After incrementByValue: %d", num);

    ref(&num);
    printf("After ref: %d", num);

  
    return 0;
}
