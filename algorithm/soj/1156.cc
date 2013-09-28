#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int i;
  char c;
  int l;
  int r;
  bool is_root;
  Node* left;
  Node* right;

  Node() {
    left = right = NULL;
    is_root = true;
  }
};

int findNode(const vector<Node>& nodes, int t) {
  if (t == 0)
    return -1;
  for (int i = 0; i < nodes.size(); ++i) {
    if (nodes[i].i == t) {
      return i;
    }
  }

  return -1;
}

void pre(Node* node) {
  if (node != NULL) {
    cout << node->c;
    pre(node->left);
    pre(node->right);
  }
}

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    Node node;
    vector<Node> nodes;
    for (int i = 0; i < n; i++) {
      cin >> node.i >> node.c >> node.l >> node.r;
      nodes.push_back(node);
    }

    for (int i = 0; i < nodes.size(); ++i) {
      int tmp;
      if ((tmp = findNode(nodes, nodes[i].l)) != -1) {
        nodes[i].left = &nodes[tmp];
        nodes[tmp].is_root = false;
      }

      if ((tmp = findNode(nodes, nodes[i].r)) != -1) {
        nodes[i].right = &nodes[tmp];
        nodes[tmp].is_root = false;
      }
    }

    for (int i = 0; i < nodes.size(); i++) {
      if (nodes[i].is_root)
        pre(&nodes[i]);
    }
    cout << endl;
  }
  return 0;
}
