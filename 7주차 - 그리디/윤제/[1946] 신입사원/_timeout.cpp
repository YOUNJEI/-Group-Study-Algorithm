#include <iostream>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_person
{
    int docu_eval;
    int meet_eval;
}t_person;

void solve(t_person **arr, int test_case_num, int *test_case_person_num)
{
    int *max_recruit = NULL;
    int flag;
    
    max_recruit = (int*)malloc(sizeof(int) * test_case_num);
    if (max_recruit == NULL)
        return;
    for (int i = 0; i < test_case_num; i++)
        max_recruit[i] = 0;
    for (int _loop = 0; _loop < test_case_num; _loop++)
    {
        for (int i = 0; i < test_case_person_num[_loop]; i++)
        {
            flag = 1;
            for (int j = 0; j < test_case_person_num[_loop]; j++)
            {
                if (arr[_loop][i].docu_eval == 1 || arr[_loop][i].meet_eval == 1)
                    break ;
                if ((arr[_loop][i].docu_eval == test_case_person_num[_loop] || arr[_loop][i].meet_eval == test_case_person_num[_loop])
                    && arr[_loop][i].docu_eval * arr[_loop][i].meet_eval > test_case_person_num[_loop])
                {
                    flag = 0;
                    break ;
                }
                if (arr[_loop][i].docu_eval > arr[_loop][j].docu_eval
                    && arr[_loop][i].meet_eval > arr[_loop][j].meet_eval)
                    {
                        flag = 0;
                        break ;
                    }
            }
            if (flag)
                max_recruit[_loop]++;
        }
    }
    for (int i = 0; i < test_case_num; i++)
        printf("%d\n", max_recruit[i]);
}

int main(void)
{
    int test_case_num;
    int *test_case_person_num = NULL;
    t_person **arr = NULL;

    scanf("%d", &test_case_num);
    arr = (t_person **)malloc(sizeof(t_person *) * test_case_num);
    test_case_person_num = (int *)malloc(sizeof(int) * test_case_num);
    if (arr == NULL || test_case_person_num == NULL)
        return (-1);
    for(int i = 0; i < test_case_num; i++)
    {
        scanf("%d", &test_case_person_num[i]);
        arr[i] = (t_person *)malloc(sizeof(t_person) * test_case_person_num[i]);
        if (arr[i] == NULL)
            return (-1);
        for(int j = 0; j < test_case_person_num[i]; j++)
        {
            scanf("%d %d", &arr[i][j].docu_eval, &arr[i][j].meet_eval);
        }
    }
    solve(arr, test_case_num, test_case_person_num);
    for(int i = 0; i < test_case_num; i++)
        free(arr[i]);
    free(arr);
    return (0);
}