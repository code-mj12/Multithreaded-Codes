#include <omp.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
using namespace std;

int count_occurrence(string str, string word){
    int i=0, j, temp, countW=0, chk;
    while(str[i]!='\0')
        {
            temp = i;
            j=0;
            while(word[j]!='\0')
            {
                if(str[i]==word[j])
                    i++;
                j++;
            }
            chk = i-temp;
            if(chk==j){
                countW++;
                }
            i = temp;
            i++;
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
}