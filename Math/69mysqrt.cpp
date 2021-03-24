int mysqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
    int left = 1;
    int right = x / 2;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int cur = x / mid;
        if (cur > mid)
            left = mid + 1;
        else
            right = mid;
    }
    return x / left == left ? left : left - 1;
}