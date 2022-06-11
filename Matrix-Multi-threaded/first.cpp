#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
#define SIZE 4
#define MAXTHREADS 2

int MAT_A[SIZE][SIZE];
int MAT_B[SIZE][SIZE];
long int MAT_C[SIZE][SIZE];
long int MAT_D[SIZE][SIZE];
int Simple_Matrix_Mult(int mat1[][SIZE], int mat2[][SIZE], long int c[][SIZE]);

int main()
{   float diff;
    int i, rp, j;
    cout << "Filling the values";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            MAT_A[i][j] = rand() % 9 + 1;
            MAT_B[i][j] = rand() % 9 + 1;
            MAT_C[i][j] = 0;
        }
    }
//    cout << "multiplying the matrices \n";
    cout << "\nMATRIX A \n";
    i = 0;
    while (i < SIZE)
    {
        int j = 0;
        while (j < SIZE)
        {
            cout << " " << MAT_A[i][j];
            j++;
        }
        cout << endl;
        i++;
    }

    cout << "\nMATRIX B \n";
    i = 0;
    while (i < SIZE)
    {
        int j = 0;
        while (j < SIZE)
        {
            cout << " " << MAT_B[i][j];
            j++;
        }
        cout << endl;
        i++;
    }
    int x = 0;
    x = Simple_Matrix_Mult(MAT_A, MAT_B, MAT_C);

}

int Simple_Matrix_Mult(int mat1[][SIZE], int mat2[][SIZE], long int c[][SIZE])
{
    int i, j, k;
    long int res[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            res[i][j] = 0;
        }
    }
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < SIZE; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    cout << "\nMATRIX C\n";
    i = 0;
    while (i < SIZE)
    {
        int j = 0;
        while (j < SIZE)
        {
            cout << " " << res[i][j];
            j++;
        }
        i++;
        cout << endl;
    }

    
}