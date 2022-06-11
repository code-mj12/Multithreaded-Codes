#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <math.h>



int findprimef(int range)
{
    omp_set_num_threads(8);


    int primes[range];

    #pragma omp parallel for
    for (int i = 2; i < range; i++)
        primes[i] = 1;
    
    int rangeSQRT = (int) sqrt((double) range);

    #pragma omp parallel for schedule(guided,7)
    for (int i = 2; i < rangeSQRT; i += 1){
        if (primes[i] == 1){
            for (int j = i * i; j < range; j += i){
                primes[j] = 0;
                }
            }
      }

    int res = 0;
    #pragma omp parallel for reduction(max:res)
    for (int i = 2; i < range; i++){
        
        if(primes[i]==1){
           res = i;
           // printf("%d ",i);
            }
    }


    return res;
}

int main()
{
    double start, stop;

    FILE *f;
	f = fopen("par.txt", "a");
    int i, res;

    fprintf(f, "%f\n", stop - start);
    i = 10000;
    start = omp_get_wtime();
    res = findprimef(i);
    stop = omp_get_wtime();
    fprintf(f, "guided chunk 7\n");

    fprintf(f, "%f\n", stop - start);
    printf(" %d\n",res);

    // i = 500000;
    // start = omp_get_wtime();
    // res = eratosthenes(i);
    // stop = omp_get_wtime();
    // fprintf(f, "%f\n", stop - start);
    // printf(" %d\n",res);

    // i = 1000000;
    // start = omp_get_wtime();
    // res = eratosthenes(i);
    // stop = omp_get_wtime();
    // fprintf(f, "%f\n", stop - start);
    // printf(" %d\n",res);

    fclose(f);
    return 0;
}