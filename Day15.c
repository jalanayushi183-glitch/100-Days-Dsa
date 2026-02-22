// Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

// Input:
// - First line: two integers m and n
// - Next m lines: n integers each

// Output:
// - Print the sum of the primary diagonal elements

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 15

// Explanation:
// 1 + 5 + 9 = 15
#include <stdio.h>

int main() {
    int m, n, i, j;
    int sum = 0;

    printf("Enter number of rows and columns (m n): ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter elements of the matrix (%d x %d):\n", m, n);
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of primary diagonal elements: %d\n", sum);

    return 0;
}