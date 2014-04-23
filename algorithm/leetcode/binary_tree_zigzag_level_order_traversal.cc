// URL: http://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
#include "common.h"

typedef std::pair<TreeNode*, int> TreeNodeWithLevel;

class Solution {
 public:
  vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > orders;
    if (!root)
      return orders;

    int last_level = 0;
    queue<TreeNodeWithLevel> q;
    q.push(TreeNodeWithLevel(root, 0));
    vector<int> current_order;
    while (!q.empty()) {
      TreeNodeWithLevel node = q.front();
      if (last_level != node.second) {
        if (last_level % 2)
          std::reverse(current_order.begin(), current_order.end());
        orders.push_back(current_order);
        current_order.clear();
        last_level = node.second;
      }

      current_order.push_back(node.first->val);
      q.pop();
      if (node.first->left != NULL)
        q.push(TreeNodeWithLevel(node.first->left, node.second + 1));
      if (node.first->right != NULL)
        q.push(TreeNodeWithLevel(node.first->right, node.second + 1));
    }

    if (!current_order.empty()) {
      if (last_level % 2)
        std::reverse(current_order.begin(), current_order.end());
      orders.push_back(current_order);
    }

    return orders;
  }
};

class SolutionWithTwoStack {
 public:
  vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > orders;
    if (!root)
      return orders;

    stack<TreeNode*> current_level;
    stack<TreeNode*> next_level;
    current_level.push(root);
    vector<int> current_order;
    bool left_to_right = true;
    while (!current_level.empty()) {
      TreeNode* current_node = current_level.top();
      current_level.pop();

      if (current_node) {
        current_order.push_back(current_node->val);
        next_level.push(
            left_to_right ? current_node->left : current_node->right);
        next_level.push(
            !left_to_right ? current_node->left : current_node->right);
      }

      if (current_level.empty()) {
        if (!current_order.empty())
        orders.push_back(current_order);
        current_order.clear();
        left_to_right = !left_to_right;
        std::swap(current_level, next_level);
      }
    }

    return orders;
  }
};

int main(int argc, char *argv[]) {
  SolutionWithTwoStack s;
  TreeNode root(3);
  TreeNode l(9);
  root.left = &l;
  TreeNode r(20);
  root.right = &r;

  TreeNode rl(15);
  r.left = &rl;
  TreeNode rr(7);
  r.right = &rr;
  vector<vector<int> > orders = s.zigzagLevelOrder(&root);
  for (int i = 0; i < orders.size(); ++i) {
    for (int j = 0; j < orders[i].size(); ++j)
      cout << orders[i][j] << " ";
    cout << endl;
  }

  return 0;
}
