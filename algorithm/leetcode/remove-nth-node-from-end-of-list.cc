// URL: http://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
//
// Problem: Given a linked list, remove the nth node from the end of list and
//          return its head.
//          For example, Given linked list: 1->2->3->4->5, and n = 2.
//          After removing the second node from the end, the linked list becomes
//          1->2->3->5.
//          Note: Given n will always be valid. Try to do this in one pass.
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode* pre;
    ListNode* cur;

    pre = cur = head;
    while (n && pre != NULL) {
      pre = pre->next;
      n--;
    }

    ListNode* tmp = NULL;
    while (pre != NULL) {
      tmp = cur;
      cur = cur->next;
      pre = pre->next;
    }

    if (tmp == NULL)
      head = cur->next;
    else
      tmp->next = cur->next;
    delete cur;

    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *n1 = new ListNode(1);
  ListNode *n2 = new ListNode(2);
  ListNode *n3 = new ListNode(3);
  ListNode *n4 = new ListNode(4);
  ListNode *n5 = new ListNode(5);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  Solution s;
  ListNode* head = s.removeNthFromEnd(n1, 5);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }

  return 0;
}
