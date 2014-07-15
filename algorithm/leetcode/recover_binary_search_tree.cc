// URL: https://oj.leetcode.com/problems/recover-binary-search-tree/
#include "common.h"

class Solution {
 public:
  void recoverTree(TreeNode* root) {
    TreeNode* prev = NULL;
    TreeNode* p1 = NULL;
    TreeNode* p2 = NULL;
    InOrderTraverse(root, prev, p1, p2);
    if (p1 && p2)
      std::swap(p1->val, p2->val);
  }

  void InOrderTraverse(TreeNode* root,
                       TreeNode*& prev,
                       TreeNode*& p1,
                       TreeNode*& p2) {
    if (root == NULL)
      return;

    InOrderTraverse(root->left, prev, p1, p2);
    if (prev && prev->val > root->val) {
      if (!p1)
        p1 = prev;
      p2 = root;
    }

    prev = root;
    InOrderTraverse(root->right, prev, p1, p2);
  }
};

void PrintTree(TreeNode *root) {
  if (root == NULL)
    return;
  PrintTree(root->left);
  std::cout << root->val << " ";
  PrintTree(root->right);
}

int main(int argc, char *argv[]) {
  TreeNode root(7);
  TreeNode l(4);
  TreeNode ll(1);
  TreeNode lr(3);
  TreeNode r(8);

  root.left = &l;
  root.right = &r;
  l.left = &ll;
  l.right = &lr;
  PrintTree(&root);
  std::cout << std::endl;

  Solution s;
  s.recoverTree(&root);
  PrintTree(&root);

  return 0;
}
