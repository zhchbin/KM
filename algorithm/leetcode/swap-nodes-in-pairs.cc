// URL: http://oj.leetcode.com/problems/swap-nodes-in-pairs/
//
// Problem: Given a linked list, swap every two adjacent nodes and return its 
// head. For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
// Your algorithm should use only constant space. You may not modify the values
// in the list, only nodes itself can be changed.

#include <iostream>
#include <cassert>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *swapPairs(ListNode *head) {
    if (head == NULL)
      return NULL;

    ListNode* p = NULL;
    ListNode* p1 = head;
    ListNode* p2 = p1->next;
    ListNode* last = NULL;
    if (p2 == NULL)
      return head;

    while (p2 != NULL) {
      if (last != NULL)
        last->next = p2;

      p1->next = p2->next;
      p2->next = p1;
      if (p == NULL)
        p = p2;
      last = p1;

      p1 = p1->next;
      if (p1 == NULL)
        break;

      p2 = p1->next;
    }

    return p;
  }
};

int main(int argc, char *argv[]) {
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  Solution s;
  ListNode *h = s.swapPairs(&n1);
  while (h != NULL) {
    cout << h->val << endl;
    h = h->next;
  }

  return 0;
}
