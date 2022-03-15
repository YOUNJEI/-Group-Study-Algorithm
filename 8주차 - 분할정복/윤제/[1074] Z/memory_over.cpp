#include <stdio.h>
#include <stdlib.h>

// global variable g_arr
int **g_arr = NULL;

int power(int power_num, int N)
{
	int result = 1;
	for (int i = 0; i < N; i++)
	{
		result *= power_num;
	}
	return (result);
}

int is_final_box(int _start_pos_x, int _start_pos_y, int _end_pos_x, int _end_pos_y)
{
	if (_start_pos_x == _end_pos_x && _start_pos_y == _end_pos_y)
		return (1);
	return (0);
}

void solve(int _start_pos_x, int _start_pos_y, int _end_pos_x, int _end_pos_y)
{
	static int count = 0;
	if (is_final_box(_start_pos_x, _start_pos_y, _end_pos_x, _end_pos_y))
	{
		g_arr[_start_pos_x][_start_pos_y] = count;
		count++;
	}
	else
	{
		solve(_start_pos_x, _start_pos_y, (_start_pos_x + _end_pos_x) / 2, (_start_pos_y + _end_pos_y) / 2);
		solve(_start_pos_x, (_start_pos_y + _end_pos_y + 1) / 2, (_start_pos_x + _end_pos_x) / 2, _end_pos_y);
		solve((_start_pos_x + _end_pos_x + 1) / 2, _start_pos_y, _end_pos_x, (_start_pos_y + _end_pos_y) / 2);
		solve((_start_pos_x + _end_pos_x + 1) / 2, (_start_pos_y + _end_pos_y + 1) / 2, _end_pos_x, _end_pos_y);
	}
}

int main(void)
{
	int N;
	int c,r;

	scanf("%d %d %d", &N, &c, &r);
	N = power(2, N);
	g_arr = (int **)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
	{
		g_arr[i] = (int *)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++)
			g_arr[i][j] = 0;
	}
	solve(0, 0, N-1, N-1);
	printf("%d\n", g_arr[c][r]);
	return (0);
}
