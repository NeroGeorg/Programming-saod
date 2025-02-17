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



void BubbleSort(int n, int A[], int *ptr_cf, int *ptr_mf){

    for(int i = 0; i < n - 1; i++){
        for(int j = n - 1 ; j > i; j--){
            (*ptr_cf)++;
            if( A[j] < A[j-1] ){
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                (*ptr_mf) += 3;
            }
        }
    }
}         

void PrintMas(int n, int A[]){
    for(int i = 0; i<n; i++){
        printf(" %d", A[i]);
    }
    printf("\n\n");
}

void PrintTable(int n, int c, int tri, int f, int fv, int *ptr_mf_dec, int *ptr_cf_dec, int *ptr_cf_rand, int *ptr_mf_rand, int *ptr_cf_inc, int *ptr_mf_inc, 
    int *ptr_mf_dec_h, int *ptr_cf_dec_h, int *ptr_cf_rand_h, int *ptr_mf_rand_h, int *ptr_cf_inc_h, int *ptr_mf_inc_h,  int *ptr_mf_dec_t, int *ptr_cf_dec_t, int *ptr_cf_rand_t, int *ptr_mf_rand_t, int *ptr_cf_inc_t, int *ptr_mf_inc_t,
    int *ptr_mf_dec_f, int *ptr_cf_dec_f, int *ptr_cf_rand_f, int *ptr_mf_rand_f, int *ptr_cf_inc_f, int *ptr_mf_inc_f,  int *ptr_mf_dec_fv, int *ptr_cf_dec_fv, int *ptr_cf_rand_fv, int *ptr_mf_rand_fv, int *ptr_cf_inc_fv, int *ptr_mf_inc_fv) {
    int theor_c = (n * (n - 1)) / 2;
    // printf("%d", theor_c);
    int theor_m = (3 * theor_c)/2;
    // printf("%d", theor_m);
    int theor_c_h = (c * (c - 1)) / 2;
    int theor_m_h = (3 * theor_c_h)/4;
    int theor_c_t = (tri * (tri - 1)) / 2;
    int theor_m_t = (3 * theor_c_t)/2;
    int theor_c_f = (f * (f - 1)) / 2;
    int theor_m_f = (3 * theor_c_f)/2;
    int theor_c_fv = (fv * (fv - 1)) / 2;
    int theor_m_fv = (3 * theor_c_fv)/2;
    printf("\t\t\tМф+Сф \n");
    printf("  N | Теор. M+C |  Убыв. | Случ. | Возр. |\n");
    printf(" %d | %d | %d | %d | %d \n", n, theor_m , *ptr_mf_dec + *ptr_cf_dec, *ptr_mf_rand + *ptr_cf_rand, *ptr_mf_inc + *ptr_cf_inc);
    printf(" %d | %d | %d | %d | %d \n", c, theor_m_h, *ptr_mf_dec_h + *ptr_cf_dec_h, *ptr_mf_rand_h + *ptr_cf_rand_h, *ptr_mf_inc_h + *ptr_cf_inc_h);
    printf(" %d | %d | %d | %d | %d \n", tri, theor_m_t, *ptr_mf_dec_t + *ptr_cf_dec_t, *ptr_mf_rand_t + *ptr_cf_rand_t, *ptr_mf_inc_t + *ptr_cf_inc_t);
    printf(" %d | %d | %d | %d | %d \n", f, theor_m_f, *ptr_mf_dec_f + *ptr_cf_dec_f, *ptr_mf_rand_f + *ptr_cf_rand_f, *ptr_mf_inc_f + *ptr_cf_inc_f);
    printf(" %d | %d | %d | %d | %d \n", fv, theor_m_fv, *ptr_mf_dec_fv + *ptr_cf_dec_fv, *ptr_mf_rand_fv + *ptr_cf_rand_fv, *ptr_mf_inc_fv + *ptr_cf_inc_fv);
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
    
    int n = 100;
    int A[n];

    printf("Прямой порядок\n");
    FillInc(n, A); 
    PrintMas(n, A);
    BubbleSort(n, A, ptr_mf_inc, ptr_cf_inc);

    printf("\nОбратный порядок\n");
    FillDec(n, A); 
    PrintMas(n, A);
    BubbleSort(n, A, ptr_mf_dec, ptr_cf_dec);
    PrintMas(n, A);

    printf("\nРандомный порядок\n");
    FillRand(n, A); 
    PrintMas(n, A);
    BubbleSort(n, A, ptr_mf_rand, ptr_cf_rand);
    PrintMas(n, A);

    // 200
    int mf_inc_h = 0, cf_inc_h = 0;
    int *ptr_mf_inc_h = &mf_inc_h, *ptr_cf_inc_h = &cf_inc_h;
    
    int mf_dec_h = 0, cf_dec_h = 0;
    int *ptr_mf_dec_h = &mf_dec_h, *ptr_cf_dec_h = &cf_dec_h;
    
    int mf_rand_h = 0, cf_rand_h = 0;
    int *ptr_mf_rand_h = &mf_rand_h, *ptr_cf_rand_h = &cf_rand_h;

    printf("\n");
    srand(time(0));
    int c = 200;
    int B[c];

    printf("Прямой порядок\n");
    FillInc(c, B); 
    PrintMas(c, B);
    BubbleSort(c, B, ptr_mf_inc_h, ptr_cf_inc_h);

    printf("\nОбратный порядок\n");
    FillDec(c, B); 
    PrintMas(c, B);
    BubbleSort(c, B, ptr_mf_dec_h, ptr_cf_dec_h);
    PrintMas(c, B);

    printf("\nРандомный порядок\n");
    FillRand(c, B); 
    PrintMas(c, B);
    BubbleSort(c, B, ptr_mf_rand_h, ptr_cf_rand_h);
    PrintMas(c, B);

    // 300
    int mf_inc_t = 0, cf_inc_t = 0;
    int *ptr_mf_inc_t = &mf_inc_t, *ptr_cf_inc_t = &cf_inc_t;
    
    int mf_dec_t = 0, cf_dec_t = 0;
    int *ptr_mf_dec_t = &mf_dec_t, *ptr_cf_dec_t = &cf_dec_t;
    
    int mf_rand_t = 0, cf_rand_t = 0;
    int *ptr_mf_rand_t = &mf_rand_t, *ptr_cf_rand_t = &cf_rand_t;

    printf("\n");
    srand(time(0));
    int tri = 300;
    int T[tri];

    printf("Прямой порядок\n");
    FillInc(tri, T); 
    PrintMas(tri, T);
    BubbleSort(tri, T, ptr_mf_inc_t, ptr_cf_inc_t);

    printf("\nОбратный порядок\n");
    FillDec(tri, T); 
    PrintMas(tri, T);
    BubbleSort(tri, T, ptr_mf_dec_t, ptr_cf_dec_t);
    PrintMas(tri, T);

    printf("\nРандомный порядок\n");
    FillRand(tri, T); 
    PrintMas(tri, T);
    BubbleSort(tri, T, ptr_mf_rand_t, ptr_cf_rand_t);
    PrintMas(tri, T);

    // 400
    int mf_inc_f = 0, cf_inc_f = 0;
    int *ptr_mf_inc_f = &mf_inc_f, *ptr_cf_inc_f = &cf_inc_f;
    
    int mf_dec_f = 0, cf_dec_f = 0;
    int *ptr_mf_dec_f = &mf_dec_f, *ptr_cf_dec_f = &cf_dec_f;
    
    int mf_rand_f = 0, cf_rand_f = 0;
    int *ptr_mf_rand_f = &mf_rand_f, *ptr_cf_rand_f = &cf_rand_f;

    printf("\n");
    srand(time(0));
    int f = 400;
    int F[f];

    printf("Прямой порядок\n");
    FillInc(f, F); 
    PrintMas(f, F);
    BubbleSort(f, F, ptr_mf_inc_f, ptr_cf_inc_f);

    printf("\nОбратный порядок\n");
    FillDec(f, F); 
    PrintMas(f, F);
    BubbleSort(f, F, ptr_mf_dec_f, ptr_cf_dec_f);
    PrintMas(f, F);

    printf("\nРандомный порядок\n");
    FillRand(f, F); 
    PrintMas(f, F);
    BubbleSort(f, F, ptr_mf_rand_f, ptr_cf_rand_f);
    PrintMas(f, F);

    // 500
    int mf_inc_fv = 0, cf_inc_fv = 0;
    int *ptr_mf_inc_fv = &mf_inc_fv, *ptr_cf_inc_fv = &cf_inc_fv;
    
    int mf_dec_fv = 0, cf_dec_fv = 0;
    int *ptr_mf_dec_fv = &mf_dec_fv, *ptr_cf_dec_fv = &cf_dec_fv;
    
    int mf_rand_fv = 0, cf_rand_fv = 0;
    int *ptr_mf_rand_fv = &mf_rand_fv, *ptr_cf_rand_fv = &cf_rand_fv;

    printf("\n");
    srand(time(0));
    int fv = 500;
    int Fv[fv];

    printf("Прямой порядок\n");
    FillInc(fv, Fv); 
    PrintMas(fv, Fv);
    BubbleSort(fv, Fv, ptr_mf_inc_fv, ptr_cf_inc_fv);

    printf("\nОбратный порядок\n");
    FillDec(fv, Fv); 
    PrintMas(fv, Fv);
    BubbleSort(fv, Fv, ptr_mf_dec_fv, ptr_cf_dec_fv);
    PrintMas(fv, Fv);

    printf("\nРандомный порядок\n");
    FillRand(fv, Fv); 
    PrintMas(fv, Fv);
    BubbleSort(fv, Fv, ptr_mf_rand_fv, ptr_cf_rand_fv);
    PrintMas(fv, Fv);

    PrintTable(n, c, tri, f, fv, ptr_mf_dec, ptr_cf_dec, ptr_mf_rand, ptr_cf_rand, ptr_mf_inc, ptr_cf_inc, ptr_mf_dec_h, ptr_cf_dec_h, ptr_mf_rand_h, ptr_cf_rand_h, ptr_mf_inc_h, ptr_cf_inc_h,
    ptr_mf_dec_t, ptr_cf_dec_t, ptr_mf_rand_t, ptr_cf_rand_t, ptr_mf_inc_t, ptr_cf_inc_t, ptr_mf_dec_f, ptr_cf_dec_f, ptr_mf_rand_f, ptr_cf_rand_f, ptr_mf_inc_f, ptr_cf_inc_f,
    ptr_mf_dec_fv, ptr_cf_dec_fv, ptr_mf_rand_fv, ptr_cf_rand_fv, ptr_mf_inc_fv, ptr_cf_inc_fv);

    return 0;
}