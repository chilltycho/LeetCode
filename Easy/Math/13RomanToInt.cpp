#include <unordered_map>
#include <iostream>
using namespace std;
/*
I V  X  L  C    D     M
1 5 10 50  100  500  1000

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
否则小的在大的右边

1.构建一个字典记录所有罗马数字子串，注意长度为2的子串记录的值是（实际值 - 子串内左边罗马数字代表的数值）
2.这样一来，遍历整个 ss 的时候判断当前位置和前一个位置的两个字符组成的字符串是否在字典内，如果在就记录值，不在就说明当前位置不存在小数字在前面的情况，直接记录当前位置字符对应值
举个例子，遍历经过 IVIV 的时候先记录 II 的对应值 11 再往前移动一步记录 IVIV 的值 33，加起来正好是 IVIV 的真实值 44。max 函数在这里是为了防止遍历第一个字符的时候出现 [-1:0][−1:0] 的情况
*/
int romanToInt(string s)//不能分辨错误如IIII
{
    unordered_map<string, int> m{{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};
    int r = m[s.substr(0, 1)];
    for (int i = 1; i < s.size(); ++i)//两两一个读取
    {
        string two = s.substr(i - 1, 2);
        string one = s.substr(i, 1);
        r += m[two] ? m[two] : m[one];
    }
    return r;
}

int main()
{
    cout<<romanToInt("XL");
}