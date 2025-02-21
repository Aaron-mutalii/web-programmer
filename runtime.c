//EB3/61607/22
#include <stdio.h>
#include <time.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

unsigned long long fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

unsigned long long fibonacci_memo(int n, unsigned long long memo[]) {
    if (memo[n] != 0) {
        return memo[n];
    }
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        memo[n] = fibonacci_memo(n - 1, memo) + fibonacci_memo(n - 2, memo);
        return memo[n];
    }
}

int main() {
    int number = 20;
    int i ;
    unsigned long long result;
    unsigned long long memo[number + 1];
    for (i = 0; i <= number; i++) {
        memo[i] = 0;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    result = factorial(number);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Factorial of %d: %llu, Time: %f seconds\n", number, result, cpu_time_used);

    start = clock();
    result = fibonacci(number);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Fibonacci of %d: %llu, Time: %f seconds (Naive)\n", number, result, cpu_time_used);

    start = clock();
    result = fibonacci_memo(number, memo);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Fibonacci of %d: %llu, Time: %f seconds (Memoized)\n", number, result, cpu_time_used);

    return 0;
}
