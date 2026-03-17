#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char queue[100];
    int front = 0, rear = -1;

    printf("Enter string: ");
    scanf("%s", str);

    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        rear++;
        queue[rear] = str[i];
    }

    int flag = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] != queue[front])
        {
            flag = 0;
            break;
        }
        front++;
    }

    if (flag)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}