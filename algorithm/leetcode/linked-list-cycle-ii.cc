// URL: http://oj.leetcode.com/problems/linked-list-cycle-ii/
//
// Problem: Given a linked list, return the node where the cycle begins. If
//          there is no cycle, return null.
//
// Reference: http://umairsaeed.com/2011/06/23/finding-the-start-of-a-loop-in-a-circular-linked-list/
//

#include <cstddef>
#include <cassert>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (slow != NULL && fast != NULL) {
      slow = slow->next;
      fast = fast->next;
      if (fast == NULL)
        break;
      fast = fast->next;

      if (slow == fast) {
        slow = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }

        return slow;
      }
    }

    return NULL;
  }
};

int main(int argc, char *argv[]) {
  ListNode l1(10);
  ListNode l2(11);
  ListNode l3(12);
  ListNode l4(13);
  ListNode l5(14);
  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  l4.next = &l5;
  Solution s;
  assert(s.detectCycle(&l1) == NULL);

  l5.next = &l2;
  assert(s.detectCycle(&l1)->val == 11);
  return 0;
}
