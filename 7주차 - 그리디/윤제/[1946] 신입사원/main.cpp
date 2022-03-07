#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int solve(int *arr, int person_num)
{
    int count = 0;
    int target = arr[0];

    for (int i = 0; i < person_num; i++)
    {
        if (arr[i] <= target)
        {
            target = arr[i];
            count++;
        }
    }
    return (count);
}

int main(void)
{
    int test_case_num;
    int person_num;
    int *arr = NULL;
    int *answer = NULL;
    int x, y;

    scanf("%d", &test_case_num);
    answer = (int *)malloc(sizeof(int) * test_case_num);
    if (answer == NULL)
        return (-1);
    for (int i = 0; i < test_case_num; i++)
    {
        scanf("%d", &person_num);
        arr = (int *)malloc(sizeof(int) * person_num);
        if (arr == NULL)
            return (-1);
        for (int j = 0; j < person_num; j++)
        {
            scanf("%d %d", &x, &y);
            arr[x - 1] = y - 1;
        }
        answer[i] = solve(arr, person_num);
        free(arr);
    }
    for (int i = 0; i < test_case_num; i++)
        printf("%d\n", answer[i]);
    free(answer);
    return (0);
}