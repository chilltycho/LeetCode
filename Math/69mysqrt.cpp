int mysqrt(int x)
{
    int l = 0, r = x, ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if ((long long)mid * mid <= x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

int mysqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
    int l = 0, r = x;
    while (l < r)
    {
        int m = l + (r - l + 1) / 2;
        if (m > x / m)
            r = m - 1;
        else
            l = m;
    }
    return l;
}