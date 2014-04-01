// URL: http://oj.leetcode.com/problems/path-sum-ii/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<vector<int> > pathSum(TreeNode* root, int num) {
    result.clear();
    vector<int> path;
    dfs(root, path, num);

    return result;
  }

  void dfs(TreeNode* root, vector<int>& path, int num) {
    if (root == NULL)
      return;

    path.push_back(root->val);
    if (root->left == NULL && root->right == NULL && num == root->val)
      result.push_back(path);

    dfs(root->left, path, num - root->val);
    dfs(root->right, path, num - root->val);
    path.pop_back();
  }

  vector<vector<int> > result;
};

int main(int argc, char *argv[]) {
  Solution s;
  TreeNode root(5);
  TreeNode l(4);
  TreeNode r(8);
  root.left = &l;
  root.right = &r;

  TreeNode ll(11);
  TreeNode lll(7);
  TreeNode llr(2);
  l.left = &ll;
  ll.left = &lll;
  ll.right = &llr;

  TreeNode rl(13);
  TreeNode rr(4);
  r.left = &rl;
  r.right = &rr;
  TreeNode rrl(5);
  TreeNode rrr(1);
  rr.left = &rrl;
  rr.right = &rrr;

  vector<vector<int> > result = s.pathSum(&root, 22);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j)
      cout << result[i][j] << " ";
    cout << endl;
  }

  result = s.pathSum(&ll, 13);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j)
      cout << result[i][j] << " ";
    cout << endl;
  }

  result = s.pathSum(&lll, 0);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j)
      cout << result[i][j] << " ";
    cout << endl;
  }

  return 0;
}
