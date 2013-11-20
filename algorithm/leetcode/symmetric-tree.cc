// URL: http://oj.leetcode.com/problems/symmetric-tree/
//
// Problem: Given a binary tree, check whether it is a mirror of itself (ie,
//          symmetric around its center).
//
#include <cassert>
#include <cstddef>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#define INT 0x3fffffff

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == NULL)
      return true;

    vector<int> order;
    inorder(root, order);
    return isSymmetricArray(order);
  }

  void inorder(TreeNode* root, vector<int>& order) {
    if (root == NULL) {
      order.push_back(INT);
      return;
    }

    if (root->left || root->right)
      inorder(root->left, order);
    order.push_back(root->val);
    if (root->left || root->right)
      inorder(root->right, order);
  }

  bool isSymmetricArray(vector<int>& order) {
    if (order.size() % 2 == 0)
      return false;

    int mid = order.size() / 2;
    int i = mid - 1;
    int j = mid + 1;
    while (i >= 0) {
      if (order[i] != order[j])
        return false;

      --i;
      ++j;
    }

    return true;
  }
};

int main(int argc, char *argv[]) {
  TreeNode root(1);
  TreeNode l(2);
  TreeNode r(2);
  root.left = &l;
  root.right = &r;
  Solution s;
  assert(s.isSymmetric(&root) == true);
  TreeNode ll(3);
  l.left = &ll;
  assert(s.isSymmetric(&root) == false);

  return 0;
}
