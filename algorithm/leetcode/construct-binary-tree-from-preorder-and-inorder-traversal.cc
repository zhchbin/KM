// URL: http://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//
// Problem: Given preorder and inorder traversal of a tree, construct the binary
//          tree.
//
// Solution:
//  For example, preorder: {1, 2, 3, 4, 5} and inorder: {2, 1, 3, 5, 4}, we can
//  get the current node is 1 from the |preorder|, and then find its index in
//  the |inorder|. So that we can get the preorder of left child of current node
//  is {2}, the inorder is {2}; the preorder of right child is {3, 4, 5}, the
//  inorder is {3, 5, 4}. It's obvious that we can solve the problem
//  recursively.
//

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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int* preorderArray = new int[preorder.size()];
    int* inorderArray = new int[inorder.size()];
    for (int i = 0; i < preorder.size(); i++) {
      preorderArray[i] = preorder[i];
      inorderArray[i] = inorder[i];
    }

    TreeNode* root = buildTreeImpl(preorderArray, preorder.size(), inorderArray, inorder.size());
    delete []preorderArray;
    delete []inorderArray;
    return root;
  }

  TreeNode* buildTreeImpl(int* preorder, int sp, int* inorder, int si) {
    if (sp == 0 || si == 0)
      return NULL;
    TreeNode* root = new TreeNode(preorder[0]);
    int i;
    for (i = 0; i < si; i++)
      if (inorder[i] == preorder[0])
        break;

    root->left = buildTreeImpl(preorder + 1, i, inorder, i);
    root->right = buildTreeImpl(preorder + i + 1, sp - i - 1,
                                inorder + i + 1, si - i - 1);
    return root;
  }
};

void in(TreeNode* root) {
  if (root == NULL)
    return;

  in(root->left);
  cout << root->val << endl;
  in(root->right);
}

int main(int argc, char *argv[]) {
  int arrPre[] = {1, 2, 3, 4, 5};
  int arrIn[] = {2, 1, 3, 5, 4};
  vector<int> preorder(arrPre, arrPre + 5);
  vector<int> inorder(arrIn, arrIn + 5);
  Solution s;
  TreeNode* root = s.buildTree(preorder, inorder);
  in(root);

  return 0;
}
