// URL: http://oj.leetcode.com/problems/balanced-binary-tree/
//
// Problem: Given a binary tree, determine if it is height-balanced.
//          For this problem, a height-balanced binary tree is defined as a
//          binary tree in which the depth of the two subtrees of every node
//          never differ by more than 1.

#include <cmath>
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
  bool isBalanced(TreeNode *root) {
    int depth = 0;
    return isBalancedRecursive(root, &depth);
  }

  bool isBalancedRecursive(TreeNode *root, int* depth) {
    if (root == NULL) {
      *depth = 0;
      return true;
    }

    int left, right;
    if (isBalancedRecursive(root->left, &left) &&
        isBalancedRecursive(root->right, &right)) {
      if (abs(left - right) <= 1) {
        *depth = (left > right ? left : right) + 1;
        return true;
      }
    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  return 0;
}
