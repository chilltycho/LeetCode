#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct ListNode
{
    int x;
    shared_ptr<ListNode> next;
    ListNode(int x_) : x(x_), next(nullptr) {}
    ListNode() : x(0), next(nullptr) {}
};

shared_ptr<ListNode> createList(const vector<int> &nums)
{
    if (nums.empty())
        return nullptr;
    auto head = make_shared<ListNode>(nums[0]);
    auto res = head;
    for (int i = 1; i < nums.size(); ++i)
    {
        head->next = make_shared<ListNode>(nums[i]);
        head = head->next;
    }
    return res;
}

void ListPrint(shared_ptr<ListNode> head)
{
    while (head)
    {
        cout << head->x << ' ';
        head = head->next;
    }
}

int main()
{
    shared_ptr<int> sp1 = make_shared<int>(1);
    sp1 = make_shared<int>(2);
}