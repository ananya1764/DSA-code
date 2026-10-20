#include <stdio.h>

// Function to input sparse matrix
void inputSparse(int a[10][10], int r, int c)
{
    int i, j;

    printf("Enter the elements of the sparse matrix:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to display any matrix
void display(int a[10][10], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

// Function to convert sparse matrix into compact form
void compact(int a[10][10], int b[10][10], int r, int c)
{
    int i, j, k = 1;

    b[0][0] = r;
    b[0][1] = c;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }

    b[0][2] = k - 1;
}

// Function for Simple Transpose
void simpleTranspose(int a[10][10], int t[10][10])
{
    int i, j, k = 1;

    t[0][0] = a[0][1];
    t[0][1] = a[0][0];
    t[0][2] = a[0][2];

    for(i = 0; i < a[0][1]; i++)
    {
        for(j = 1; j <= a[0][2]; j++)
        {
            if(a[j][1] == i)
            {
                t[k][0] = a[j][1];
                t[k][1] = a[j][0];
                t[k][2] = a[j][2];
                k++;
            }
        }
    }
}

// Function for Fast Transpose
void fastTranspose(int a[10][10], int t[10][10])
{
    int count[10] = {0};
    int startPos[10] = {0};
    int i, col, pos;

    t[0][0] = a[0][1];
    t[0][1] = a[0][0];
    t[0][2] = a[0][2];

    // Count number of elements in each column
    for(i = 1; i <= a[0][2]; i++)
    {
        count[a[i][1]]++;
    }

    // Calculate starting position
    startPos[0] = 1;
    for(i = 1; i < a[0][1]; i++)
    {
        startPos[i] = startPos[i - 1] + count[i - 1];
    }

    // Place elements in transpose
    for(i = 1; i <= a[0][2]; i++)
    {
        col = a[i][1];
        pos = startPos[col];

        t[pos][0] = a[i][1];
        t[pos][1] = a[i][0];
        t[pos][2] = a[i][2];

        startPos[col]++;
    }
}

int main()
{
    int a[10][10], b[10][10], t[10][10];
    int r, c, choice;

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);

    inputSparse(a, r, c);

    printf("\nOriginal Matrix:\n");
    display(a, r, c);

    compact(a, b, r, c);

    printf("\nCompact Matrix:\n");
    display(b, b[0][2] + 1, 3);

    printf("\n1. Simple Transpose\n");
    printf("2. Fast Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        simpleTranspose(b, t);
        printf("\nSimple Transpose:\n");
        display(t, t[0][2] + 1, 3);
    }
    else if(choice == 2)
    {
        fastTranspose(b, t);
        printf("\nFast Transpose:\n");
        display(t, t[0][2] + 1, 3);
    }
    else
    {
        printf("Invalid Choice\n");
    }

    return 0;
}
