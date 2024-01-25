#include "prime.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void markMultiples(int *numbers, int n, int prime) {
    for (int i = 2 * prime; i <= n; i += prime) {
        numbers[i - 1] = -1;
    }
}

void getPrimes(int limit, int *numPrimes, int **primeValues) {
    int *numbers =  (int *)malloc(limit * sizeof(int)) ;

    if (numbers == NULL) {
        printf("they are no numbers\n");
        exit(1);
    }

    for (int i = 0; i < limit; ++i) {
        numbers[i] = i + 1;
    }

    numbers[0] = -1;

    int k = 2;
    while (k <= sqrt(limit)) {
        int m;
        for (m = k + 1; m <= limit && numbers[m - 1] == -1; ++m) {
        }

        markMultiples(numbers, limit, m);

        k = m;
    }

    *numPrimes = 0;
    for (int i = 2; i <= limit; ++i) {
        if (numbers[i - 1] != -1) {
            (*numPrimes)++;
        }
    }

    *primeValues = (int *)malloc((*numPrimes) * sizeof(int));

    int index = 0;
    for (int i = 2; i <= limit; ++i) {
        if (numbers[i - 1] != -1) {
            (*primeValues)[index++] = i;
        }
    }

    
}

int countPrimesBelow(int limit) {
    int numPrimes;
    int *primeArray;

    getPrimes(limit, &numPrimes, &primeArray);

    free(primeArray);

    return numPrimes;
}

int greatestProductOfFiveDigits(char *number) {
    int maxProduct = 0;

    for (int i = 0; i < 1000 - 4; ++i) {
        int product = 1;
        for (int j = 0; j < 5; ++j) {
            product *= number[i + j] - '0';
        }

        if (product > maxProduct) {
            maxProduct = product;
        }
    }

    return maxProduct;
}

int sumOfMultiples(int limit) {
    int sum = 0;

    for (int i = 0; i < limit; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    return sum;
}

