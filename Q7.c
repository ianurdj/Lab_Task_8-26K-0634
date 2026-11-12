#include <stdio.h>


int findMax(int *p, int n) {
    int max = *p;

    for (int i = 1; i < n; i++) {
        if (*(p + i) > max) {
            max = *(p + i);
        }
    }

    return max;
}

int findMin(int *p, int n) {
    int min = *p;

    for (int i = 1; i < n; i++) {
        if (*(p + i) < min) {
            min = *(p + i);
        }
    }

    return min;
}

double findAverage(int *p, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += *(p + i);
    }

    return (double)sum / n;
}

int countAbove(int *p, int n, double avg) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (*(p + i) > avg) {
            count++;
        }
    }

    return count;
}

void reverseArray(int *p, int n) {
    int *start = p;
    int *end = p + n - 1;
    int temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int searchMark(int *p, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (*(p + i) == key) {
            return i + 1;
        }
    }

    return -1;
}

int main() {
    int marks[10];
    int key, pass = 0;

    printf("Enter marks of 10 students:\n");

    for (int i = 0; i < 10; i++) {
        do {
            printf("Student %d: ", i + 1);
            scanf("%d", &marks[i]);

            if (marks[i] < 0 || marks[i] > 100) {
                printf("Invalid marks! Enter between 0 and 100.\n");
            }

        } while (marks[i] < 0 || marks[i] > 100);
    }

    printf("\nOriginal Marks:\n");

    for (int i = 0; i < 10; i++) {
        printf("%d ", marks[i]);

        if (marks[i] >= 40) {
            pass++;
        }
    }

    double avg = findAverage(marks, 10);

    printf("\n\nHighest Marks: %d", findMax(marks, 10));
    printf("\nLowest Marks: %d", findMin(marks, 10));
    printf("\nAverage Marks: %.2lf", avg);
    printf("\nStudents Above Average: %d", countAbove(marks, 10, avg));
    printf("\nStudents Passed: %d", pass);

    printf("\n\nEnter marks to search: ");
    scanf("%d", &key);

    int position = searchMark(marks, 10, key);

    if (position == -1) {
        printf("Marks not found.");
    }
    else {
        printf("Marks found at position %d.", position);
    }

    reverseArray(marks, 10);

    printf("\n\nMarks in Reverse Order:\n");

    for (int i = 0; i < 10; i++) {
        printf("%d ", marks[i]);
    }

    return 0;
}
