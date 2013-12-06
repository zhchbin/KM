// URL: http://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
//
// Problem: Given a binary tree, return the bottom-up level order traversal of
//          its nodes' values. (ie, from left to right, level by level from leaf
//          to root).

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > orders;
    levelOrderRecursive(root, 0, orders);
    std::reverse(orders.begin(), orders.end());

    return orders;
  }

  void levelOrderRecursive(TreeNode* root,
                           int level,
                           vector<vector<int> >& orders) {
    if (root == NULL)
      return;

    if (orders.size() <= level)
      orders.push_back(vector<int>());

    orders[level].push_back(root->val);
    levelOrderRecursive(root->left, level + 1, orders);
    levelOrderRecursive(root->right, level + 1, orders);
  }
};

int main(int argc, char *argv[]) {
  TreeNode root(3);
  TreeNode l(9);
  TreeNode r(20);
  TreeNode rl(15);
  TreeNode rr(7);
  root.left = &r;
  root.right = &l;
  r.left = &rl;
  r.right = &rr;
  Solution s;
  vector<vector<int> > orders = s.levelOrderBottom(&root);
  for (int i = 0; i < orders.size(); ++i) {
    for (int j = 0; j < orders[i].size(); ++j)
      cout << orders[i][j] << " ";
    cout << endl;
  }

  return 0;
}
