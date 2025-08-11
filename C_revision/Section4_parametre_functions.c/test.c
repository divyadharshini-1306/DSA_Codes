#include <stdio.h>

void printBinary(int n) {
    // Determine the number of bits in an int (e.g., 32 for a typical system)
    int numBits = sizeof(int) * 8; 

    // Iterate from the most significant bit to the least significant bit
    for (int i = numBits - 1; i >= 0; i--) {
        // Check if the i-th bit is set
        if ((n >> i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n"); // Print a newline after the binary representation
}

int main() {
    int decimalNum = 13;
    printf("Decimal: %d, Binary: ", decimalNum);
    printBinary(decimalNum);

    int anotherNum = 255;
    printf("Decimal: %d, Binary: ", anotherNum);
    printBinary(anotherNum);

    return 0;
}