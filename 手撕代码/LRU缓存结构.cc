/*
删除最近最少使用项目。
设计LRU缓存结构，结构在构造时确定大小，假设大小为K。
set(key,value):将记录(key,value)插入该结构
get(key)：返回key对应value值

要求：
1. set和get方法时间复杂度为O(1)，
2. 某个key的set或get操作一旦发生，认为key的记录成了最常使用的
3. 当缓存的大小超过K时，移除最不经常使用的记录，即set或get最久远的
若opt=1，接下来两个整数x, y，表示set(x, y)
若opt=2，接下来一个整数x，表示get(x)，若x未出现过或已被移除，则返回-1
对于每个操作2，输出一个答案

输入：[[1,1,1],[1,2,2],[1,3,2],[2,1],[1,4,4],[2,2]],3
返回值：[1,-1]
第一次操作后：最常使用的记录为("1", 1)
第二次操作后：最常使用的记录为("2", 2)，("1", 1)变为最不常用的
第三次操作后：最常使用的记录为("3", 2)，("1", 1)还是最不常用的
第四次操作后：最常用的记录为("1", 1)，("2", 2)变为最不常用的
第五次操作后：大小超过了3，所以移除此时最不常使用的记录("2", 2)，
加入记录("4", 4)，并且为最常使用的记录，然后("3", 2)变为最不常使用的记录
*/
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;
struct Node
{
    Node(int k = 0, int v = 0) : key(k), val(v) {}
    int key;
    int val;
};
class Solution
{
private:
    list<Node> L;// 头部是最新的
    unordered_map<int, list<Node>::iterator> H;//O(1)查找
    int cap; // 容量

public:
    vector<int> LRU(vector<vector<int>> &operators, int k)
    {
        cap = k;
        vector<int> ans;
        for (auto &input : operators)
        {
            if (input[0] == 1)
            {
                set(input[1], input[2]);
            }
            else
            {
                ans.push_back(get(input[1]));
            }
        }
        return ans;
    }
    //删除
    int remove(std::list<Node>::iterator &ite)
    {
        int key = ite->key;
        int val = ite->val;
        L.erase(ite);
        H.erase(key);
        return val;
    }
    // 添加到头部
    void add(int key, int val)
    {
        L.push_front(Node(key, val));
        H[key] = L.begin();
        if (L.size() > cap) //超容量，删除尾部
        {
            auto last = L.end();
            --last;
            remove(last);
        }
    }
    void set(int x, int y)
    {
        auto ite = H.find(x);
        //已经存在，删除了再添加到头部
        if (ite != H.end())
        {
            remove(ite->second);
        }
        add(x, y);
    }
    int get(int x)
    {
        int val = 0;
        //已经存在，删除了再添加到头部
        auto ite = H.find(x);
        if (ite != H.end())
        {
            val = remove(ite->second);
            add(x, val);
            return val;
        }
        return -1;
    }
};