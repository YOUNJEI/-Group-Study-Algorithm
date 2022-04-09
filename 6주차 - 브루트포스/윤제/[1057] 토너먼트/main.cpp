#include <stdio.h>

int my_abs(int n)
{
    if (n >= 0)
        return (n);
    else
        return (-n);
}

int get_left_num(int n1, int n2)
{
    if (n1 <= n2)
        return (n1);
    else
        return (n2);
}

int get_right_num(int n1, int n2)
{
    if (n1 <= n2)
        return (n2);
    else
        return (n1);
}

void move_next_round(int *n)
{
    if (*n % 2 == 0)
        *n = *n / 2;
    else
        *n = (*n / 2) + 1;
}

int solve(int total_person, int jimin_num, int hansu_num)
{
    int count = 1;
    while(1)
    {
        if (my_abs(jimin_num - hansu_num) == 1)
        {
            if (get_left_num(jimin_num, hansu_num) % 2 == 1)
            {
                return (count);
            }
        }
        move_next_round(&jimin_num);
        move_next_round(&hansu_num);
        count++;
    }
    // 대결하지 않는 경우가 있긴 한가??
    return (-1);
}

int main(void)
{
    int total_person;
    int jimin_num;
    int hansu_num;

    scanf("%d %d %d", &total_person, &jimin_num, &hansu_num);
    printf("%d", solve(total_person, jimin_num, hansu_num));
    return (0);
}