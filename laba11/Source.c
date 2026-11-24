#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

#define N 10

void task1();
void task2();
void task3();

int main()
{
    setlocale(LC_ALL, "RUS");

    task1();
    task2();
    task3();
}

void task1() 
{
    float A[N];
    float temp;

    printf("Введите %d вещественных чисел:\n", N);
    for (int i = 0; i < N; i++) 
    {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
    }

    float A_new[N];
    for (int i = 0; i < N; i++) 
    {
        A_new[i] = A[i] * A[i];
    }

    float sum = 0;
    for (int i = 0; i < N; i++) 
    {
        sum += A[i];
    }
    float avg = sum / N;

    printf("\n| индекс | исходное значение | новое значение |\n");
    printf("|--------|-------------------|----------------|\n");
    for (int i = 0; i < N; i++) 
    {
        printf("| %6d | %17.2f | %14.2f |\n", i + 1, A[i], A_new[i]);
    }

    printf("\nСреднее арифметическое исходного массива: %.2f\n", avg);
}

float calculate_func(float x) 
{
    return x * x - 2 * x + 1;
}

void task2()
{
#define SIZE 100 
    float arr[SIZE];
    float x_min = -10.0, x_max = 10.0;

    float sum_pos = 0, sum_neg = 0;
    int count_pos = 0, count_neg = 0;

    for (int i = 0; i < SIZE; i++)
    {
        float x = x_min + (float)rand() / RAND_MAX * (x_max - x_min);
        arr[i] = calculate_func(x);

        if (arr[i] > 0) {
            sum_pos += arr[i];
            count_pos++;
        }
        else if (arr[i] < 0) {
            sum_neg += arr[i];
            count_neg++;
        }
    }

    float avg_pos = (count_pos > 0) ? (sum_pos / count_pos) : 0.0;

    printf("Имя массива: arr\n");
    printf("Сумма положительных: %.2f\n", sum_pos);
    printf("Сумма отрицательных: %.2f\n", sum_neg);
    printf("Число положительных: %d\n", count_pos);
    printf("Число отрицательных: %d\n", count_neg);
    printf("Среднее положительных: %.2f\n", avg_pos);
}

void task3() 
{
    int n;
    printf("Введите размер массива n: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) 
    {
        printf("Ошибка памяти!\n");
        return;
    }

    printf("Введите %d целых чисел (положительных и отрицательных):\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int first_pos = -1, last_pos = -1;

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > 0) 
        {
            if (first_pos == -1) first_pos = i;
            last_pos = i;
        }
    }

    long long sum_between = 0;
    if (first_pos != -1 && last_pos != -1 && first_pos < last_pos) 
    {
        for (int i = first_pos + 1; i < last_pos; i++) 
        {
            sum_between += arr[i];
        }
        printf("Сумма элементов между первым (%d) и последним (%d) положительными элементами: %lld\n",
            first_pos + 1, last_pos + 1, sum_between);
    }
    else 
    {
        printf("В массиве нет двух положительных элементов или они стоят рядом. Сумма не вычислена.\n");
    }

    free(arr);
}