// 题目：http://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
//
// 题意：二叉树上的每个节点是0-9其中一个数字，从根节点到每个叶子节点可以构造一个
//       整数。对给定的二叉树，计算得到其每条路径得到的整数的和。
//
// 解法：直接DFS遍历的即可。关键在于如何记录路径。
//
////////////////////////////////////////////////////////////////////////////////
//         1
//        / \
//       2   3
//      / \
//     5   4
// The result will be: 125 + 124 + 13 = 262.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
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
  int sumNumbers(TreeNode *root) {
    if (root == NULL)
      return 0;

    sum = 0;
    vector<int> path;
    path.push_back(root->val);
    dfs(root, path);
    return sum;
  }

  void dfs(TreeNode* root, vector<int>& path) {
    if (root == NULL)
      return;

    if (root->left == NULL && root->right == NULL) {
      int t = 1;
      for (int i = path.size() - 1; i >= 0; i--) {
        sum += t * path[i];
        t *= 10;
      }
    }

    if (root->left != NULL) {
      path.push_back(root->left->val);
      dfs(root->left, path);
      path.pop_back();
    }
    if (root->right != NULL) {
      path.push_back(root->right->val);
      dfs(root->right, path);
      path.pop_back();
    }
  }

  int sum;
};

int main(int argc, char *argv[]) {
  TreeNode ll(5);
  TreeNode lr(4);
  TreeNode left(2);
  left.left = &ll;
  left.right = &lr;
  TreeNode right(3);
  TreeNode root(1);
  root.left = &left;
  root.right = &right;
  Solution s;
  cout << s.sumNumbers(&root) << endl;

  return 0;
}
