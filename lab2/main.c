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
        A[i] = (rand() % 100) + 1;
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
    int sum_s = 1;
    for(int i = 1; i<n; i++){
         if (A[i] <= A[i-1]){
            sum_s+=1;
        }
    }
    printf("Sum_s = %d", sum_s);
    printf("\n");
    return sum_s;
}



void SelectSortSimple(int n, int A[], int *ptr_cf, int *ptr_mf){

    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            (*ptr_cf)++;
            if( A[j] < A[min] ){
                min = j;
            }
        }
            int tmp = A[i];
            A[i] = A[min];
            A[min] = tmp;
            (*ptr_mf) += 3;
    }
}    

void SelectSort(int n, int A[], int *ptr_cf, int *ptr_mf){

    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            (*ptr_cf)++;
            if( A[j] < A[min] ){
                min = j;
            }
        }
        if( min != i){
            int tmp = A[i];
            A[i] = A[min];
            A[min] = tmp;
            (*ptr_mf) += 3;
        }
    }
}  

void PrintMas(int n, int A[]){
    for(int i = 0; i<n; i++){
        printf(" %d", A[i]);
    }
    printf("\n\n");
}

void PrintTable(int n, int c, 
    int *ptr_mf_dec, int *ptr_cf_dec, int *ptr_cf_rand, int *ptr_mf_rand, int *ptr_cf_inc, int *ptr_mf_inc, int *ptr_mf_dec_h, int *ptr_cf_dec_h, int *ptr_cf_rand_h, int *ptr_mf_rand_h, int *ptr_cf_inc_h, int *ptr_mf_inc_h,
        int *ptr_mf_dec_s, int *ptr_cf_dec_s, int *ptr_cf_rand_s, int *ptr_mf_rand_s, int *ptr_cf_inc_s, int *ptr_mf_inc_s, int *ptr_mf_dec_h_s, int *ptr_cf_dec_h_s, int *ptr_cf_rand_h_s, int *ptr_mf_rand_h_s, int *ptr_cf_inc_h_s, int *ptr_mf_inc_h_s) {

    int theor_c = (n * (n - 1)) / 2;
    int theor_m = 3 * (n - 1);
    int theor_c_h = (c * (c - 1)) / 2;
    int theor_m_h = 3 * (c - 1);
    printf("\t\t\tУлуч. Мф+Сф                Мф+Сф \n");
    printf("   N |Теор. M+C|  Убыв. | Случ. | Возр. |  | Убыв. | Случ. | Возр. \n");
    printf(" %5d | %5d | %5d | %5d | %5d |  | %5d | %5d | %5d |\n", n, theor_m + theor_c, *ptr_mf_dec + *ptr_cf_dec, *ptr_mf_rand + *ptr_cf_rand, *ptr_mf_inc + *ptr_cf_inc, *ptr_mf_dec_s + *ptr_cf_dec_s, *ptr_mf_rand_s + *ptr_cf_rand_s, *ptr_mf_inc_s + *ptr_cf_inc_s);
    printf(" %5d | %5d | %5d | %5d | %5d |  | %5d | %5d | %5d |\n", c, theor_m_h + theor_c_h, *ptr_mf_dec_h + *ptr_cf_dec_h, *ptr_mf_rand_h + *ptr_cf_rand_h, *ptr_mf_inc_h + *ptr_cf_inc_h, *ptr_mf_dec_h_s + *ptr_cf_dec_h_s, *ptr_mf_rand_h_s + *ptr_cf_rand_h_s, *ptr_mf_inc_h_s + *ptr_cf_inc_h_s);
}

int main(){
    
    srand(time(0));

    int mf = 0;
    int cf = 0;
    int *ptr_mf = &mf;
    int *ptr_cf = &cf;

    int mf_inc = 0, cf_inc = 0;
    int *ptr_mf_inc = &mf_inc, *ptr_cf_inc = &cf_inc;
    int mf_dec = 0, cf_dec = 0;
    int *ptr_mf_dec = &mf_dec, *ptr_cf_dec = &cf_dec;
    int mf_rand = 0, cf_rand = 0;
    int *ptr_mf_rand = &mf_rand, *ptr_cf_rand = &cf_rand;

    int mf_inc_s = 0, cf_inc_s = 0;
    int *ptr_mf_inc_s = &mf_inc_s, *ptr_cf_inc_s = &cf_inc_s;
    int mf_dec_s = 0, cf_dec_s = 0;
    int *ptr_mf_dec_s = &mf_dec_s, *ptr_cf_dec_s = &cf_dec_s;
    int mf_rand_s = 0, cf_rand_s = 0;
    int *ptr_mf_rand_s = &mf_rand_s, *ptr_cf_rand_s = &cf_rand_s;

    int n = 10;
    int A[n];

    printf("Прямой порядок\n");
    FillInc(n, A); 
    PrintMas(n, A);
    SelectSort(n, A, ptr_mf_inc, ptr_cf_inc);
    SelectSortSimple(n, A, ptr_mf_inc_s, ptr_cf_inc_s);

    printf("\nОбратный порядок\n");
    FillDec(n, A); 
    PrintMas(n, A);
    SelectSort(n, A, ptr_mf_dec, ptr_cf_dec);
    SelectSortSimple(n, A, ptr_mf_dec_s, ptr_cf_dec_s);
    PrintMas(n, A);

    printf("\nРандомный порядок\n");
    FillRand(n, A); 
    PrintMas(n, A);
    SelectSort(n, A, ptr_mf_rand, ptr_cf_rand);
    SelectSortSimple(n, A, ptr_mf_rand_s, ptr_cf_rand_s);
    PrintMas(n, A);

    // 100

    int mf_inc_h = 0, cf_inc_h = 0;
    int *ptr_mf_inc_h = &mf_inc_h, *ptr_cf_inc_h = &cf_inc_h;
    
    int mf_dec_h = 0, cf_dec_h = 0;
    int *ptr_mf_dec_h = &mf_dec_h, *ptr_cf_dec_h = &cf_dec_h;
    
    int mf_rand_h = 0, cf_rand_h = 0;
    int *ptr_mf_rand_h = &mf_rand_h, *ptr_cf_rand_h = &cf_rand_h;

    int mf_inc_h_s = 0, cf_inc_h_s = 0;
    int *ptr_mf_inc_h_s = &mf_inc_h_s, *ptr_cf_inc_h_s = &cf_inc_h_s;
    
    int mf_dec_h_s = 0, cf_dec_h_s = 0;
    int *ptr_mf_dec_h_s = &mf_dec_h_s, *ptr_cf_dec_h_s = &cf_dec_h_s;
    
    int mf_rand_h_s = 0, cf_rand_h_s = 0;
    int *ptr_mf_rand_h_s = &mf_rand_h_s, *ptr_cf_rand_h_s = &cf_rand_h_s;

    printf("\n");
    srand(time(0));
    int c = 100;
    int B[c];

    printf("Прямой порядок\n");
    FillInc(c, B); 
    PrintMas(c, B);
    SelectSort(c, B, ptr_mf_inc_h, ptr_cf_inc_h);
    SelectSortSimple(c, B, ptr_mf_inc_h_s, ptr_cf_inc_h_s);

    printf("\nОбратный порядок\n");
    FillDec(c, B); 
    PrintMas(c, B);
    SelectSortSimple(c, B, ptr_mf_dec_h_s, ptr_cf_dec_h_s);
    SelectSort(c, B, ptr_mf_dec_h, ptr_cf_dec_h);
    PrintMas(c, B);

    printf("\nРандомный порядок\n");
    FillRand(c, B); 
    PrintMas(c, B);
    SelectSortSimple(c, B, ptr_mf_rand_h_s, ptr_cf_rand_h_s); 
    SelectSort(c, B, ptr_mf_rand_h, ptr_cf_rand_h); 
    PrintMas(c, B);

    PrintTable(n, c, 
        ptr_mf_dec, ptr_cf_dec, ptr_mf_rand, ptr_cf_rand, ptr_mf_inc, ptr_cf_inc, ptr_mf_dec_h, ptr_cf_dec_h, ptr_mf_rand_h, ptr_cf_rand_h, ptr_mf_inc_h, ptr_cf_inc_h,
        ptr_mf_dec_s, ptr_cf_dec_s, ptr_mf_rand_s, ptr_cf_rand_s, ptr_mf_inc_s, ptr_cf_inc_s, ptr_mf_dec_h_s, ptr_cf_dec_h_s, ptr_mf_rand_h_s, ptr_cf_rand_h_s, ptr_mf_inc_h_s, ptr_cf_inc_h_s);
    return 0;
}