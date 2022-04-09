#include <iostream>

using namespace std;

#define BUFFER_SIZE 100
int arr[BUFFER_SIZE + 2][BUFFER_SIZE + 2][BUFFER_SIZE + 2];
bool g_visit[BUFFER_SIZE + 2][BUFFER_SIZE + 2][BUFFER_SIZE + 2];
int M, N, H;

int max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

bool is_work_done(void)
{
	for (int i = 1; i < H + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			for (int k = 1; k < M + 1; k++)
			{
				if (arr[i][j][k] == 0)
					return (false);
			}
		}
	}
	return (true);
}

int recur(int h, int r, int c, int days)
{
	int ret = days;

	if (h <= 0 || h > H || r <= 0 || r > N || c <= 0 || c > M)
		return (-1);
	arr[h][r][c] = 1;
	g_visit[h][r][c] = true;
	if (arr[h + 1][r][c] == 0 && g_visit[h + 1][r][c] == false)
		ret = max(ret, recur(h + 1, r, c, days + 1));
	if (arr[h - 1][r][c] == 0 && g_visit[h - 1][r][c] == false)
		ret = max(ret, recur(h - 1, r, c, days + 1));
	if (arr[h][r + 1][c] == 0 && g_visit[h][r + 1][c] == false)
		ret = max(ret, recur(h, r + 1, c, days + 1));
	if (arr[h][r - 1][c] == 0 && g_visit[h][r - 1][c] == false)
		ret = max(ret, recur(h, r - 1, c, days + 1));
	if (arr[h][r][c + 1] == 0 && g_visit[h][r][c + 1] == false)
		ret = max(ret, recur(h, r, c + 1, days + 1));
	if (arr[h][r][c - 1] == 0 && g_visit[h][r][c - 1] == false)
		ret = max(ret, recur(h, r, c - 1, days + 1));
	return (ret);
}

void solve(void)
{
	int answer = 0;

	for (int i = 1; i < H + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			for (int k = 1; k < M + 1; k++)
			{
				if (arr[i][j][k] == 1 && g_visit[i][j][k] == false)
				{
					answer = max(answer, recur(i, j, k, 0));
				}
			}
		}
	}
	if (is_work_done())
	{
		answer /= 6;
		answer++;
		cout<<answer;
	}
	else
		cout<<"-1";
}

int main(void)
{
	cin>>M>>N>>H;
	for (int i = 1; i < H + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			for (int k = 1; k < M + 1; k++)
			{
				cin>>arr[i][j][k];
			}
		}
	}
	solve();
	return 0;
}
