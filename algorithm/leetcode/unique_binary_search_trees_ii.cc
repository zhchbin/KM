// URL: http://oj.leetcode.com/problems/unique-binary-search-trees-ii/
#include "common.h"

class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) {
    return generateTreesHelper(1, n);
  }

  vector<TreeNode*> generateTreesHelper(int start, int end) {
    if (start > end)
      return vector<TreeNode*>(1, static_cast<TreeNode*>(NULL));

    vector<TreeNode*> trees;
    for (int i = start; i <= end; ++i) {
      vector<TreeNode*> leftTrees = generateTreesHelper(start, i - 1);
      vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, end);

      for (int j = 0; j < leftTrees.size(); ++j) {
        for (int k = 0; k < rightTrees.size(); ++k) {
          TreeNode* root = new TreeNode(i);
          root->left = leftTrees[j];
          root->right = rightTrees[k];

          trees.push_back(root);
        }
      }
    }

    return trees;
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
  Solution s;
  vector<TreeNode*> trees = s.generateTrees(3);
  for (int i = 0; i < trees.size(); ++i) {
    SerializeTree(trees[i]);
    cout << endl;
  }

  return 0;
}
