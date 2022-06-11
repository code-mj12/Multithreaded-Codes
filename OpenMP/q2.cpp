#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
int arr[] = {
        1,
        3,
        5,
        7,
        9,
        11,
        13,
        15,
        17,
        19,
        21,
        23,
        25,
        27,
        29,
        31,
        33,
        35,
        37,
        39,
        42,
        43,
        45
    };    int noel = sizeof(arr)/sizeof(int);
    int num_to_found = 7;
    bool var = 0;
    int fpro=0;
    int delpro=0;
    #pragma omp parallel
    {   
        #pragma omp sections
        {
            if(var==0){
            for(int i=0;i<noel/2;i++){
                if(!(arr[i]==num_to_found)){}else{
                    var=1;
                    fpro=1;
                    delpro=2;
                    cout << "Thread 1 found the number" << endl;
                    break;
                }
            }}
        }
        #pragma omp sections
        {
            if(var==0){
            for(int j=noel/2;j<noel;j++){
                if(!(arr[j]==num_to_found)){}else{
                    var=1;
                    fpro=2;
                    delpro=1;
                    cout << "Thread 2 found the number" << endl;
                    break;
                }
            }
            }
        }
        #pragma omp master
        {
            while(1>0){
                if(var==1){
                    cout << "Master: Process " << fpro << " has found the number" << endl;
                    cout << "All process aborted including process " << delpro << endl;
                    break;
                }
            }
        }
      
    }
}