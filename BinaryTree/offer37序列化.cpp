//将[1,2,3,null,null,4,5]反序列化为树。
#include "TreeNode.h"
#include <sstream>
using namespace std;
// bfs
string serialize(TreeNode *root) {
  if (root == nullptr)
    return {};
  ostringstream out;
  queue<TreeNode *> mq;
  mq.push(root);
  while (!mq.empty()) {
    auto temp = mq.front();
    mq.pop();
    if (temp) {
      out << temp->val << " ";
      mq.push(temp->left);
      mq.push(temp->right);
    } else
      out << "null ";
  }
  return out.str();
}

TreeNode *deserialize(string data) {
  if (data.empty())
    return nullptr;

  stringstream ss(data);
  int tmp;
  ss >> tmp;
  auto head = new TreeNode(tmp);
  queue<TreeNode *> buffer;
  buffer.push(head);
  while (!buffer.empty()) {
    auto node = buffer.front();
    buffer.pop();
    string str;
    ss >> str;
    if (str != "null") {
      node->left = new TreeNode(stoi(str));
      buffer.push(node->left);
    }
    ss >> str;
    if (str != "null") {
      node->right = new TreeNode(stoi(str));
      buffer.push(node->right);
    }
  }
  return head;
}

// dfs
string serialize_dfs(TreeNode *root) {
  if (root == nullptr)
    return "null";
  return to_string(root->val) + " " + serialize_dfs(root->left) + " " +
         serialize_dfs(root->right);
}

int main() {
  vector<int> vi{1, 2, 3, -1, -1, 4, 5};
  auto root = vecToTree(vi);
  preprint(root);
  auto res = serialize_dfs(root);
  cout << res << endl;
  auto t1 = deserialize(res);
  preprint(t1);
}

