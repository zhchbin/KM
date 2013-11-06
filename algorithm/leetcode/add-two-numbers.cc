// URL: http://oj.leetcode.com/problems/add-two-numbers/
//
// Problem:
//  You are given two linked lists representing two non-negative numbers. The
//  digits are stored in reverse order and each of their nodes contain a single
//  digit. Add the two numbers and return it as a linked list.
//    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//    Output: 7 -> 0 -> 8
//
//  Solution: Simulate the addition. I firstly solve the problem with many
//            duplicated code, after reading the discussion, just merge them
//            into one loop: 57 -> 27, awesome!
//

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode* head = NULL;
    ListNode* p = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0) {
      int num1 = l1 == NULL ? 0 : l1->val;
      int num2 = l2 == NULL ? 0 : l2->val;
      int val = num1 + num2 + carry;
      carry = val / 10;
      val %= 10;

      if (p == NULL) {
        head = p = new ListNode(val);
      } else {
        p->next = new ListNode(val);
        p = p->next;
      }
      l1 = (l1 == NULL ? NULL : l1->next);
      l2 = (l2 == NULL ? NULL : l2->next);
    }

    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode l1[] = {2, 4, 3};
  ListNode l2[] = {5, 6, 1, 8};
  for (int i = 0; i < 2; i++) {
    l1[i].next = &l1[i + 1];
    l2[i].next = &l2[i + 1];
  }
  l2[2].next = &l2[3];
  Solution s;
  ListNode *head = s.addTwoNumbers(&l1[0], &l2[0]);
  ListNode *p;
  while (head != NULL) {
    p = head;
    cout << head->val << " ";
    head = head->next;
    delete p;
  }
  cout << endl;

  return 0;
}
