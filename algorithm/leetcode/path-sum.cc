// URL: http://oj.leetcode.com/problems/path-sum/
//
// Problem: Given a binary tree and a sum, determine if the tree has a
//          root-to-leaf path such that adding up all the values along the path
//          equals the given sum.

#include <cassert>
#include <cstddef>

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool hasPathSum(TreeNode *root, int sum) {
    return dfs(root, sum, 0);
  }

  bool dfs(TreeNode* root, int sum, int cur) {
    if (root == NULL)
      return false;

    cur = cur + root->val;
    if (sum == cur && root->left == NULL && root->right == NULL)
      return true;
    else
      return dfs(root->left, sum, cur) || dfs(root->right, sum, cur);
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
  assert(s.hasPathSum(&root, 100) == false);
  assert(s.hasPathSum(&root, 2) == false);
  assert(s.hasPathSum(&root, 6) == true);
  assert(s.hasPathSum(&root, 12) == true);

  return 0;
}
