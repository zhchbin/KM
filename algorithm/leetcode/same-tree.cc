// URL: http://oj.leetcode.com/problems/same-tree/
//
// Problem: Given two binary trees, write a function to check if they are equal
//          or not. Two binary trees are considered equal if they are
//          structurally identical and the nodes have the same value.
//
// Solution: DFS.
//

#include <cstddef>
#include <cassert>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    return dfs(p, q);
  }

  bool dfs(TreeNode *p, TreeNode *q) {
    if (p == NULL || q == NULL) {
      if (p == NULL && q == NULL) {
        return true;
      }
      return false;
    }

    if (p->val == q->val)
      return dfs(p->left, q->left) && dfs(p->right, q->right);
    else
      return false;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  TreeNode p(1);
  TreeNode pl(2);
  TreeNode pr(3);
  p.left = &pl;
  p.right = &pr;

  TreeNode q(1);
  TreeNode ql(2);
  TreeNode qr(3);
  q.left = &ql;
  q.right = &qr;

  assert(s.isSameTree(&p, &p) == true);
  assert(s.isSameTree(&p, &pr) == false);
  assert(s.isSameTree(&p, &q) == true);
  ql.val = 10;
  assert(s.isSameTree(&p, &q) == false);
  return 0;
}
