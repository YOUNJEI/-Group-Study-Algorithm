#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define BUFFER_SIZE 100
int arr[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE];
bool g_visit[BUFFER_SIZE][BUFFER_SIZE][BUFFER_SIZE];
bool g_days[BUFFER_SIZE*BUFFER_SIZE*BUFFER_SIZE];
int M, N, H;
queue<tuple<int, int, int, int>> q;

bool is_work_done(void)
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (arr[i][j][k] == 0)
					return (false);
			}
		}
	}
	return (true);
}

int bfs(void)
{
	int count = -1;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (arr[i][j][k] == 1 && g_visit[i][j][k] == false)
				{
					q.push(make_tuple(i, j, k, 0));
					g_visit[i][j][k] = true;
				}
			}
		}
	}
	while (!q.empty())
	{
		int h = get<0>(q.front());
		int r = get<1>(q.front());
		int c = get<2>(q.front());
		int days = get<3>(q.front());
		q.pop();

		arr[h][r][c] = 1;
		if (!g_days[days])
		{
			g_days[days] = true;
			count++;
		}
		if (h < H - 1 && arr[h + 1][r][c] == 0 && g_visit[h + 1][r][c] == false)
		{
			q.push(make_tuple(h + 1, r, c, days + 1));
			g_visit[h + 1][r][c] = true;
		}
		if (h > 0 && arr[h - 1][r][c] == 0 && g_visit[h - 1][r][c] == false)
		{
			q.push(make_tuple(h - 1, r, c, days + 1));
			g_visit[h - 1][r][c] = true;
		}
		if (r < N - 1 && arr[h][r + 1][c] == 0 && g_visit[h][r + 1][c] == false)
		{
			q.push(make_tuple(h, r + 1, c, days + 1));
			g_visit[h][r + 1][c] = true;
		}
		if (r > 0 && arr[h][r - 1][c] == 0 && g_visit[h][r - 1][c] == false)
		{
			q.push(make_tuple(h, r - 1, c, days + 1));
			g_visit[h][r - 1][c] = true;
		}
		if (c < M - 1 && arr[h][r][c + 1] == 0 && g_visit[h][r][c + 1] == false)
		{
			q.push(make_tuple(h, r, c + 1, days + 1));
			g_visit[h][r][c + 1] = true;
		}
		if (c > 0 && arr[h][r][c - 1] == 0 && g_visit[h][r][c - 1] == false)
		{
			q.push(make_tuple(h, r, c - 1, days + 1));
			g_visit[h][r][c - 1] = true;
		}
	}
	return (count);
}

void solve(void)
{
	int answer;

	answer = bfs();
	if (is_work_done())
		cout<<answer;
	else
		cout<<"-1";
}

int main(void)
{
	cin>>M>>N>>H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin>>arr[i][j][k];
			}
		}
	}
	solve();
	return 0;
}
