// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int left, right;
    int isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    left = 0;
    right = strlen(str) - 1;

    while(left < right) {
        if(str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if(isPalindrome)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}