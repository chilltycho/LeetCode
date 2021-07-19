// 可跳1级或2级，求跳上n级总有多少跳法
int jumpFloor(int number)
{
    if (number == 0 || number == 1)
        return 1;
    int pre = 1, cur = 1;
    for (int i = 2; i <= number; ++i)
    {
        int tmp = cur;
        cur = pre + cur;
        pre = tmp;
    }
    return cur;
}