// URL: https://oj.leetcode.com/problems/merge-k-sorted-lists/

#include "common.h"

class Solution {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty())
      return NULL;

    return mergeKListsRecursive(lists, 0, lists.size() - 1);
  }

  ListNode* mergeKListsRecursive(vector<ListNode*>& lists, int begin, int end) {
    if (begin > end)
      return NULL;

    if (begin == end)
      return lists[begin];

    int mid = (begin + end) / 2;
    ListNode* left = mergeKListsRecursive(lists, begin, mid);
    ListNode* right = mergeKListsRecursive(lists, mid + 1, end);
    return mergeLists(left, right);
  }

  ListNode* mergeLists(ListNode* h1, ListNode* h2) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    while (h1 && h2) {
      if (h1->val < h2->val) {
        cur->next = h1;
        h1 = h1->next;
      } else {
        cur->next = h2;
        h2 = h2->next;
      }
      cur = cur->next;
    }
    cur->next = h1 ? h1 : h2;

    return dummy.next;
  }
};

int main(int argc, char *argv[]) {
  ListNode l1[] = {1, 2, 5, 8};
  ListNode l2[] = {3, 7, 9, 10};
  ListNode l3[] = {0, 3, 4, 11};
  for (int i = 0; i < 3; ++i) {
    l1[i].next = &l1[i + 1];
    l2[i].next = &l2[i + 1];
    l3[i].next = &l3[i + 1];
  }
  vector<ListNode*> lists;
  lists.push_back(&l1[0]);
  lists.push_back(&l2[0]);
  lists.push_back(&l3[0]);
  Solution s;
  ListNode* head = s.mergeKLists(lists);
  while (head) {
    cout << head->val << endl;
    head = head->next;
  }

  return 0;
}
