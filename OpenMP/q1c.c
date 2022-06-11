#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <math.h>
#include <string.h>

int Fprime(int n){
    omp_set_num_threads(8);

    int A[n];
    #pragma omp parallel for

    for (int i = 2; i < n; i++)
    {
        A[i]=i;
    }
    int rangeSQRT = (int) sqrt((double) n);
    #pragma omp parallel for schedule(guided,7)
    for (int i = 2; i < rangeSQRT; i++)
    {
        if(A[i]!=0){
            int j =0;
            j=i*i;
            while (j<=n)
            {
                A[j]=0;
                j=j+i;
            }
            
        }
    }

    int L[n];
    memset( L, 0, n*sizeof(int) );

    int i =0;
    #pragma omp parallel for

    for (int p = 2; p < n; p++)
    {
        if (A[p]!=0)
        {
            L[i]=A[p];
            i++;
        }
        
    }

    int maxq=0;
    #pragma omp parallel for reduction(max:maxq)

    for (int i = 0; i < n; i++)
    {
        if (maxq<L[i])
        {
            maxq=L[i];
        }
        
    }
    return maxq;
}


int main()
{
    double start, stop;

    FILE *f;
	f = fopen("par3.txt", "a");
    start = omp_get_wtime();

    int a = Fprime(5000);
    stop = omp_get_wtime();

    fprintf(f, "guided chunk 7\n");
    fprintf(f, "%f\n", stop - start);
    printf("%d",a);
    fclose(f);
    return 0;
}