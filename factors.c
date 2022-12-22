#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // Check the number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: factors <file>\n");
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    // Read and factorize each number

    int n;
    while (fscanf(file, "%d", &n) == 1) {

        // Check if n is prime

        int is_prime = 1;
        for (int i = 2; i < n/2+1; i++) {
            if (n % i == 0) {

                // Found a factor, n is not prime
                is_prime = 0;
                printf("%d=%d*%d\n", n, i, n/i);
                break;
            }
        }
        if (is_prime) {
            printf("%d is prime\n", n);
        }
    }

    // Close the file

    fclose(file);

    return 0;

}

