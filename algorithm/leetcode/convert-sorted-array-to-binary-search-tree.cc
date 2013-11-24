// URL: http://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
//
// Problem: Given an array where elements are sorted in ascending order, convert
//          it to a height balanced BST.
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
  TreeNode *sortedArrayToBST(vector<int> &num) {
    TreeNode *root = NULL;
    recursiveSortedArrayToBST(num, 0, num.size() - 1, root);

    return root;
  }

  void recursiveSortedArrayToBST(vector<int> &num, int hd, int tl,
                                 TreeNode*& root) {
    if (hd > tl)
      return;
    int mid = (hd + tl) >> 1;
    root = new TreeNode(num[mid]);
    recursiveSortedArrayToBST(num, hd, mid - 1, root->left);
    recursiveSortedArrayToBST(num, mid + 1, tl, root->right);
  }
};

void inorder(TreeNode *root) {
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->val << endl;
  inorder(root->right);
}

int main(int argc, char *argv[]) {
  Solution s;
  int arr[] = {1, 2, 3, 4, 5};
  vector<int> nums(arr, arr + 3);
  TreeNode *root = s.sortedArrayToBST(nums);
  inorder(root);

  return 0;
}
