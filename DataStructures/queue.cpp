#include <iostream>
#include <vector>
using namespace std;
class MyQueue
{
private:
    vector<int> data;
    int p_start;

public:
    MyQueue() { p_start = 0; }
    bool enQueue(int x)
    {
        data.push_back(x);
        return true;
    }
    bool deQueue()
    {
        if (isEmpty())
            return false;
        p_start++;
        return true;
    }
    bool isEmpty()
    {
        return p_start >= data.size();
    }
    int Front()
    {
        return data[p_start];
    }
};
//tailIndex=(headIndex+count-1) % capacity
class MyCircularQueue
{
private:
    int *queue;
    int headIndex;
    int count;    //当前队列长度
    int capacity; //分配数组长度

public:
    MyCircularQueue(int k)
    {
        capacity = k;
        queue = new int[k];
        headIndex = count = 0;
    }
    ~MyCircularQueue()
    {
        delete[] queue;
    }
    bool isEmpty()
    {
        return count == 0;
    }
    bool isFull()
    {
        return count == capacity;
    }
    bool enQueue(int value)
    {
        if (isFull())
            return false;
        queue[(headIndex + count) % capacity] = value;
        count += 1;
        return true;
    }
    bool deQueue()
    {
        if (isEmpty())
            return false;
        headIndex = (headIndex + 1) % capacity;
        count -= 1;
        return true;
    }
    int Front()
    {
        if (isEmpty())
            return -1;
        return queue[headIndex];
    }
    int Rear()
    {
        if (isEmpty())
            return -1;
        int tailIndex = (headIndex + count - 1) % capacity;
        return queue[tailIndex];
    }
};

class MyCircularQueue_1
{
private:
    vector<int> data;
    int head;
    int tail;
    int size;

public:
    MyCircularQueue_1(int k)
    {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }
    bool enQueue(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
            head = 0;
        tail = (tail + 1) % size;
        data[tail] = value;
        return true;
    }
    bool deQueue()
    {
        if (isEmpty())
            return false;
        if (head == tail)
        {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }
    bool isEmpty()
    {
        return head == -1;
    }
    bool isFull()
    {
        return ((tail + 1) % size) == head;
    }
};

struct Node
{
    int value;
    Node *nextNode;
    Node()
    {
        nextNode = nullptr;
    }
    Node(int x)
    {
        nextNode = nullptr;
        value = x;
    }
};

class MyListQueue
{
private:
    Node *head, *tail;
    int count;
    int capacity;

public:
    MyListQueue(int k)
    {
        capacity = k;
        head = tail = nullptr;
        count = 0;
    }
    bool enQueue(int value)
    {
        if (isFull())
            return false;
        Node *newnode = new Node(value);
        if (count == 0)
            head = tail = newnode;
        else
        {
            tail->nextNode = newnode;
            tail = newnode;
        }
        count += 1;
        return true;
    }
    bool deQueue()
    {
        if (isEmpty())
            return false;
        head = head->nextNode;
        count -= 1;
        return true;
    }
    int Front()
    {
        if (isEmpty())
            return -1;
        return head->value;
    }
    int Rear()
    {
        if (isEmpty())
            return -1;
        return tail->value;
    }
    bool isEmpty()
    {
        return count == 0;
    }
    bool isFull()
    {
        return count == capacity;
    }
};

int main()
{
    MyListQueue m1(3);
    m1.enQueue(1);
    m1.enQueue(2);
    m1.enQueue(3);
    m1.enQueue(4);
    cout << m1.Rear();
    cout << m1.isFull();
    cout << m1.deQueue();
    cout << m1.enQueue(4);
    cout << m1.Rear();
}