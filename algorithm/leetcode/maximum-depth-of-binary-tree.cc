// URL: http://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
//
// Problem: Given a binary tree, find its maximum depth.
//          The maximum depth is the number of nodes along the longest path from
//          the root node down to the farthest leaf node.
//
// Solution: DFS.
//

#include <cstddef>
#include <cassert>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  int maxDepth(TreeNode *root) {
    max_ = 0;
    dfs(root, 0);
    return max_;
  }

  void dfs(TreeNode *root, int depth) {
    if (root == NULL) {
      if (depth > max_)
        max_ = depth;
      return ;
    }

    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
  }

 private:
  int max_;
};

int main(int argc, char *argv[]) {
  TreeNode root(10);
  TreeNode l(10);
  TreeNode ll(10);
  TreeNode r(10);
  root.left = &l;
  l.left = &ll;
  root.right = &r;
  Solution s;
  assert(s.maxDepth(&root) == 3);

  return 0;
}
