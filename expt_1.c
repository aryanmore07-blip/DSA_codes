#include <stdio.h>

#define MAX 10

int main()
{
    int m, n, ch;
    int X[MAX][MAX], Y[MAX][MAX], Z[MAX][MAX];

    printf("Enter the number of rows (max %d): ", MAX);
    scanf("%d", &m);

    printf("Enter the number of columns (max %d): ", MAX);
    scanf("%d", &n);

    
    if (m <= 0 || m > MAX || n <= 0 || n > MAX)
    {
        printf("Invalid matrix size! Rows and columns must be between 1 and %d.\n", MAX);
        return 1;
    }

    
    printf("\nEnter the elements of Matrix 1:\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Element (%d,%d): ", i + 1, j + 1);
            scanf("%d", &X[i][j]);
        }
    }

    
    printf("\nEnter the elements of Matrix 2:\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Element (%d,%d): ", i + 1, j + 1);
            scanf("%d", &Y[i][j]);
        }
    }

    
    printf("\n----- MATRIX OPERATIONS -----\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication (Element-wise)\n");
    printf("4. Transpose of Matrix 1\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
            printf("\nAddition of Matrix:\n");

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Z[i][j] = X[i][j] + Y[i][j];
                    printf("%d ", Z[i][j]);
                }
                printf("\n");
            }
            break;

        case 2:
            printf("\nSubtraction of Matrix:\n");

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Z[i][j] = X[i][j] - Y[i][j];
                    printf("%d ", Z[i][j]);
                }
                printf("\n");
            }
            break;

        case 3:
            printf("\nElement-wise Multiplication:\n");

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Z[i][j] = X[i][j] * Y[i][j];
                    printf("%d ", Z[i][j]);
                }
                printf("\n");
            }
            break;

        case 4:
            printf("\nOriginal Matrix (Matrix 1):\n");

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%d ", X[i][j]);
                }
                printf("\n");
            }

            printf("\nTranspose of Matrix 1:\n");

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    printf("%d ", X[j][i]);
                }
                printf("\n");
            }
            break;

        default:
            printf("\nInvalid Choice!\n");
    }

    return 0;
}