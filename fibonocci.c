#include <stdio.h>

// Function to print Fibonacci sequence up to n terms
void printFibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;
    int i;
    printf("Fibonacci Sequence: ");
    
    for (i = 1; i <= n; ++i) {
        printf("%d", t1);  // Print current term
        
        if (i < n) {
            printf(", ");  // Print comma only between terms
        }
        
        // Calculate the next term
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

int main() {
    int num;
    printf("Enter the number of terms: ");
    scanf("%d", &num);  // Read user input
    
    if (num <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printFibonacci(num);  // Print Fibonacci sequence
    }
    
    return 0;
}
