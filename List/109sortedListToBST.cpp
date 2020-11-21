//将有序链表转换为二叉搜索树
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
ListNode* getMedian(ListNode* left,ListNode* right)
{
    auto fast=left,slow=left;
    while(fast!=right&&fast->next!=right)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
TreeNode* buildTree(ListNode* left,ListNode* right)
{
    if(left==right)
        return nullptr;
    auto mid=getMedian(left,right);
    auto root=new TreeNode(mid->val);
    root->left=buildTree(left,mid);
    root->right=buildTree(mid->next,right);
    return root;
}
//根节点，每次取链表元素中位数作为根节点,时间复杂度O(nlogn),空间复杂度为树深度O(logn)
TreeNode* sortedListToBST(ListNode* head)
{
    return buildTree(head,nullptr);
}

TreeNode* sortedListToBST_1(ListNode* head)
{
    if(head==nullptr)
        return nullptr;
    if(head->next==nullptr)
        return new TreeNode(head->val);
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* pre=nullptr;
    while(fast!=nullptr&&fast->next!=nullptr)
    {
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    pre->next=nullptr;
    auto node=new TreeNode(slow->val);
    node->left=sortedListToBST_1(head);//从head到pre
    node->right=sortedListToBST_1(slow->next);//从slow->next到末尾
    return node;
}