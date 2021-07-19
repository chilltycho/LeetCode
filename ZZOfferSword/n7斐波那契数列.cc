int Fibonacci(int n)
{
    if (n < 2)
        return n;
    int pre = 0;
    int cur = 1;
    for (int i = 2; i <= n; ++i)
    {
        int tmp = cur;
        cur = cur + pre;
        pre = tmp;
    }
    return cur;
}