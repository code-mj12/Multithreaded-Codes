#include <omp.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkPrime(int number){
    bool isPrime = true;

    #pragma omp parallel for schedule(guided,7)
    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0) {
            isPrime = false;
        }
    }
    
    if (isPrime == true) {
        //printf("Number is Prime");
    }
    else {
        //printf("Number not prime");
    }
    return isPrime;
}

int main()
{
        double start, stop;

    FILE *f;
	f = fopen("q1.txt", "a");

omp_set_num_threads(8);
int maxq=0;
    start = omp_get_wtime();

#pragma omp parallel for reduction(max:maxq)
for (int i = 1; i < 5000; i++)
{
    if(checkPrime(i)){
        maxq=i;
    }
    /* code */
}
stop = omp_get_wtime();
fprintf(f, "guided chunk 7\n");
fprintf(f, "%f\n", stop - start);
printf("%d",maxq);
fclose(f);
return 0;
}