// URL: https://oj.leetcode.com/problems/reorder-list/

#include "common.h"

class Solution {
 public:
  ListNode* findMid(ListNode* head) {
    ListNode* slow, *fast;  
    slow = fast = head;
    while (fast && fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

  ListNode* reverseList(ListNode *head) {
    ListNode* prev = NULL;
    ListNode* cur = head;

    while (cur) {
      ListNode* tmp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = tmp;
    }

    return prev;
  }

  ListNode* mergeList(ListNode* lhs, ListNode* rhs) {
    ListNode* cur = lhs;
    while (cur && rhs) {
      ListNode* t1 = cur->next;
      ListNode* t2 = rhs->next;
      cur->next = rhs;
      rhs->next = t1;
      cur = t1;
      rhs = t2;
    }

    return lhs;
  }

  void reorderList(ListNode *head) {
    if (head == NULL || head->next == NULL)
      return;
    ListNode* mid = findMid(head);
    ListNode* right = reverseList(mid->next);
    mid->next = NULL;
    mergeList(head, right);
  }
};

int main(int argc, char *argv[]) {
  ListNode nodes[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < ARRAY_SIZE(nodes) - 1; ++i)
    nodes[i].next = &nodes[i + 1];

  Solution s;
  ListNode* p = &nodes[0];
  s.reorderList(p);
  while (p) {
    cout << p->val << endl;
    p = p->next;
  }

  return 0;
}
