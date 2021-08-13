#include "utl.h"
using namespace std;

int main()
{
    vector<int> vi{1, 2, 3, 4, 5};
    auto head = createLinkedList(vi);
    printLinkeList(head);
    deleteLinkedList(head);
}