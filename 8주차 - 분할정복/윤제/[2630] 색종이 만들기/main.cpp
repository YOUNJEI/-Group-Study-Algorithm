#include <stdio.h>
#include <stdlib.h>

// global variable g_arr
int **g_arr = NULL;

int is_filled_one_color(int _start_pos_x, int _start_pos_y, int _end_pos_x, int _end_pos_y)
{
	int target = g_arr[_start_pos_x][_start_pos_y];

	for (int i = _start_pos_x; i <= _end_pos_x; i++)
	{
		for (int j = _start_pos_y; j <= _end_pos_y; j++)
		{
			if (g_arr[i][j] != target)
				return (-1);
		}
	}
	return (target);
}

void solve(int _start_pos_x, int _start_pos_y, int _end_pos_x, int _end_pos_y, int depth)
{
	static int count_0 = 0;
	static int count_1 = 0;
	int result = is_filled_one_color(_start_pos_x, _start_pos_y, _end_pos_x, _end_pos_y);
	if (result == 0)
		count_0++;
	else if (result == 1)
		count_1++;
	else
	{
		solve(_start_pos_x, _start_pos_y, (_start_pos_x + _end_pos_x) / 2, (_start_pos_y + _end_pos_y) / 2, depth + 1);
		solve(_start_pos_x, (_start_pos_y + _end_pos_y + 1) / 2, (_start_pos_x + _end_pos_x) / 2, _end_pos_y, depth + 1);
		solve((_start_pos_x + _end_pos_x + 1) / 2, _start_pos_y, _end_pos_x, (_start_pos_y + _end_pos_y) / 2, depth + 1);
		solve((_start_pos_x + _end_pos_x + 1) / 2, (_start_pos_y + _end_pos_y + 1) / 2, _end_pos_x, _end_pos_y, depth + 1);
	}
	if (depth == 0)
	{
		printf("%d\n", count_0);
		printf("%d", count_1);
	}
}

int main(void)
{
	int N;

	scanf("%d", &N);
	g_arr = (int **)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
	{
		g_arr[i] = (int *)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++)
			scanf("%d", &g_arr[i][j]);
	}
	solve(0, 0, N-1, N-1, 0);
	return (0);
}
