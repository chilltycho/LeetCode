//串联所有单词的子串,所有单词长度相同，返回能串联的开始下标
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//假设s长度为n，words里面m个单词，时间复杂度O(n*m)
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
    //每次移动一个字符
    for (int i = 0; i < s.size() - wordNum * wordLen + 1; i++)
    {
        unordered_map<string, int> hasWords; //窗口中包含的单词
        int num = 0;
        while (num < wordNum)
        {
            auto word = s.substr(i + num * wordLen, wordLen);
            if (allWords.find(word) != allWords.end())
            {
                hasWords[word]++;
                if (hasWords[word] > allWords[word])
                    break;
            }
            else
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
    int wordNum = words.size();
    int wordLen = words[0].size();
    unordered_map<string, int> allWords;
    for (auto &w : words)
        allWords[w]++;
    //将移动分成wordLen类情况，从0、1、2、..开始每次移动一个单词
    for (int j = 0; j < wordLen; j++)
    {
        unordered_map<string, int> hasWords;
        int num = 0;
        for (int i = j; i < s.size() - wordLen * wordNum + 1; i = i + wordLen)
        {
            bool isRemoved = false;
            while (num < wordNum)
            {
                auto word = s.substr(i + num * wordLen, wordLen);
                if (allWords.count(word))
                {
                    hasWords[word]++;
                    //当某单词数量大于某单词需要数量
                    if (hasWords[word] > allWords[word])
                    {
                        isRemoved = true;
                        int removeNum = 0;
                        while (hasWords[word] > allWords[word])
                        {
                            auto firstword = s.substr(i + removeNum * wordLen, wordLen);
                            hasWords[firstword]--;
                            removeNum++;
                        }
                        num = num - removeNum + 1;
                        i = i + (removeNum - 1) * wordLen;
                        break;
                    }
                }
                else//当包含不合法单词时
                {
                    hasWords.clear();
                    i = i + num * wordLen;
                    num = 0;
                    break;
                }
                num++;
            }
            if(num==wordNum)
                res.push_back(i);
            //当全部符合时，后移一个单词，找下一个可能下标
            if(num>0&&!isRemoved)
            {
                auto firstWord=s.substr(i,wordLen);
                hasWords[firstWord]--;
                num--;
            }
        }
    }
    return res;
}

int main()
{
    string s{"barfoothefoobarman"};
    vector<string> words{"foo", "bar"};
    auto res = findSubstring(s, words); //[0,9]
    for(auto c:res)
        cout<<c<<' ';
}