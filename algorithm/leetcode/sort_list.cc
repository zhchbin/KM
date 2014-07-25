// URL: https://oj.leetcode.com/problems/sort-list/
#include "common.h"

class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next)
      return head;

    ListNode* mid = findMid(head);
    ListNode* rightHead = mid->next;
    mid->next = NULL;
    ListNode* left = sortList(head);
    ListNode* right = sortList(rightHead);
    return merge(left, right);
  }

  ListNode* findMid(ListNode* head) {
    ListNode *slow, *fast;
    slow = fast = head;
    while (fast && fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

  ListNode* merge(ListNode* left, ListNode* right) {
    ListNode dummy(0);
    ListNode* cur = &dummy;

    while (left && right) {
      if (right->val < left->val) {
        cur->next = right;
        right = right->next;
      } else {
        cur->next = left;
        left = left->next;
      }
      cur = cur->next;
    }
    if (right)
      cur->next = right;
    if (left)
      cur->next = left;

    return dummy.next;
  }
};

int main(int argc, char* argv[]) {
  ListNode node[] = {5, 4, 1, 9, 10, 11, 0, 3, 6};
  for (int i = 0; i < ARRAY_SIZE(node) - 1; ++i) {
    node[i].next = &node[i + 1];
  }

  Solution s;
  ListNode* head = s.sortList(&node[0]);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;

  return 0;
}
