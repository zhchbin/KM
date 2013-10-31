// URL: http://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
//
// Problem: Given a binary tree, find its minimum depth. The minimum depth is
//          the number of nodes along the shortest path from the root node down
//          to the nearest leaf node.
//
// Solution: DFS the tree.
//

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
  int minDepth(TreeNode *root) {
    if (root == NULL)
      return 0;

    min_depth_ = 0x3FFFFFFF;
    dfs(root, 1);
    return min_depth_;
  }

  void dfs(TreeNode* root, int depth) {
    if (root == NULL) {
      return ;
    }
    if (root->left == NULL && root->right == NULL) {
      if (depth < min_depth_)
        min_depth_ = depth;
    }

    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
  }

  int min_depth_;
};

int main(int argc, char *argv[]) {
  TreeNode rootNode(10);
  TreeNode left(100);
  TreeNode leftC(1);
  TreeNode right(100);
  Solution s;
  left.left = &leftC;
  rootNode.left = &left;
  rootNode.right = &right;
  cout << s.minDepth(&rootNode) << endl;    // Expectation: 2.

  return 0;
}
