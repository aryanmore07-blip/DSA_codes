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

void transpose(int sp[MAX_NON_ZERO][3],
               int tr[MAX_NON_ZERO][3])
{
    int rows = sp[0][0];
    int cols = sp[0][1];
    int non_zero = sp[0][2];

    int q = 1;

    
    tr[0][0] = cols;
    tr[0][1] = rows;
    tr[0][2] = non_zero;

    
    for (int col = 0; col < cols; col++)
    {
        for (int p = 1; p <= non_zero; p++)
        {
            if (sp[p][1] == col)
            {
                tr[q][0] = sp[p][1];
                tr[q][1] = sp[p][0];
                tr[q][2] = sp[p][2];

                q++;
            }
        }
    }
}

int main()
{
    int a[MAX][MAX];
    int sp[MAX_NON_ZERO][3];
    int tr[MAX_NON_ZERO][3];

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

    
    printf("\nSparse Matrix:\n");
    display(sp);

    
    transpose(sp, tr);

    
    printf("\nTranspose of Sparse Matrix:\n");
    display(tr);

    return 0;
}