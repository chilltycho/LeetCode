/*
高效存储和检索字符串数据集中的键。
void insert(string word): 插入字符word
bool search(string word)：如果word存在，返回true，否则false
bool startWith(string prefix)：如果已插入word前缀为prefix，返回true。否则false
*/
#include <string>
using namespace std;

// Trie(try)为多叉树模型
struct TrieNode
{
    bool isEnd;         // 该节点是否是一个串的结束
    TrieNode *next[26]; // 字母映射表
};

class Trie
{
private:
    bool isEnd=false;
    Trie *next[26]{};

public:
    Trie(){isEnd=false;};
    ~Trie();

    void insert(string word)
    {
        Trie *node = this;
        for (auto c : word)
        {
            if (node->next[c - 'a'] == nullptr)
                node->next[c - 'a'] = new Trie();
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie *node = this;
        for (auto c : word)
        {
            node = node->next[c - 'a'];
            if (node == nullptr)
                return false;
        }
        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (auto c : prefix)
        {
            node = node->next[c - 'a'];
            if (node == nullptr)
                return false;
        }
        return true;
    }
};
