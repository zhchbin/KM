// https://oj.leetcode.com/problems/rotate-list/
#include "common.h"

class Solution {
 public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || k <= 0)
      return head;

    int len = 1;
    ListNode* p = head;
    while (p->next) {
      p = p->next;
      len++;
    }
    p->next = head;
    int steps = len - k % len;
    for (int i = 0; i < steps; ++i)
      p = p->next;
    head = p->next;
    p->next = NULL;
    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode nodes[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < ARRAY_SIZE(nodes) - 1; ++i)
    nodes[i].next = &nodes[i + 1];
  Solution s;
  ListNode* p = s.rotateRight(&nodes[0], 2);
  while (p) {
    cout << p->val << " -> ";
    p = p->next;
  }
  cout << endl;

  return 0;
}
