/*
设计和构建一个“最近最少使用”缓存，该缓存会删除最近最少使用的项目。缓存应该从键映射到值(允许你插入和检索特定键对应的值)，并在初始化时指定最大容量。当缓存被填满时，它应该删除最近最少使用的项目。
它应该支持以下操作： 获取数据 get 和 写入数据 put 。
获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。
*/
#include <map>
#include <queue>
#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;
class LRUCache
{
private:
    size_t cap = 0;
    list<pair<int, int>> cache;                            // 键-值
    unordered_map<int, list<pair<int, int>>::iterator> mp; // 键，在链表中位置

public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }
    int get(int key)
    {
        auto it = mp.find(key);
        // 未找到
        if (it == mp.end())
            return -1;

        // 找到迭代器
        auto target_it = it->second;
        pair<int, int> n{target_it->first, target_it->second};
        // 重新放到链表头部
        cache.push_front(n);
        // 删除旧的
        cache.erase(target_it);
        mp[key] = cache.begin();
        return n.second;
    }
    void put(int key, int value)
    {
        auto it = mp.find(key);
        // 已经存在，先删除，需要插入链表头部
        if (it != mp.end())
        {
            cache.erase(it->second);
            mp.erase(key);
        }

        pair<int, int> n{key, value};
        cache.push_front(n);
        mp.emplace(key, cache.begin());
        // 超出容量，删除末尾的
        if (cache.size() > cap)
        {
            mp.erase(cache.back().first);
            cache.pop_back();
        }
    }
    void print()
    {
        for (auto i : cache)
            cout << i.first << ' ' << i.second << ' ';
        cout << endl;
    }
};

int main()
{
    size_t size = 10;
    LRUCache l(size);
    for (size_t i = 0; i < size; ++i)
        l.put(i, i);
    l.print();
    cout << l.get(2) << endl;
    l.print();
    l.get(3);
    l.print();
}