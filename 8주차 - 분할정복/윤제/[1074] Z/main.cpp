#include <stdio.h>
#include <stdlib.h>

/*	Global */
int r,c;

int power(int power_num, int N)
{
	int result = 1;
	for (int i = 0; i < N; i++)
	{
		result *= power_num;
	}
	return (result);
}

int solve(int _start_pos_x, int _start_pos_y, int _end_pos_x, int _end_pos_y, int size)
{
	static int count = 0;
	bool flag = true;
	if (r == _start_pos_x && c == _start_pos_y)
	{
		printf("%d\n", count);
		return (1);
	}
	if (r >= _start_pos_x && r <= _start_pos_x + (size - 1))
	{
		if (c >= _start_pos_y && c <= _start_pos_y + (size - 1))
		{
			flag = false;
					if (solve(_start_pos_x, _start_pos_y, (_start_pos_x + _end_pos_x) / 2, (_start_pos_y + _end_pos_y) / 2, size / 2))
			return (1);
		if (solve(_start_pos_x, (_start_pos_y + _end_pos_y + 1) / 2, (_start_pos_x + _end_pos_x) / 2, _end_pos_y, size / 2))
			return (1);
		if (solve((_start_pos_x + _end_pos_x + 1) / 2, _start_pos_y, _end_pos_x, (_start_pos_y + _end_pos_y) / 2, size / 2))
			return (1);
		if (solve((_start_pos_x + _end_pos_x + 1) / 2, (_start_pos_y + _end_pos_y + 1) / 2, _end_pos_x, _end_pos_y, size / 2))
			return (1);
		}
	}
	if (flag)
	{
		count += size * size;
	}
	return (0);
}

int main(void)
{
	int N;

	// int r, int c -> global varaious
	scanf("%d %d %d", &N, &r, &c);
	N = power(2, N);
	solve(0, 0, N-1, N-1, N);
	return (0);
}
