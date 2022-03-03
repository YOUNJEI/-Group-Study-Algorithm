#include <stdio.h>

void test(int tape_count)
{
    tape_count++;
}

int main(void)
{
    int leak_num;
    int tape_len;
    static int tape_count = 0;
    test(tape_count);
    //scanf("%d %d", &leak_num, &tape_len);
    //  함수 호출
    printf("%d\n", tape_count);
}