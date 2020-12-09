/*给定单词数组和长度maxWidth，重新排版单词，使每行恰好有maxWidth个字符，且左右两端对齐
文本最后一行应左对齐，单词间不插入额外空格*/
#include <vector>
#include <iostream>
using namespace std;
string fillWords(vector<string> &words, int bg, int ed, int maxWidth, bool lastLine = false)
{
    int wordCount = ed - bg + 1;
    int spaceCount = maxWidth + 1 - wordCount; // 除去每个单词尾部空格， + 1 是最后一个单词的尾部空格的特殊处理
    for (int i = bg; i <= ed; i++)
    {
        spaceCount -= words[i].size(); // 除去所有单词的长度
    }

    int spaceSuffix = 1;                                                  // 词尾空格
    int spaceAvg = (wordCount == 1) ? 1 : spaceCount / (wordCount - 1);   // 额外空格的平均值
    int spaceExtra = (wordCount == 1) ? 0 : spaceCount % (wordCount - 1); // 额外空格的余数

    string ans;
    for (int i = bg; i < ed; i++)
    {
        ans += words[i]; // 填入单词
        if (lastLine)    // 特殊处理最后一行
        {
            fill_n(back_inserter(ans), 1, ' ');
            continue;
        }
        fill_n(back_inserter(ans), spaceSuffix + spaceAvg + ((i - bg) < spaceExtra), ' '); // 根据计算结果补上空格
    }
    ans += words[ed];                                       // 填入最后一个单词
    fill_n(back_inserter(ans), maxWidth - ans.size(), ' '); // 补上这一行最后的空格
    return ans;
}
vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> ans;
    int cnt = 0;
    int bg = 0;
    for (int i = 0; i < words.size(); i++)
    {
        cnt += words[i].size() + 1;
        if (i + 1 == words.size() || cnt + words[i + 1].size() > maxWidth)
        {
            //若是最后一个单词，或加上下一个单词就超过长度，即可凑成一行。
            ans.push_back(fillWords(words, bg, i, maxWidth, i + 1 == words.size()));
            bg = i + 1;
            cnt = 0;
        }
    }
    return ans;
}