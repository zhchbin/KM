// URL: http://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include "common.h"

// Need O(nlgn). :(
class BadSolution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (head == NULL)
      return NULL;

    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = NULL;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    TreeNode* node = new TreeNode(slow->val);
    if (!prev)
      return node;

    prev->next = NULL;
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(slow->next);
    return node;
  }
};

// O(n). LOL!
class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    int n = 0;
    ListNode* p = head;
    while (p) {
      n++;
      p = p->next;
    }

    return sortedListToBST(head, 0, n - 1);
  }

  TreeNode* sortedListToBST(ListNode*& head, int start, int end) {
    if (start > end)
      return NULL;
    int mid = start + (end - start) / 2;
    TreeNode* left_child = sortedListToBST(head, start, mid - 1);
    TreeNode* parent = new TreeNode(head->val);
    parent->left = left_child;
    head = head->next;
    parent->right = sortedListToBST(head, mid + 1, end);
    return parent;
  }
};

void WriteBinaryTree(TreeNode* root) {
  if (!root) {
    cout << "# ";
  } else {
    cout << root->val << " ";
    WriteBinaryTree(root->left);
    WriteBinaryTree(root->right);
  }
}

int main(int argc, char *argv[]) {
  ListNode nodes[] = {1, 2, 3, 4, 5, 6, 7};
  for (int i = 0; i < ARRAY_SIZE(nodes) - 1; ++i)
    nodes[i].next = &nodes[i + 1];
  Solution s;
  TreeNode* root = s.sortedListToBST(&nodes[0]);
  WriteBinaryTree(root);

  return 0;
}
