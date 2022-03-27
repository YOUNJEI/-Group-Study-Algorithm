#include <stdio.h>
#include <vector>
#define BUFFER_SIZE 100
using namespace std;

typedef struct s_rect
{
    int L_X;
    int L_Y;
    int R_X;
    int R_Y;
}   t_rect;

int g_arr[BUFFER_SIZE][BUFFER_SIZE];
t_rect g_rect[BUFFER_SIZE];
int M;
int N;
int K;

void trans_position_to_computer_idx()
{
    for (int i = 0; i < K; i++)
    {
        g_rect[i].L_Y = (M - g_rect[i].L_Y - 1);
        
        g_rect[i].R_Y = (M - g_rect[i].R_Y);
        g_rect[i].R_X = g_rect[i].R_X - 1;
    }
}

int min(int n1, int n2)
{
    if (n1 <= n2)
        return (n1);
    else
        return (n2);
}

int max(int n1, int n2)
{
    if (n1 <= n2)
        return (n2);
    else
        return (n1);
}

void fill_rect()
{
    for (int _loop = 0; _loop < K; _loop++)
    {
        for (int i = min(g_rect[_loop].L_Y, g_rect[_loop].R_Y); i <= max(g_rect[_loop].L_Y, g_rect[_loop].R_Y); i++)
        {
            for (int j = min(g_rect[_loop].L_X, g_rect[_loop].R_X); j <= max(g_rect[_loop].L_X, g_rect[_loop].R_X); j++)
            {
                g_arr[i][j] = 1;
            }
        }
    }
}

int recur(int r, int c)
{
    int count = 0;
    if (r < 0 || r > M - 1 || c < 0 || c > N - 1)
        return (0);
    if (!g_arr[r][c])
        g_arr[r][c] = 2;
    if (!g_arr[r - 1][c])
        count += recur(r - 1, c);
    if (!g_arr[r + 1][c])
        count += recur(r + 1, c);
    if (!g_arr[r][c - 1])
        count += recur(r, c - 1);
    if (!g_arr[r][c + 1])
        count += recur(r, c + 1);
    return (count + 1);
}

void vector_sort(vector<int> &answer)
{
    int temp;
    int size = answer.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (answer[j] > answer[j + 1])
            {
                temp = answer[j];
                answer[j] = answer[j + 1];
                answer[j + 1] = temp;
            }
        }
    }
}

void solve(void)
{
    vector<int> answer;
    fill_rect();

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (g_arr[i][j] == 0)
            {
                answer.push_back(recur(i, j));
            }
        }
    }
    vector_sort(answer);
    printf("%lu\n", answer.size());
    for (int i = 0; i < answer.size(); i++)
    {
        printf("%d", answer[i]);
        if (i != answer.size() - 1)
        printf(" ");
    }
}

int main(void)
{
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d %d %d %d", &g_rect[i].L_X, &g_rect[i].L_Y, &g_rect[i].R_X, &g_rect[i].R_Y);
    }
    trans_position_to_computer_idx();
    solve();
    return (0);
}