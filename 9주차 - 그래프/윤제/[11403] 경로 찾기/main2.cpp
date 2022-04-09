#include <stdio.h>
#include <vector>
using namespace std;

#define BUFFER_SIZE 100
int g_arr[BUFFER_SIZE][BUFFER_SIZE];
int g_answer[BUFFER_SIZE][BUFFER_SIZE];
bool g_visit [BUFFER_SIZE][BUFFER_SIZE];
int N;

void recur(int i, int j, vector <int> *vi)
{
	bool flag = true;

	if (g_visit[i][j] == false)
	{
		g_visit[i][j] = true;
		g_answer[i][j] = 1;
		printf("(%d %d)\n", i, j);
	}
	for (int k = 0; k < N; k++)
	{
		if (g_arr[j][k] == 1 && g_visit[j][k] == false)
		{
			//recur(j, k, vi);
			if (!vi->empty())
			{
				for (int l = 0; l < vi->size(); l++)
				{
					if (g_visit[(*vi)[l]][k] == false)
					{	
						g_visit[(*vi)[l]][k] = true;
						g_answer[(*vi)[l]][k] = 1;
						printf("(%d %d)\n", (*vi)[l], k);
					}
				}
			}
			if (flag)
			{
				vi->push_back(i);
				flag = false;
			}
			recur(j, k, vi);
		}
	}
}

void solve(void)
{
	vector <int> vi;

	vi.clear();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
		if (g_arr[i][j] == 1 && g_visit[i][j] == false)
		{
			recur(i, j, &vi);
			vi.clear();
		}
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
