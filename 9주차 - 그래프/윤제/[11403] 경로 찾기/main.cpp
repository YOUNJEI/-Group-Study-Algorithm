#include <stdio.h>

#define BUFFER_SIZE 100
int g_arr[BUFFER_SIZE][BUFFER_SIZE];
int g_answer[BUFFER_SIZE][BUFFER_SIZE];
bool g_visit [BUFFER_SIZE];
int N;

void reset_visit(void)
{
    for (int i = 0; i < N; i++)
        g_visit[i] = false;
}

bool recur(int _from, int _target, int depth)
{
    bool path = false;
    if (depth != 0 && _from == _target)
        return (true);
    if (!g_visit[_from])
        g_visit[_from] = true;
    for (int i = 0; i < N; i++)
    {
        if (g_arr[_from][i])
        {
            if (i == _target)
                return (true);
            if (!g_visit[i])
            {
                if (recur(i, _target, depth + 1))
                    return (true);
            }
        }
    }
    return (path);
}

void solve(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            reset_visit();
            if (recur(i, j, 0))
                g_answer[i][j] = 1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d", g_answer[i][j]);
            if (j != N - 1)
                printf(" ");
        }
        printf("\n");
    }
}

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &g_arr[i][j]);
        }
    }
    solve();
    return (0);
}