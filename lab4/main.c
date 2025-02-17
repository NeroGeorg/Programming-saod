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
        A[i] = (rand() % n) + 1;
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
         if (A[i] < A[i-1]){
            sum_s+=1;
        }
    }
    printf("Summa seriy = %d", sum_s);
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

void ShakerSort(int n, int A[], int *ptr_cf, int *ptr_mf){
    int p, i;
    for (p = 1; p <= n / 2; p++)
    {
        for (i = p - 1; i < n - p; i++){
            (*ptr_cf)++;
            if (A[i] > A[i+1]){
                int tmp = A[i];
                A[i] = A[i+1];
                A[i+1] = tmp;
                (*ptr_mf) += 3;}
            }   
        for (i = n - p - 1; i >= p; i--){
            (*ptr_cf)++;
            if (A[i] < A[i-1]){
                int tmp = A[i];
                A[i] = A[i-1];
                A[i-1] = tmp;
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
    int *ptr_mf_dec_f, int *ptr_cf_dec_f, int *ptr_cf_rand_f, int *ptr_mf_rand_f, int *ptr_cf_inc_f, int *ptr_mf_inc_f,  int *ptr_mf_dec_fv, int *ptr_cf_dec_fv, int *ptr_cf_rand_fv, int *ptr_mf_rand_fv, int *ptr_cf_inc_fv, int *ptr_mf_inc_fv, 
    int *ptr_cf_dec_sh, int *ptr_mf_dec_sh, int *ptr_mf_rand_sh, int *ptr_cf_rand_sh, int *ptr_mf_inc_sh, int *ptr_cf_inc_sh, int *ptr_cf_dec_h_sh, int *ptr_mf_dec_h_sh, int *ptr_mf_rand_h_sh, int *ptr_cf_rand_h_sh, int *ptr_mf_inc_h_sh, int *ptr_cf_inc_h_sh,
    int *ptr_cf_dec_t_sh, int *ptr_mf_dec_t_sh, int *ptr_mf_rand_t_sh, int *ptr_cf_rand_t_sh, int *ptr_mf_inc_t_sh, int *ptr_cf_inc_t_sh, int *ptr_cf_dec_f_sh, int *ptr_mf_dec_f_sh, int *ptr_mf_rand_f_sh, int *ptr_cf_rand_f_sh, int *ptr_mf_inc_f_sh, int *ptr_cf_inc_f_sh,
    int *ptr_cf_dec_fv_sh, int *ptr_mf_dec_fv_sh, int *ptr_mf_rand_fv_sh, int *ptr_cf_rand_fv_sh, int *ptr_mf_inc_fv_sh, int *ptr_cf_inc_fv_sh) {
    printf("\tМф+Сф пузырьковой          Мф+Сф шейкерной\n");
    printf("     N | Убыв. | Случ. | Возр.| | Убыв. | Случ. | Возр. |\n");
    printf(" %5d | %5d | %5d | %5d | | %5d | %5d | %5d |\n", n,  *ptr_mf_dec + *ptr_cf_dec, *ptr_mf_rand + *ptr_cf_rand, *ptr_mf_inc + *ptr_cf_inc, *ptr_mf_dec_sh + *ptr_cf_dec_sh, *ptr_mf_rand_sh + *ptr_cf_rand_sh, *ptr_mf_inc_sh + *ptr_cf_inc_sh);
    printf(" %5d | %5d | %5d | %5d | | %5d | %5d | %5d |\n", c, *ptr_mf_dec_h + *ptr_cf_dec_h, *ptr_mf_rand_h + *ptr_cf_rand_h, *ptr_mf_inc_h + *ptr_cf_inc_h, *ptr_mf_dec_h_sh + *ptr_cf_dec_h_sh, *ptr_mf_rand_h_sh + *ptr_cf_rand_h_sh, *ptr_mf_inc_h_sh + *ptr_cf_inc_h_sh);
    printf(" %5d | %5d | %5d | %5d | | %5d | %5d | %5d |\n", tri, *ptr_mf_dec_t + *ptr_cf_dec_t, *ptr_mf_rand_t + *ptr_cf_rand_t, *ptr_mf_inc_t + *ptr_cf_inc_t, *ptr_mf_dec_t_sh + *ptr_cf_dec_t_sh, *ptr_mf_rand_t_sh + *ptr_cf_rand_t_sh, *ptr_mf_inc_t_sh + *ptr_cf_inc_t_sh);
    printf(" %5d | %5d | %5d | %5d | | %5d | %5d | %5d |\n", f, *ptr_mf_dec_f + *ptr_cf_dec_f, *ptr_mf_rand_f + *ptr_cf_rand_f, *ptr_mf_inc_f + *ptr_cf_inc_f, *ptr_mf_dec_f_sh + *ptr_cf_dec_f_sh, *ptr_mf_rand_f_sh + *ptr_cf_rand_f_sh, *ptr_mf_inc_f_sh + *ptr_cf_inc_f_sh);
    printf(" %5d | %5d | %5d | %5d | | %5d | %5d | %5d |\n", fv, *ptr_mf_dec_fv + *ptr_cf_dec_fv, *ptr_mf_rand_fv + *ptr_cf_rand_fv, *ptr_mf_inc_fv + *ptr_cf_inc_fv, *ptr_mf_dec_fv_sh + *ptr_cf_dec_fv_sh, *ptr_mf_rand_fv_sh + *ptr_cf_rand_fv_sh, *ptr_mf_inc_fv_sh + *ptr_cf_inc_fv_sh);
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

    int mf_inc_sh = 0, cf_inc_sh = 0;
    int *ptr_mf_inc_sh = &mf_inc_sh, *ptr_cf_inc_sh = &cf_inc_sh;
    int mf_dec_sh = 0, cf_dec_sh = 0;
    int *ptr_mf_dec_sh = &mf_dec_sh, *ptr_cf_dec_sh = &cf_dec_sh;
    int mf_rand_sh = 0, cf_rand_sh = 0;
    int *ptr_mf_rand_sh = &mf_rand_sh, *ptr_cf_rand_sh = &cf_rand_sh;
    
    int n = 100;
    int A[n];

    printf("Прямой порядок\n");
    FillInc(n, A); 
    PrintMas(n, A);
    BubbleSort(n, A, ptr_mf_inc, ptr_cf_inc);
    ShakerSort(n, A, ptr_mf_inc_sh, ptr_cf_inc_sh);

    printf("\nОбратный порядок\n");
    FillDec(n, A); 
    PrintMas(n, A);
    BubbleSort(n, A, ptr_mf_dec, ptr_cf_dec);
    ShakerSort(n, A, ptr_mf_dec_sh, ptr_cf_dec_sh);
    PrintMas(n, A);

    printf("\nРандомный порядок\n");
    FillRand(n, A);
    PrintMas(n, A);
    BubbleSort(n, A, ptr_mf_rand, ptr_cf_rand);
    ShakerSort(n, A, ptr_mf_rand_sh, ptr_cf_rand_sh);
    PrintMas(n, A);

    // 200
    int mf_inc_h = 0, cf_inc_h = 0;
    int *ptr_mf_inc_h = &mf_inc_h, *ptr_cf_inc_h = &cf_inc_h;
    int mf_dec_h = 0, cf_dec_h = 0;
    int *ptr_mf_dec_h = &mf_dec_h, *ptr_cf_dec_h = &cf_dec_h; 
    int mf_rand_h = 0, cf_rand_h = 0;
    int *ptr_mf_rand_h = &mf_rand_h, *ptr_cf_rand_h = &cf_rand_h;

    int mf_inc_h_sh = 0, cf_inc_h_sh = 0;
    int *ptr_mf_inc_h_sh = &mf_inc_h_sh, *ptr_cf_inc_h_sh = &cf_inc_h_sh;
    int mf_dec_h_sh = 0, cf_dec_h_sh = 0;
    int *ptr_mf_dec_h_sh = &mf_dec_h_sh, *ptr_cf_dec_h_sh = &cf_dec_h_sh; 
    int mf_rand_h_sh = 0, cf_rand_h_sh = 0;
    int *ptr_mf_rand_h_sh = &mf_rand_h_sh, *ptr_cf_rand_h_sh = &cf_rand_h_sh;

    printf("\n");
    srand(time(0));
    int c = 200;
    int B[c];

    printf("Прямой порядок\n");
    FillInc(c, B); 
    PrintMas(c, B);
    BubbleSort(c, B, ptr_mf_inc_h, ptr_cf_inc_h);
    ShakerSort(c, B, ptr_mf_inc_h_sh, ptr_cf_inc_h_sh);

    printf("\nОбратный порядок\n");
    FillDec(c, B); 
    PrintMas(c, B);
    BubbleSort(c, B, ptr_mf_dec_h, ptr_cf_dec_h);
    ShakerSort(c, B, ptr_mf_dec_h_sh, ptr_cf_dec_h_sh);
    PrintMas(c, B);

    printf("\nРандомный порядок\n");
    FillRand(c, B); 
    PrintMas(c, B);
    BubbleSort(c, B, ptr_mf_rand_h, ptr_cf_rand_h);
    ShakerSort(c, B, ptr_mf_rand_h_sh, ptr_cf_rand_h_sh);
    PrintMas(c, B);

    // 300
    int mf_inc_t = 0, cf_inc_t = 0;
    int *ptr_mf_inc_t = &mf_inc_t, *ptr_cf_inc_t = &cf_inc_t;
    int mf_dec_t = 0, cf_dec_t = 0;
    int *ptr_mf_dec_t = &mf_dec_t, *ptr_cf_dec_t = &cf_dec_t;
    int mf_rand_t = 0, cf_rand_t = 0;
    int *ptr_mf_rand_t = &mf_rand_t, *ptr_cf_rand_t = &cf_rand_t;

    int mf_inc_t_sh = 0, cf_inc_t_sh = 0;
    int *ptr_mf_inc_t_sh = &mf_inc_t_sh, *ptr_cf_inc_t_sh = &cf_inc_t_sh;
    int mf_dec_t_sh = 0, cf_dec_t_sh = 0;
    int *ptr_mf_dec_t_sh = &mf_dec_t_sh, *ptr_cf_dec_t_sh = &cf_dec_t_sh;
    int mf_rand_t_sh = 0, cf_rand_t_sh = 0;
    int *ptr_mf_rand_t_sh = &mf_rand_t_sh, *ptr_cf_rand_t_sh = &cf_rand_t_sh;

    printf("\n");
    srand(time(0));
    int tri = 300;
    int T[tri];

    printf("Прямой порядок\n");
    FillInc(tri, T); 
    PrintMas(tri, T);
    BubbleSort(tri, T, ptr_mf_inc_t, ptr_cf_inc_t);
    ShakerSort(tri, T, ptr_mf_inc_t_sh, ptr_cf_inc_t_sh);

    printf("\nОбратный порядок\n");
    FillDec(tri, T); 
    PrintMas(tri, T);
    BubbleSort(tri, T, ptr_mf_dec_t, ptr_cf_dec_t);
    ShakerSort(tri, T, ptr_mf_dec_t_sh, ptr_cf_dec_t_sh);
    PrintMas(tri, T);

    printf("\nРандомный порядок\n");
    FillRand(tri, T); 
    PrintMas(tri, T);
    BubbleSort(tri, T, ptr_mf_rand_t, ptr_cf_rand_t);
    ShakerSort(tri, T, ptr_mf_rand_t_sh, ptr_cf_rand_t_sh);
    PrintMas(tri, T);

    // 400
    int mf_inc_f = 0, cf_inc_f = 0;
    int *ptr_mf_inc_f = &mf_inc_f, *ptr_cf_inc_f = &cf_inc_f;
    int mf_dec_f = 0, cf_dec_f = 0;
    int *ptr_mf_dec_f = &mf_dec_f, *ptr_cf_dec_f = &cf_dec_f;
    int mf_rand_f = 0, cf_rand_f = 0;
    int *ptr_mf_rand_f = &mf_rand_f, *ptr_cf_rand_f = &cf_rand_f;

    int mf_inc_f_sh = 0, cf_inc_f_sh = 0;
    int *ptr_mf_inc_f_sh = &mf_inc_f_sh, *ptr_cf_inc_f_sh = &cf_inc_f_sh;
    int mf_dec_f_sh = 0, cf_dec_f_sh = 0;
    int *ptr_mf_dec_f_sh = &mf_dec_f_sh, *ptr_cf_dec_f_sh = &cf_dec_f_sh;
    int mf_rand_f_sh = 0, cf_rand_f_sh = 0;
    int *ptr_mf_rand_f_sh = &mf_rand_f_sh, *ptr_cf_rand_f_sh = &cf_rand_f_sh;

    printf("\n");
    srand(time(0));
    int f = 400;
    int F[f];

    printf("Прямой порядок\n");
    FillInc(f, F); 
    PrintMas(f, F);
    BubbleSort(f, F, ptr_mf_inc_f, ptr_cf_inc_f);
    ShakerSort(f, F, ptr_mf_inc_f_sh, ptr_cf_inc_f_sh);

    printf("\nОбратный порядок\n");
    FillDec(f, F); 
    PrintMas(f, F);
    BubbleSort(f, F, ptr_mf_dec_f, ptr_cf_dec_f);
    ShakerSort(f, F, ptr_mf_dec_f_sh, ptr_cf_dec_f_sh);
    PrintMas(f, F);

    printf("\nРандомный порядок\n");
    FillRand(f, F); 
    PrintMas(f, F);
    BubbleSort(f, F, ptr_mf_rand_f, ptr_cf_rand_f);
    ShakerSort(f, F, ptr_mf_rand_f_sh, ptr_cf_rand_f_sh);
    PrintMas(f, F);

    // 500
    int mf_inc_fv = 0, cf_inc_fv = 0;
    int *ptr_mf_inc_fv = &mf_inc_fv, *ptr_cf_inc_fv = &cf_inc_fv;
    int mf_dec_fv = 0, cf_dec_fv = 0;
    int *ptr_mf_dec_fv = &mf_dec_fv, *ptr_cf_dec_fv = &cf_dec_fv;
    int mf_rand_fv = 0, cf_rand_fv = 0;
    int *ptr_mf_rand_fv = &mf_rand_fv, *ptr_cf_rand_fv = &cf_rand_fv;

    int mf_inc_fv_sh = 0, cf_inc_fv_sh = 0;
    int *ptr_mf_inc_fv_sh = &mf_inc_fv_sh, *ptr_cf_inc_fv_sh = &cf_inc_fv_sh;
    int mf_dec_fv_sh = 0, cf_dec_fv_sh = 0;
    int *ptr_mf_dec_fv_sh = &mf_dec_fv_sh, *ptr_cf_dec_fv_sh = &cf_dec_fv_sh;
    int mf_rand_fv_sh = 0, cf_rand_fv_sh = 0;
    int *ptr_mf_rand_fv_sh = &mf_rand_fv_sh, *ptr_cf_rand_fv_sh = &cf_rand_fv_sh;

    printf("\n");
    srand(time(0));
    int fv = 500;
    int Fv[fv];

    printf("Прямой порядок\n");
    FillInc(fv, Fv); 
    PrintMas(fv, Fv);
    BubbleSort(fv, Fv, ptr_mf_inc_fv, ptr_cf_inc_fv);
    ShakerSort(fv, Fv, ptr_mf_inc_fv_sh, ptr_cf_inc_fv_sh);

    printf("\nОбратный порядок\n");
    FillDec(fv, Fv); 
    PrintMas(fv, Fv);
    BubbleSort(fv, Fv, ptr_mf_dec_fv, ptr_cf_dec_fv);
    ShakerSort(fv, Fv, ptr_mf_dec_fv_sh, ptr_cf_dec_fv_sh);
    PrintMas(fv, Fv);

    printf("\nРандомный порядок\n");
    FillRand(fv, Fv); 
    PrintMas(fv, Fv);
    BubbleSort(fv, Fv, ptr_mf_rand_fv, ptr_cf_rand_fv);
    ShakerSort(fv, Fv, ptr_mf_rand_fv_sh, ptr_cf_rand_fv_sh);
    PrintMas(fv, Fv);

    PrintTable(n, c, tri, f, fv, ptr_mf_dec, ptr_cf_dec, ptr_mf_rand, ptr_cf_rand, ptr_mf_inc, ptr_cf_inc, ptr_mf_dec_h, ptr_cf_dec_h, ptr_mf_rand_h, ptr_cf_rand_h, ptr_mf_inc_h, ptr_cf_inc_h,
    ptr_mf_dec_t, ptr_cf_dec_t, ptr_mf_rand_t, ptr_cf_rand_t, ptr_mf_inc_t, ptr_cf_inc_t, ptr_mf_dec_f, ptr_cf_dec_f, ptr_mf_rand_f, ptr_cf_rand_f, ptr_mf_inc_f, ptr_cf_inc_f,
    ptr_mf_dec_fv, ptr_cf_dec_fv, ptr_mf_rand_fv, ptr_cf_rand_fv, ptr_mf_inc_fv, ptr_cf_inc_fv, ptr_mf_dec_sh, ptr_cf_dec_sh, ptr_mf_rand_sh, ptr_cf_rand_sh, ptr_mf_inc_sh, ptr_cf_inc_sh, 
    ptr_cf_dec_h_sh, ptr_mf_dec_h_sh, ptr_mf_rand_h_sh, ptr_cf_rand_h_sh, ptr_mf_inc_h_sh, ptr_cf_inc_h_sh,
    ptr_cf_dec_t_sh, ptr_mf_dec_t_sh, ptr_mf_rand_t_sh, ptr_cf_rand_t_sh, ptr_mf_inc_t_sh, ptr_cf_inc_t_sh,
    ptr_cf_dec_f_sh, ptr_mf_dec_f_sh, ptr_mf_rand_f_sh, ptr_cf_rand_f_sh, ptr_mf_inc_f_sh, ptr_cf_inc_f_sh,
    ptr_cf_dec_fv_sh, ptr_mf_dec_fv_sh, ptr_mf_rand_fv_sh, ptr_cf_rand_fv_sh, ptr_mf_inc_fv_sh, ptr_cf_inc_fv_sh);

    return 0;
}