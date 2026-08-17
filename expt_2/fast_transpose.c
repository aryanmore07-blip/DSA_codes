#include <stdio.h>

void accept_matrix(int a[10][10], int m, int n)
{
    printf("Enter matrix elements:\n");

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void compact(int sp[20][3], int a[10][10], int m, int n)
{
    int k = 1;

    sp[0][0] = m;
    sp[0][1] = n;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] != 0)
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

void display(int sp[20][3])
{
    printf("\nRow\tCol\tValue\n");

    for(int i = 0; i <= sp[0][2]; i++)
    {
        printf("%d\t%d\t%d\n",
               sp[i][0],
               sp[i][1],
               sp[i][2]);
    }
}

void fastTranspose(int sp[20][3], int tr[20][3])
{
    int rows, cols, terms;

    rows = sp[0][0];
    cols = sp[0][1];
    terms = sp[0][2];

    
    tr[0][0] = cols;
    tr[0][1] = rows;
    tr[0][2] = terms;

    if(terms == 0)
        return;

    int rowTerms[10] = {0};
    int startingPos[10];


    for(int i = 1; i <= terms; i++)
    {
        rowTerms[sp[i][1]]++;
    }

    
    startingPos[0] = 1;

    for(int i = 1; i < cols; i++)
    {
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    
    for(int i = 1; i <= terms; i++)
    {
        int col = sp[i][1];
        int pos = startingPos[col];

        tr[pos][0] = sp[i][1];
        tr[pos][1] = sp[i][0];
        tr[pos][2] = sp[i][2];

        startingPos[col]++;
    }
}

int main()
{
    int a[10][10];
    int sp[20][3], tr[20][3];
    int m, n;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    accept_matrix(a, m, n);

    compact(sp, a, m, n);

    printf("\nSparse Matrix:");
    display(sp);

    fastTranspose(sp, tr);

    printf("\nFast Transpose of Sparse Matrix:");
    display(tr);

    return 0;
}