#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct TreeNode {
  int val;
  string path;
};

int cmp(const TreeNode& lhs, const TreeNode& rhs) {
  if (lhs.path.size() != rhs.path.size())
    return lhs.path.size() < rhs.path.size();
  else
    return lhs.path < rhs.path;
}

void parseNode(const string& str, TreeNode& treeNode) {
  int i;
  int v = -1;
  for (i = 1; i < str.size() - 1; i++) {
    if (str[i] != ',') {
      if (v == -1) {
        v = str[i] - '0';
      }
      else {
        v *= 10;
        v += str[i] - '0';
      }
    } else {
      break;
    }
  }

  treeNode.val = v;
  treeNode.path = str.substr(i + 1, str.size() - 1 - i - 1);
}

vector<TreeNode> nodes;

int main(int argc, char *argv[]) {
  string node;
  while (cin >> node) {
    if (node != "()") {
      TreeNode tmp;
      parseNode(node, tmp);
      nodes.push_back(tmp);
    } else {
      sort(nodes.begin(), nodes.end(), cmp);
      bool flag = true;
      set<string> ps;

      for (int i = 0; i < nodes.size(); i++) {
        string t = nodes[i].path;
        if (ps.find(t) == ps.end())
          ps.insert(t);
        else {
          flag = false;
          break;
        }

        for (int i = t.size() - 1; i >= 0; i--) {
          if (ps.find(t.substr(0, i)) == ps.end()) {
            flag = false;
            break;
          }
        }
      }

      if (flag) {
        for (int i = 0; i < nodes.size(); i++) {
          cout << nodes[i].val;
          if (i != nodes.size() - 1)
            cout << " ";
        }
        cout << endl;
      } else {
        cout << "not complete" << endl;
      }

      nodes.clear();
    }
  }
  return 0;
}
