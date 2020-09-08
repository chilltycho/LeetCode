/*给定两单词(beginWord，endWord)和一个字典，找到从beginWord到endWord
最短转换序列长度。每次转换只能改变一个字母，转换过程中单词必须是字典中单词。
若不存在转换序列，返回0.所有单词具有相同长度。所有单词由小写字母组成。字典中不存在重复单词。
beginWord和endWord非空且二者不相同*/
#include <vector>
#include <cassert>
#include <iostream>
#include<unordered_set>
using namespace std;
//求图最短路径，BFS，转换可逆，故为无向图
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    if(wordList.empty())
        return 0;
    unordered_set<string> wordSet;
    for(auto c:wordList)
        wordSet.insert(c);
}

int main()
{
    string s1{"hit"};
    string s2 = "cog";
    vector<string> words1{"hot", "dot", "dog", "lot", "log", "cog"};
    assert(5 == ladderLength(s1, s2, words1));

    string s3 = "hit";
    string s4 = "cog";
    vector<string> words2{"hot", "dot", "dog", "lot", "log"};
    assert(0 == ladderLength(s3, s4, words2));
}