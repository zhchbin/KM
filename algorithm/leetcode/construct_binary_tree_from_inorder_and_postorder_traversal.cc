// URL: http://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include "common.h"

class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int size = inorder.size();
    return buildTree(inorder, postorder, 0, size - 1, 0, size - 1);
  }

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
                      int in_start, int in_end,
                      int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end)
      return NULL;

    int val = postorder[post_end];
    int pos;
    for (int i = in_start; i <= in_end; ++i) {
      if (inorder[i] == val) {
        pos = i;
        break;
      }
    }

    TreeNode* node = new TreeNode(val);
    node->left = buildTree(inorder, postorder, in_start, pos - 1,
                           post_start, post_start + pos - in_start - 1);
    node->right = buildTree(inorder, postorder, pos + 1, in_end,
                           post_start + pos - in_start, post_end - 1);
    return node;
  }
};

void SerializeTree(TreeNode* root) {
  if (root == NULL) {
    cout << "# ";
  } else {
    cout << root->val << " ";
    SerializeTree(root->left);
    SerializeTree(root->right);
  }
}

int main(int argc, char *argv[]) {
  int in[] = {4, 10, 3, 1, 7, 11, 8, 2};
  int post[] = {4, 1, 3, 10, 11, 8, 2, 7};
  vector<int> inorder(in, in + ARRAY_SIZE(in));
  vector<int> postorder(post, post + ARRAY_SIZE(post));
  Solution s;
  SerializeTree(s.buildTree(inorder, postorder));
  return 0;
}
