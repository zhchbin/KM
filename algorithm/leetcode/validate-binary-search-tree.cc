// URL: https://oj.leetcode.com/problems/validate-binary-search-tree/

#include "common.h"
#include <iostream>
#include <climits>

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, INT_MIN, INT_MAX);
  }
  
  bool isValidBSTHelper(TreeNode* root, int min, int max) {
    if (root == NULL)
      return true;
    if (root->val < min || root->val > max)
      return false;

    return isValidBSTHelper(root->left, min, root->val - 1) &&
           isValidBSTHelper(root->right, root->val + 1, max);
  }
};

static TreeNode* prevNode = NULL;

class Solution2 {
 public:
  bool isValidBST(TreeNode* root) {
    prevNode = NULL;
    return isValidBSTHelper(root);
  }

  bool isValidBSTHelper(TreeNode* root) {
    if (!root)
      return true;

    if (!isValidBSTHelper(root->left))
      return false;
    if (prevNode && prevNode->val >= root->val)
      return false;
    prevNode = root;
    return isValidBSTHelper(root->right);
  }
};

int main(int argc, char *argv[]) {
  Solution2 s;
  TreeNode root(10);
  TreeNode l(2);
  TreeNode r(11);

  std::cout << s.isValidBST(&root) << std::endl;
  root.left = &l;
  root.right = &r;
  std::cout << s.isValidBST(&root) << std::endl;
  TreeNode rr(1);
  r.right = &rr;
  std::cout << s.isValidBST(&root) << std::endl;

  return 0;
}
