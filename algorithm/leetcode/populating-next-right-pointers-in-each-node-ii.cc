// URL: http://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

#include <iostream>
using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// You can also used BFS, but there is a "queue".
class RecursiveSolution {
public:
  void connect(TreeLinkNode* root) {
    if (!root)
      return;

    TreeLinkNode* t = NULL;
    if (root->left && root->right) {
      root->left->next = root->right;
      t = root->right;
    } else if (root->left) {
      t = root->left;
    } else if (root->right) {
      t = root->right;
    }

    TreeLinkNode* temp = root->next;
    if (t) {
      TreeLinkNode* next = NULL;
      while (temp) {
        if (temp->left) {
          next = temp->left;
          break;
        } else if (temp->right) {
          next = temp->right;
          break;
        }

        temp = temp->next;
      }
      t->next = next;
    }

    // Note the sequence, right -> left, due to case like:
    //      1
    //    2   3
    //   4 5 6 7
    //  8       15
    connect(root->right);
    connect(root->left);
  }
};

class Solution {
 public:
  void connect(TreeLinkNode* root) {
    while (root) {
      TreeLinkNode* prev = NULL;
      TreeLinkNode* next = NULL;

      while (root) {
        if (!next)
          next = root->left ? root->left : root->right;

        if (root->left) {
          if (prev) {
            prev->next = root->left;
            prev = prev->next;
          } else {
            prev = root->left;
          }
        }

        if (root->right) {
           if (prev) {
            prev->next = root->right;
            prev = prev->next;
          } else {
            prev = root->right;
          }
        }
        root = root->next;
      }

      root = next;
    }
  }
};

int main() {
  TreeLinkNode root(1);
  TreeLinkNode l(2);
  TreeLinkNode r(3);
  TreeLinkNode ll(4);
  TreeLinkNode lr(5);
  TreeLinkNode rl(6);
  TreeLinkNode rr(7);
  TreeLinkNode lll(8);
  TreeLinkNode rrr(15);

  root.left = &l;
  root.right = &r;
  l.left = &ll;
  l.right = &lr;
  r.left = &rl;
  r.right = &rr;
  ll.left = &lll;
  rr.left = &rrr;

  Solution s;
  s.connect(&root);
  TreeLinkNode* p = &l;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  p = &lll;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }

  return 0;
}
