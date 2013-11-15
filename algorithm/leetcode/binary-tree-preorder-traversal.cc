#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> orders;
    preorder(root, orders);
    return orders;
  }

  void preorder(TreeNode *root, vector<int>& orders) {
    if (root == NULL)
      return;

    orders.push_back(root->val);
    preorder(root->left, orders);
    preorder(root->right, orders);
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  TreeNode root(1);
  TreeNode r(2);
  TreeNode rl(3);

  root.right = &r;
  r.left = &rl;
  vector<int> orders = s.preorderTraversal(&root);
  for (size_t i = 0; i < orders.size(); i++)
    cout << orders[i] << endl;

  return 0;
}
