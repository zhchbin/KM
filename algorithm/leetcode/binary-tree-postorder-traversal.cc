// URL: http://oj.leetcode.com/problems/binary-tree-postorder-traversal/ 
//
// Problem: Given a binary tree, return the postorder traversal of its nodes'
//          values.

#include <algorithm>
#include <iostream>
#include <stack>
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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> order;
    if (root == NULL)
      return order;

    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
      TreeNode* cur = stk.top();
      stk.pop();
      order.push_back(cur->val);
      if (cur->left)
        stk.push(cur->left);
      if (cur->right)
        stk.push(cur->right);
    }

    std::reverse(order.begin(), order.end());
    return order;
  }
};

int main(int argc, char *argv[]) {
  TreeNode root(1);
  TreeNode l(2);
  TreeNode r(5);
  TreeNode ll(3);
  TreeNode lr(4);
  TreeNode rr(6);

  root.left = &l;
  l.left = &ll;
  l.right = &lr;

  root.right = &r;
  r.right = &rr;
  Solution s;
  vector<int> order = s.postorderTraversal(&root);
  for (int i = 0; i < order.size(); ++i)
    cout << order.at(i) << " ";
  cout << endl;
  return 0;
}
