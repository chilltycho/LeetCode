//串联所有单词的子串,所有单词长度相同，返回能串联的开始下标
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> findSubstring_1(string s, vector<string> &words)
{
    vector<int> res;
    if (words.empty())
        return res;
    int wordNum = words.size();
    int wordLen = words[0].size();
    unordered_map<string, int> allWords;
    for (auto &w : words)
        allWords[w]++;
    for (int i = 0; i < s.size() - wordNum * wordNum + 1; i++)
    {
        unordered_map<string, int> hasWords;
        int num = 0;
        while (num < wordNum)
        {
            auto word = s.substr(i + num * wordLen, wordLen);
            if (allWords.find(word) != allWords.end())
                hasWords[word]++;
            else
                break;
            if (hasWords[word] > allWords[word])
                break;
            num++;
        }
        if (num == wordNum)
            res.push_back(i);
    }
    return res;
}
vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> res;
    if (words.empty())
        return res;
    int n = s.size(), m = words.size(), w = words[0].size();
    unordered_map<string, int> tot;
    for (auto &wo : words)
        tot[wo]++;
    //枚举起点i，将字符按照words中单词长度分段
    for (int i = 0; i < w; i++)
    {
        int suc = 0;
        unordered_map<string, int> window;
        for (int j = i; j + w <= n; j += w) //截取每个单词
        {
            if (j >= i + m * w)
            {
                string cur = s.substr(j - m * w, w);
                window[cur]--;
                if (window[cur] < tot[cur])
                    suc--;
            }
            string cur = s.substr(j, w);
            window[cur]++;
            if (window[cur] <= tot[cur])
                suc++;
            if (suc == m)
                res.push_back(j - (m - 1) * w);
        }
    }
    return res;
}

int main()
{
    string s{"barfoothefoobarman"};
    vector<string> words{"foo", "bar"};
    auto res = findSubstring(s, words); //[0,9]
}