#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isPrime(int n) {
    if (n < 2) 
        return false;

    if (n == 2) 
        return true;

    if (n % 2 == 0) 
        return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

bool checkConcat(int a, int b) {
    char str1[20], str2[20], concat1[40], concat2[40];

    // Convert numbers to strings
    sprintf(str1, "%d", a);
    sprintf(str2, "%d", b);

    // Concat strings for start and end
    sprintf(concat1, "%s%s", str1, str2);
    sprintf(concat2, "%s%s", str2, str1);

    // convert string to number
    int num1 = atoi(concat1);
    int num2 = atoi(concat2);

    // Check if it makes a prime number
    return isPrime(num1) && isPrime(num2);
}

int findLowestPrimeSet() {
    const int limit = 10000;
    int primes[limit];
    int primeCount = 0;

    // Make list of primes to check later on
    for (int i = 0; i < limit; i++) {
        if (isPrime(i)) {
            primes[primeCount++] = i;
        }
    }

    // First prime number
    for (int i = 0; i < primeCount; i++) {

        // Second prime number
        for (int j = i + 1; j < primeCount; j++) {
            if (!checkConcat(primes[i], primes[j])){
                continue;
            }

            //Third prime number
            for (int k = j + 1; k < primeCount; k++) {
                if (!checkConcat(primes[i], primes[k]) ||
                    !checkConcat(primes[j], primes[k]))
                {
                    continue;
                }

                // Fourth prime number
                for (int l = k + 1; l < primeCount; l++) {
                    if (!checkConcat(primes[i], primes[l]) || 
                        !checkConcat(primes[j], primes[l]) || 
                        !checkConcat(primes[k], primes[l]))
                        {
                            continue;
                        }

                    // Fifth prime number
                    for (int m = l + 1; m < primeCount; m++) {
                        if (!checkConcat(primes[i], primes[m]) || 
                            !checkConcat(primes[j], primes[m]) || 
                            !checkConcat(primes[k], primes[m]) || 
                            !checkConcat(primes[l], primes[m]))
                            {
                                continue;
                            }

                        printf("Found primes: %d, %d, %d, %d, %d\n", primes[i], primes[j], primes[k], primes[l], primes[m]);
                        return primes[i] + primes[j] + primes[k] + primes[l] + primes[m];
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int result = findLowestPrimeSet();
    if (result != -1) {
        printf("Lowest sum: %d\n", result);
    } else {
        printf("None.\n");
    }
    return 0;
}