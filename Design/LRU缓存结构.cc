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
        if (mp.count(key))
        {
            auto kv = mp[key];
            cache.push_front(make_pair(kv->first, kv->second));
            cache.erase(kv);
            mp[key] = cache.begin();
            return cache.front().second;
        }
        return -1;
    }
    void put(int key, int value)
    {
        if (mp.count(key))
        {
            auto kv = mp[key];
            cache.erase(kv);
            cache.push_front(make_pair(key, value));
            mp[key] = cache.begin();
        }
        else
        {
            cache.push_front(make_pair(key, value));
            mp[key] = cache.begin();
            if (cache.size() > cap)
            {
                mp.erase(cache.back().first);
                cache.pop_back();
            }
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
    size_t size = 2;
    LRUCache l(size);
    l.put(1, 1);
    l.print();
    l.put(2, 2);
    l.print();
    cout << l.get(1) << endl;
    l.put(3, 3);
    l.print();
    cout << l.get(2) << endl;
    l.put(4, 4);
    l.print();
    cout << l.get(1) << endl;
    l.get(3);
    l.get(4);
}