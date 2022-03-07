#include <stdio.h>
#include <stdlib.h>

int tape_count = 0;

void BubbleSort(int *arr, int leak_num)
{
    int temp;
    for (int i=0; i<leak_num-1; i++)
    {
        for (int j=0; j<leak_num-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void Solve(int *arr, int tape_len, int leak_num)
{
    BubbleSort(arr, leak_num);
    tape_count++;
    int right = arr[0] + tape_len;

    for(int i=1; i<leak_num; i++)
    {
        if (right >= arr[i] + 1)
            continue;
        right = arr[i] + tape_len;
        tape_count++;
    }
}

int main(void)
{
    int leak_num;
    int tape_len;
    scanf("%d %d", &leak_num, &tape_len);
    int *arr = (int *)malloc(sizeof(int) * leak_num);

    for (int i=0; i< leak_num ; i++)
    {
        scanf("%d", &arr[i]);
    }
    Solve(arr, tape_len, leak_num);
    printf("%d", tape_count);
    free(arr);
    return (0);
}