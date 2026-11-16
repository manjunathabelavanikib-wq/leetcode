
#include <stdbool.h>

bool isPalindrome(int x) {
    
    // Negative numbers are not palindromes
    if (x < 0) {
        return false;
    }

    int original = x;
    long reversed = 0;

    // Reverse the number
    while (x > 0) {
        int digit = x % 10;

        reversed = reversed * 10 + digit;

        x = x / 10;
    }

    // Compare original and reversed numbers
    if (original == reversed) {
        return true;
    } else {
        return false;
    }
}

