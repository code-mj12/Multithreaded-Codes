#include <omp.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
using namespace std;

int count_occurrence(string str, string word){
    omp_set_num_threads(8);

    int  j, temp, countW=0, chk;
    #pragma omp parallel for schedule(dynamic,6)
    for(int i =0; i<=str.length();i++)
        {
            temp = i;
            j=0;
            for(j=0;j<word.length();j++)
            {
                if(str[i]==word[j])
                    i++;
            }
            chk = i-temp;
            if(chk==j){
                countW++;
                }
            i = temp;

        }

        return countW;
}

int main(){
    int a= count_occurrence ("ATTTGCGCAGACCTAAGCA", "GCA");
    cout<<a<<endl;
    a=count_occurrence ("AAABCDEFGAAGEREAANMT", "AA");
    cout<<a<<endl;
    a=count_occurrence ("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "BTTT");
    cout<<a<<endl;
    return 0;
}