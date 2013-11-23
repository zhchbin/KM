// URL: http://oj.leetcode.com/problems/binary-tree-inorder-traversal/
//
// Problem: Binary Tree Inorder Traversal without recursive.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> inorder;
    if (root == NULL)
      return inorder;

    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
      TreeNode* p = s.top();
      if (p->left != NULL) {
        s.push(p->left);
        p->left = NULL;
      } else {
        inorder.push_back(p->val);
        s.pop();
        if (p->right != NULL) {
          s.push(p->right);
          p->right = NULL;
        }
      }
    }

    return inorder;
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
  vector<int> inorder = s.inorderTraversal(&root);
  for (int i = 0; i < inorder.size(); ++i)
    cout << inorder.at(i) << " ";
  cout << endl;

  return 0;
}
