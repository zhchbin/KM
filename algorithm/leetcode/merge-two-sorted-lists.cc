// URL: http://oj.leetcode.com/problems/merge-two-sorted-lists/
//
// Problem: Merge two sorted list.

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == NULL || l2 == NULL)
      return l1 != NULL ? l1 : l2;

    ListNode* head = NULL;
    ListNode* p = NULL;

    while (l1 != NULL && l2 != NULL) {
      ListNode* node;
      if (l1->val < l2->val) {
        node = l1;
        l1 = l1->next;
      } else {
        node = l2;
        l2 = l2->next;
      }

      if (p == NULL) {
        head = p = node;
        continue;
      }

      p->next = node;
      p = p->next;
    }

    if (l1 != NULL)
      p->next = l1;
    else if (l2 != NULL)
      p->next = l2;

    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode l1[] = {1, 2, 5, 8};
  ListNode l2[] = {3, 7, 9, 10};
  for (int i = 0; i < 3; ++i) {
    l1[i].next = &l1[i + 1];
    l2[i].next = &l2[i + 1];
  }

  Solution s;
  ListNode* p = s.mergeTwoLists(&l1[0], &l2[0]);
  while (p != NULL) {
    cout << p->val << endl;
    p = p->next;
  }

  return 0;
}
