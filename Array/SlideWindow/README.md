滑动窗口是暴力解法的优化
---------------------
将数组里双重for循环改写成一次遍历:
1.右边界先向右移动，然后左边界向右移动，交替进行
2.不会错过最优解
```C
int left=0,right=0;
while(right<s.size())
{
    window.add(s[right]);
    right++;
    while(window needs shrink)
    {
        window.remove(s[left]);
        left++;
    }
}
```