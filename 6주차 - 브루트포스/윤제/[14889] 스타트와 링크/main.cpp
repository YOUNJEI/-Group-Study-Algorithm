#include <stdio.h>
#include <stdlib.h>

int my_abs(int n)
{
    if (n >= 0)
        return (n);
    else
        return (-n);
}

int solve(int **arr, int *visit, int N, int count, int idx)
{
    static int comb_num = N / 2;
    static int start_team_status = 0;
    static int link_team_status = 0;
    static int answer;
    static int is_set_first = true;

    if (count == comb_num)
    {
        for (int i = 0; i < N; i++)
        {
            if (visit[i] == 1)
            {
                for (int j = 0; j < N; j++)
                {
                    if (visit[j] == 1)
                    {
                        start_team_status += arr[i][j];
                    }
                }
            }
            else
            {
                for (int j = 0; j < N; j++)
                {
                    if (visit[j] != 1)
                    {
                        link_team_status += arr[i][j];
                    }
                }
            }
        }
        if (is_set_first)
        {
            answer = my_abs(start_team_status - link_team_status);
            is_set_first = false;
        }
        else
        {
            int temp = my_abs(start_team_status - link_team_status);
            if (temp < answer)
                answer = temp;
        }
        start_team_status = 0;
        link_team_status = 0;
        return (-1);
    }
    for (int i = idx + 1; i < N; i++)
    {
        if (visit[i] == 0)
        {
            visit[i] = 1;
            solve(arr, visit, N, count + 1, i);
            visit[i] = 0;
        }
    }
    return (answer);
}

int main(void)
{
    int **arr = NULL;
    int *visit = NULL;
    int N;

    scanf("%d", &N);
    arr = (int **)malloc(sizeof(int *) * N);
    visit = (int *)malloc(sizeof(int) * N);
    if (arr == NULL || visit == NULL)
        return (-1);
    for (int i = 0; i < N; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * N);
        if (arr[i] == NULL)
            return (-1);
        visit[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d", solve(arr, visit, N, 0, -1));
    for (int i = 0; i < N; i++)
        free(arr[i]);
    free(arr);
    free(visit);
    return (0);
}