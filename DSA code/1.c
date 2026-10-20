#include <stdio.h>

void addition(int r, int c, int A[r][c], int B[r][c], int result[r][c]);
void subtraction(int r, int c, int A[r][c], int B[r][c], int result[r][c]);
void multiplication(int r, int c, int A[r][c], int B[r][c], int result[r][c]);
void transpose (int c,int r,int matrix_A[r][c], int result[r][c]) ;

int main() {
    int  r,c,i,j;

     printf("enetr no of rows and columns");
    scanf("%d %d" , &r, &c);
    
    int matrix_A[r][c];
    int matrix_B[r][c];
    int result[r][c];
    int choice;


    //MENU
    printf("choose operation from menu \n");
    printf("1 Addition \n");
    printf("2 subtraction \n");
    printf("3 multiplication \n");
    printf("4 transpose \n");
    printf("0 exit \n");

    scanf("%d", &choice);

   

    // take matrix iput and print matrix

    printf("enter matrix A elements ") ;
    for (i=0 ; i<r;i++) {
        for ( j=0;j<c;j++) {
            scanf("%d", &matrix_A[i][j]);
        }
    }

    printf("matrix A: ");
    for (i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            printf("%d", matrix_A[i][j]);
        }
    }

    printf("enter matrix B elements ") ;
    for (i=0 ; i<r;i++) {
        for ( j=0;j<c;j++) {
            scanf("%d", &matrix_B[i][j]);
        }
    }

    printf("matrix B: ");
    for (i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            printf("%d", matrix_B[i][j]);
        }
    }

    switch (choice)
    { 
        case 1:
        addition(r,c,matrix_A,matrix_B,result);
        break;

        case 2:
        subtraction(r,c,matrix_A,matrix_B,result);
        break;

        case 3:
        multiplication(r,c,matrix_A,matrix_B,result);
        break;

        case 4:
        transpose(r,c,matrix_A,result);
        break;

        case 0:
        printf("%s,exit \n");
        break;

    }


    
return 0;
}

void addition(int c,int r,int matrix_A[r][c], int matrix_B[r][c], int result[r][c]) {
    int i,j;
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            result[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }

    }
}

void subtraction(int c,int r,int matrix_A[r][c], int matrix_B[r][c], int result[r][c]) {
    int i,j;
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            result[i][j] = matrix_A[i][j] - matrix_B[i][j];
        }

    }
}

void multiplication(int c,int r,int matrix_A[r][c], int matrix_B[r][c], int result[r][c]) {
    int i,j;
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            result[i][j]=0;

            for(int k=0 ; k<c;k++) {
                 result[i][j] += matrix_A[i][j] * matrix_B[i][j];
            }

        }
    }
}

void transpose (int c,int r,int matrix_A[r][c], int result[r][c]) {
    for(int i=0;i<r;i++) {
        for(int j=0; j< c;j++) {
            result[j][i] = matrix_A[i][j];
        }
    }
}

void display(int r,int c,int result[r][c]) {
    for (int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            printf("%d",result[i][j]);
        }
    }
}
