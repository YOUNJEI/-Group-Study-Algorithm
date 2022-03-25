#include <stdio.h>

#define BUFFER_SIZE 100
#define HEIGHT_SIZE 101
int g_arr[BUFFER_SIZE][BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE];
bool g_harr[HEIGHT_SIZE];
int N;

void reset_visit(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            g_visit[i][j] = false;
    }
}

void mark_visit(int r, int c, int height)
{
    if (r < 0 || r > N - 1 || c < 0 || c > N - 1)
        return ;
    if (!g_visit[r][c])
        g_visit[r][c] = true;
    if (g_arr[r - 1][c] > height && !g_visit[r - 1][c])
        mark_visit(r - 1, c, height);
    if (g_arr[r + 1][c] > height && !g_visit[r + 1][c])
        mark_visit(r + 1, c, height);
    if (g_arr[r][c - 1] > height && !g_visit[r][c - 1])
        mark_visit(r, c - 1, height);
    if (g_arr[r][c + 1] > height && !g_visit[r][c + 1])
        mark_visit(r, c + 1, height);
}

int count_island(int height)
{
    int count = 0;
    reset_visit();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (g_arr[i][j] > height && g_visit[i][j] == false)
            {
                count++;
                mark_visit(i, j, height);
            }
        }
    }
    return (count);
}

void solve(void)
{
    int answer = 1;
    int temp;

    for (int i = 1; i < HEIGHT_SIZE; i++)
    {
        if (g_harr[i])
        {
            temp = count_island(i);
            if (temp > answer)
                answer = temp;
        }
    }
    printf("%d\n", answer);
}

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &g_arr[i][j]);
            if (g_harr[g_arr[i][j]] == false)
                g_harr[g_arr[i][j]] = true;
        }
    }
    solve();
    return (0);
}