//将链表分隔为k个连续部分，任意两部分长度不超过1,k个部分按在链表中出现顺序输出，排在前面长度大于等于后面长度
#include "utl.h"
vector<ListNode *> splitListToParts(ListNode *root, int k) {
  auto cur = root;
  int N = 0;
  while (cur != nullptr) {
    N++;
    cur = cur->next;
  }
  int width = N / k, rem = N % k;
  vector<ListNode *> res(k, nullptr);
  cur = root;
  for (int i = 0; i < k; i++) {
    auto head = cur;
    // 前rem个多取1
    for (int j = 0; j < width + (i < rem ? 1 : 0) - 1; j++) {
      if (cur != nullptr) {
        cur = cur->next;
      }
    }
    // 将cur移动为下条链的起点
    if (cur != nullptr) {
      auto pre = cur;
      cur = cur->next;
      pre->next = nullptr;
    }
    res[i] = head;
  }
  return res;
}

int main() {
  vector<int> vi{1, 2, 3};
  auto head = createLinkedList(vi);
  auto res = splitListToParts(head, 5);
  for (auto l : res)
    printLinkeList(l);
}
