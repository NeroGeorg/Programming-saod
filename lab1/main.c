#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillInc(int n, int A[]){
    for(int i = 0; i<n; i++){
        A[i] = i + 1;
    }
    printf("\n");
}

void FillDec(int n, int A[]){
    for(int i = 0; i<n; i++){
        A[i] = n - i;
    }
    printf("\n");
}

void FillRand(int n, int A[]){
    for(int i = 0; i<n; i++){
        A[i] = rand() % 100;
    }
    printf("\n");
}

int CheckSum(int n, int A[]){
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += A[i];
    }
    printf("Sum = %d", sum);
    printf("\n");
    return sum;
}

int RunNumber(int n, int A[]){
    int sum_s = 0;
    for(int i = 0; i<n; i++){
         if (A[i] <= A[i-1]){
            sum_s+=1;
        }
    }
    printf("Sum_s = %d", sum_s);
    printf("\n");
    return sum_s;
}

void PrintMas(int n, int A[]){
    for(int i = 0; i<n; i++){
        printf(" %d |", A[i]);
    }
    printf("\n");
}

int main(){
    int n = 10;
    int A[n];

    FillInc(n, A);
    PrintMas(n, A);
    CheckSum(n, A);
    RunNumber(n, A);

    FillDec(n, A);
    PrintMas(n, A);
    CheckSum(n, A);
    RunNumber(n, A);

    srand(time(0));
    FillRand(n, A); 
    PrintMas(n, A);
    CheckSum(n, A);
    RunNumber(n, A);

}
