// URL: http://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/

#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void flatten(TreeNode* root) {
    if (!root)
      return;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    if (left) {
      root->right = root->left;
      root->left = NULL;
      TreeNode* right_most = root->right;
      while (right_most->right)
        right_most = right_most->right;
      right_most->right = right;
    }

    flatten(root->right);
  }
};

class NonRecursiveSolution {
 public:
  void flatten(TreeNode* root) {
    while (root) {
      if (root->left) {
        TreeNode* right_most = root->left;
        while (right_most->right)
          right_most = right_most->right;
        right_most->right = root->right;
        root->right = root->left;
        root->left = NULL;
      }

      root = root->right;
    }
  }
};

int main(int argc, char *argv[]) {
  TreeNode root(1);
  TreeNode l(2);
  TreeNode r(5);
  TreeNode rl(6);
  TreeNode ll(3);
  TreeNode lr(4);
  root.left = &l;
  root.right = &r;
  l.left = &ll;
  l.right = &lr;
  r.left = &rl;

  NonRecursiveSolution s;

  s.flatten(&root);
  TreeNode* p = &root;
  while (p) {
    cout << p->val << " ";
    p = p->right;
  }
  cout << endl;

  return 0;
}
