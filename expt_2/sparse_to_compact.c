#include <stdio.h>

#define MAX 10
#define MAX_NON_ZERO 101

void accept_matrix(int a[MAX][MAX], int m, int n)
{
    printf("Enter matrix elements:\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void compact(int sp[MAX_NON_ZERO][3], int a[MAX][MAX], int m, int n)
{
    int k = 1;

    
    sp[0][0] = m;
    sp[0][1] = n;

    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                sp[k][0] = i;
                sp[k][1] = j;
                sp[k][2] = a[i][j];

                k++;
            }
        }
    }

    
    sp[0][2] = k - 1;
}

void display(int sp[MAX_NON_ZERO][3])
{
    printf("\nRow\tColumn\tValue\n");

    for (int i = 0; i <= sp[0][2]; i++)
    {
        printf("%d\t%d\t%d\n",
               sp[i][0],
               sp[i][1],
               sp[i][2]);
    }
}

int main()
{
    int a[MAX][MAX];
    int sp[MAX_NON_ZERO][3];
    int m, n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    
    if (m <= 0 || m > MAX || n <= 0 || n > MAX)
    {
        printf("Invalid matrix size!\n");
        printf("Rows and columns must be between 1 and %d.\n", MAX);
        return 1;
    }

    accept_matrix(a, m, n);

    compact(sp, a, m, n);

    printf("\nCompact (Sparse) Matrix:\n");
    display(sp);

    return 0;
}