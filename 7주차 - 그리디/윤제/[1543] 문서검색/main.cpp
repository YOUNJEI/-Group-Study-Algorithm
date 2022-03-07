#include <cstring>
#include <iostream>
#include <stdio.h>

using namespace std;

#define DOCU_BUFFER_SIZE 2501
#define FIND_BUFFER_SIZE 51

int str_find_count(char *src, char *char_set)
{
    int count = 0;
    int flag;
    char *cur_char_set;
    char *temp;

    while (*src != '\0')
    {
        if (*src == char_set[0])
        {
            flag = 1;
            cur_char_set = char_set;
            temp = src;
            while (*cur_char_set != '\0')
            {
                if (*src != *cur_char_set)
                {
                    flag = 0;
                    break;
                }
                src++;
                cur_char_set++;
            }
            if (flag)
            {
                count++;
                src--;
            }
            else
                src = temp;
        }
        src++;
    }
    return (count);
}

int main(void)
{
    char _docu[DOCU_BUFFER_SIZE] = {0,};
    char _find[FIND_BUFFER_SIZE] = {0,};
    string temp;
    int null_idx;

    getline(cin, temp);
    null_idx = temp.copy(_docu, temp.size(), 0);
    _docu[null_idx] = '\0';

    getline(cin, temp);
    null_idx = temp.copy(_find, temp.size(), 0);
    _find[null_idx] = '\0';

    cout<<str_find_count(_docu, _find);

    return (0);
}
