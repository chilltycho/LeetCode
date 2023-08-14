/*给定两个单词begin,end，和字典，找出所有从begin
到end的最短转换序列。每次转换只能改变一个字母。
转换后单词必须是字典中单词。*/
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
/**
 * 将每个单词抽象为点，建立图模型。给每个单词标号。同时创建id到word映射
 * cost数组，cost[i]表示beginword到第i个点代价。
 */
unordered_map<string, int> wordId;
vector<string> idWord;
vector<vector<int>> edges;

vector<vector<string>> findLadders(string beginWord, string endWord,
                                   vector<string> &wordList) {
  int id = 0;
  for (auto word : wordList) {
    if (!wordId.count(word)) {
      wordId[word] = id++;
      idWord.push_back(word);
    }
  }
  if (!wordId.count(endWord))
    return {};

  if (!wordId.count(beginWord)) {
    wordId[beginWord] = id++;
    idWord.push_back(beginWord);
  }

  //建立图
  edges.resize(idWord.size());
  for (int i = 0; i < idWord.size(); i++) {
    for (int j = i + 1; j < idWord.size(); j++) {
      if (transformCheck(idWord[i], idWord[j])) {
        edges[i].push_back(j);
        edges[j].push_back(i);
      }
    }
  }

  //目标id
  int dest = wordId[endWord];
  vector<vector<string>> res;
  queue<vector<int>> q;
  vector<int> cost(id, INT_MAX);
  //起点加入队列，cost设置为0
  q.push(vector<int>{wordId[beginWord]});
  cost[wordId[beginWord]] = 0;

  //开始广度搜索
  while (!q.empty()) {
    vector<int> now = q.front();
    q.pop();
    int last = now.back();
    //遇到终点
    if (last == dest) {
      vector<string> tmp;
      for (auto i : now)
        tmp.push_back(idWord[i]);
      res.push_back(tmp);
    } else {
      for (int i = 0; i < edges[last].size(); i++) {
        int to = edges[last][i];
        if (cost[last] + 1 <= cost[to]) {
          cost[to] = cost[last] + 1;
          vector<int> tmp(now);
          tmp.push_back(to);
          q.push(tmp);
        }
      }
    }
  }
  return res;
}

bool transformCheck(string &s1, string &s2) {
  int differences = 0;
  for (int i = 0; i < s1.size() && differences < 2; i++) {
    if (s1[i] != s2[i])
      ++differences;
  }
  return differences == 1;
}
