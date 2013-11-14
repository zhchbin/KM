// URL: http://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
//
// Problem: Given a binary tree, populate each next pointer to point to its next
// right node. If there is no next right node, the next pointer should be set to
// NULL.
//
// Solution: BFS.
//
#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct QNode {
  TreeLinkNode *node;
  int level;
  QNode(TreeLinkNode *n, int l) : node(n), level(l) {}
};

class Solution {
 public:
  void connect(TreeLinkNode *root) {
    if (root == NULL)
      return;

    queue<QNode> q;
    q.push(QNode(root, 0));
    TreeLinkNode *last_node = NULL;
    int current_level = -1;
    while (!q.empty()) {
      QNode t = q.front();
      q.pop();
      if (current_level != t.level) {
        last_node = t.node;
        current_level = t.level;
      } else {
        last_node->next = t.node;
        last_node = t.node;
      }

      if (t.node->left != NULL)
        q.push(QNode(t.node->left, t.level + 1));
      if (t.node->right != NULL)
        q.push(QNode(t.node->right, t.level + 1));
    }
  }
};

int main(int argc, char *argv[]) {
  TreeLinkNode root(1);
  TreeLinkNode l(2);
  TreeLinkNode r(3);
  TreeLinkNode ll(4);
  TreeLinkNode lr(5);
  TreeLinkNode rl(6);
  TreeLinkNode rr(7);
  root.left = &l;
  root.right = &r;
  l.left = &ll;
  l.right = &lr;
  r.left = &rl;
  r.right = &rr;

  Solution s;
  s.connect(&root);
  TreeLinkNode *p = &ll;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  return 0;
}
