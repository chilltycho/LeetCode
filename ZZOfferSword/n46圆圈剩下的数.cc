/**
 * 0-n-1排成圆圈，从0开始，每次删除第m个数，求最后剩下的数
*/
// 找规律
int f(int n, int m)
{
    if (n == 1)
        return 0;
    int x = f(n - 1, m);
    return (m + x) % n;
}
int lastRemaining(int n, int m)
{
    return f(n, m);
}