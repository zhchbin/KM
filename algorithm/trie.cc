#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
  bool is_word;
  TreeNode* next[26];

  TreeNode() {
    is_word = false;
    for (int i = 0; i < 26; ++i) {
      next[i] = NULL;
    }
  }
};

void Insert(TreeNode* root, const string& word) {
  if (root == NULL || word.empty())
    return;

  TreeNode* p = root;
  for (int i = 0; i < word.size(); ++i) {
    int c = word[i] - 'a';

    if (p->next[c] == NULL) {
      TreeNode* tmp = new TreeNode;
      p->next[c] = tmp;
    }

    p = p->next[c];
  }
  p->is_word = true;
}

bool Find(TreeNode* root, const string& word) {
  TreeNode* p = root;
  for (int i = 0; i < word.size(); ++i) {
    if (p == NULL)
      return false;

    p = p->next[word[i] - 'a'];
  }

  return p != NULL && p->is_word;
}

void Delete(TreeNode* root) {
  if (root == NULL)
    return;

  for (int i = 0; i < 26; ++i)
    Delete(root->next[i]);

  delete root;
}

int main(int argc, char *argv[]) {
  TreeNode* root = new TreeNode;
  Insert(root, "abcd");
  Insert(root, "abd");
  Insert(root, "asd");
  Insert(root, "eadkasdkfas");
  Insert(root, "es");
  Insert(root, "saf");
  Insert(root, "adfasdf");
  cout << Find(root, "es") << endl;
  cout << Find(root, "esa") << endl;
  cout << Find(root, "eadkasdkfas") << endl;
  cout << Find(root, "s") << endl;

  Delete(root);
  return 0;
}
