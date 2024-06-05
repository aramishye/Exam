/* 1. Write a program in C to calculate the difference between two weights using Structures.
Check the program with the following values:
10kg 100gr and 5kg 1800gr.

#include <stdio.h>

struct Weight {
    int kg;
    int grams;
};

void calculateWeightDifference(struct Weight w1, struct Weight w2, struct Weight *diff) {
    diff->kg = w1.kg - w2.kg;
    diff->grams = w1.grams - w2.grams;
    if (diff->grams < 0) {
        diff->grams += 1000;
        diff->kg--;
    }
}

int main() {
    struct Weight weight1 = {10, 100};
    struct Weight weight2 = {5, 1800};
    struct Weight weightDiff;

    calculateWeightDifference(weight1, weight2, &weightDiff);

    printf("Weight Difference: %d kg %d g\n", weightDiff.kg, weightDiff.grams);

    return 0;
}

2. Using #define preprocessor write Macros and use it.
circle_length

#include <stdio.h>
#define CIRCLE_LENGTH(radius) (2 * 3.1415 * (radius))

int main() {
    float radius;
    float circumference;

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    circumference = CIRCLE_LENGTH(radius);

    printf("Circumference of the circle with radius %.2f: %.2f\n", radius, circumference);

    return 0;
}

3. Using dynamic memory allocation create array of Students structure (size of array is 5)
And sort it according age in descending order. Then output data.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char first_name[10];
    char last_name[15];
    int age;
    int midtermExamGrade;
    int finalExamGrade;
};

int compareByAge(const void *a, const void *b) {
    return ((struct Student *)b)->age - ((struct Student *)a)->age;
}

int main() {
    int numStudents = 5;
    struct Student *students;

    students = (struct Student *)malloc(numStudents * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    strcpy(students[0].first_name, "John");
    strcpy(students[0].last_name, "Doe");
    students[0].age = 22;
    students[0].midtermExamGrade = 85;
    students[0].finalExamGrade = 90;

    qsort(students, numStudents, sizeof(struct Student), compareByAge);

    printf("Student data sorted by age (descending order):\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s %s, Age: %d, Midterm Grade: %d, Final Grade: %d\n",
               students[i].first_name, students[i].last_name,
               students[i].age, students[i].midtermExamGrade, students[i].finalExamGrade);
    }

    free(students);

    return 0;
}

4. The algorithm for calculating the value of the function F (n), where n is a natural number, is:
F(n<=1) = 1
F(n) = F(n–1) * (n + 4), n > 1
Write two functions – recursive and iterative (while loop)

#include <stdio.h>

// Recursive function to calculate F(n)
int recursiveF(int n) {
    if (n <= 1) {
        return 1;
    }
    return recursiveF(n - 1) * (n + 4);
}

int main() {
    int n = 5; // Example value of n

    printf("F(%d) = %d\n", n, recursiveF(n));

    return 0;
}

#include <stdio.h>

// Iterative function to calculate F(n)
int iterativeF(int n) {
    int result = 1;
    int i = 2; // Start from n = 2

    while (i <= n) {
        result *= (i + 4);
        i++;
    }

    return result;
}

int main() {
    int n = 5; // Example value of n

    printf("F(%d) = %d\n", n, iterativeF(n));

    return 0;
}

5. You have 2D array [5][4]. Please write program for finding column’s number with minimal sum of elements

#include <stdio.h>

int main() {
    int rows = 5;
    int cols = 4;
    int array[5][4] = {
        {10, 20, 30, 40},
        {5, 15, 25, 35},
        {8, 18, 28, 38},
        {12, 22, 32, 42},
        {7, 17, 27, 37}
    };

    int minSum = 0; // Initialize with the sum of the first column
    int minCol = 0; // Initialize with the first column number

    // Calculate the sum of the first column
    for (int i = 0; i < rows; i++) {
        minSum += array[i][0];
    }

    // Find the column with the minimal sum
    for (int j = 1; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += array[i][j];
        }
        if (colSum < minSum) {
            minSum = colSum;
            minCol = j;
        }
    }

    printf("Column with minimal sum: %d\n", minCol + 1); // Adding 1 to display column number

    return 0;
}

6. User enters the x and n= 1..3, which is number of action
Using switch construction, calculate and output the answer
1) -2x2-4;    2) 5x+2;    3) 15-3x.

#include <stdio.h>

int main() {
    double x;
    int n;
    double result;

    printf("Enter the value of x: ");
    scanf("%lf", &x);

    printf("Enter the action number (1, 2, or 3): ");
    scanf("%d", &n);

    switch (n) {
        case 1:
            result = -2 * x * x - 4;
            break;
        case 2:
            result = 5 * x + 2;
            break;
        case 3:
            result = 15 - 3 * x;
            break;
        default:
            printf("Invalid action number. Please choose 1, 2, or 3.\n");
            return 1;
    }

    printf("Result: %.2lf\n", result);

    return 0;
}

7. Find the maximum element with an even index in the array.

#include <stdio.h>

int main() {
    int arr[] = {10, 5, 20, 15, 30, 25}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array
    int maxElement = arr[0]; // Initialize with the first element

    // Iterate through even indices (starting from index 0)
    for (int i = 0; i < n; i += 2) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    printf("Maximum element with an even index: %d\n", maxElement);

    return 0;
}

8. Create Function using reference and use it inside of main
void circle_length (int *a)

#include <stdio.h>

// Function to calculate the circumference of a circle
void circle_length(int *radius) {
    // Assuming radius is non-negative
    double circumference = 2 * 3.1415 * (*radius);
    printf("Circumference of the circle with radius %d: %.2lf\n", *radius, circumference);
}

int main() {
    int radius;

    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);

    // Call the circle_length function
    circle_length(&radius);

    return 0;
}

9. Write a program to write an 1D array to a file

#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array

    // Open a file for writing
    FILE *file = fopen("array.txt", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Write array elements to the file
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    // Close the file
    fclose(file);

    printf("Array elements written to array.txt.\n");

    return 0;
}

*/