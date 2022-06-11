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
static void print(int start, int end, int tid);
void *thread_mult(void *arg);

int main()
{
    pthread_t pt[MAXTHREADS];
    int fg = SIZE;
    void *exit_status;
    double start, end;
    float diff;
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
    cout << "multiplying the matrices \n";


for (int j = 0; j < 1; j++)
{
    i = 0;
    while (i < MAXTHREADS)
    {
        if (rp = pthread_create(&pt[i], NULL, *thread_mult, (void *)i))
        {
            cout << "thread creation failed %d\n", i;
        }
        i++;
    }
    /* code */
}


    j = 0;
    while (j < MAXTHREADS)
    {
        pthread_join(pt[j], &exit_status);
        j++;
    }

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
    cout << "\nMATRIX C \n";
    i = 0;
    while (i < SIZE)
    {
        int j = 0;
        while (j < SIZE)
        {
            cout << " " << MAT_C[i][j];
            j++;
        }
        i++;
        cout << endl;
    }
    int x = 0;
    x = Simple_Matrix_Mult(MAT_A, MAT_B, MAT_C);
    if (x == 1)
    {
        cout << "It is Same Matrix";
    }
    else
    {
        cout << "Not same!";
    }
    return 0;
}

void *thread_mult(void *arg)
{
    int l,i, j, k;
    l = (intptr_t)arg;

    int rpt, end, start;
    rpt = (SIZE / MAXTHREADS)*4;
    start = l * (SIZE / MAXTHREADS)*4;
    end = start + (SIZE / MAXTHREADS)*4;
    cout << "Thread " << l << "created \n";
    i = start;
    while (i < end)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                MAT_C[i][j] =MAT_C[i][j]+ MAT_A[i][k] * MAT_B[k][j];
            }
        }
        i++;
    }
    print(start, end, l);
    return NULL;
}

void print(int start, int end, int tid)
{
    cout << "Thread " << tid << "printing the values \n";

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
    cout << "\nMATRIX D \n";
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
    i = 0;
    while (i < SIZE)
    {
        int j = 0;
        while (j < SIZE)
        {
            j++;
            if (res[i][j] != c[i][j])
            {
                //cout<<res[i][j]<<" "<<c[i][j];
                return 0;
            }
        }
        i++;
        return 1;
    }
}