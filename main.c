#include "prime.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
    // Task 1: Find the 1001st prime number
    int n =2*(1000 * log(1000));
    int numPrimes;
    int *primeValues;
    int limit = atoi(argv[1]);
    getPrimes(n, &numPrimes, &primeValues);

    // Print the 1001st prime number
    if (numPrimes >= 1001) {
        printf("prime 1001st: %d\n", primeValues[1000]);
    } else {
        printf("Not enough primes found.\n");
    }

    // Clean up allocated memory
    free(primeValues);

    // Task 2: Find the number of primes below the given limit
    int numPrimesBelow = countPrimesBelow(limit);
    printf("Number of primes below %d is: %d\n", limit, numPrimesBelow);

    // Task 3: Find the greatest product of five consecutive digits
    char *number =
        "73167176531330624919225119674426574742355349194934"
        "96983520312774506326239578318016984801869478851843"
        "85861560789112949495459501737958331952853208805511"
        "12540698747158523863050715693290963295227443043557"
        "66896648950445244523161731856403098711121722383113"
        "62229893423380308135336276614282806444486645238749"
        "30358907296290491560440772390713810515859307960866"
        "70172427121883998797908792274921901699720888093776"
        "65727333001053367881220235421809751254540594752243"
        "52584907711670556013604839586446706324415722155397"
        "53697817977846174064955149290862569321978468622482"
        "83972241375657056057490261407972968652414535100474"
        "82166370484403199890008895243450658541227588666881"
        "16427171479924442928230863465674813919123162824586"
        "17866458359124566529476545682848912883142607690042"
        "24219022671055626321111109370544217506941658960408"
        "07198403850962455444362981230987879927244284909188"
        "84580156166097919133875499200524063689912560717606"
        "05886116467109405077541002256983155200055935729725"
        "71636269561882670428252483600823257530420752963450";
    int product = greatestProductOfFiveDigits(number);
    printf("The greatest product of five consecutive digits is: %d\n", product);

    // Task 4: Find the sum of all multiples of 3 or 5 below a user-given number
    if (argc != 4) {
        printf("Usage: %s <limit> <number>\n", argv[0]);
        return 2;
    }

    int no = atoi(argv[2]);
    int sum = sumOfMultiples(no);
    printf("The sum of multiples of 3 or 5 below %d is: %d\n", no, sum);

    return 0;
}

