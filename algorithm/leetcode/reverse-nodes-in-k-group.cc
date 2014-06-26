#include "common.h"

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k <= 1)
      return head;

    ListNode dummy(0);
    dummy.next = head;
    int i = 0;
    ListNode* prev = &dummy;
    while (head) {
      i++;
      if (i % k == 0) {
        prev = reverse(prev, head->next);
        head = prev->next;
      } else {
        head = head->next;
      }
    }

    return dummy.next;
  }

  ListNode* reverse(ListNode* prev, ListNode* next) {
    ListNode* last = prev->next;
    ListNode* cur = last->next;
    while (cur != next) {
      last->next = cur->next;
      cur->next = prev->next;
      prev->next = cur;
      cur = last->next;
    }

    return last;
  }
};

#define SIZE 10

int main(int argc, char *argv[]) {
  ListNode list[SIZE];
  for (int i = 0; i < SIZE; ++i) {
    list[i].val = i;
    if (i != SIZE - 1)
      list[i].next = &list[i + 1];
  }
  Solution s;
  ListNode* head = s.reverseKGroup(&list[0], 3);
  while (head) {
    cout << head->val << endl;
    head = head->next;
  }

  return 0;
}
