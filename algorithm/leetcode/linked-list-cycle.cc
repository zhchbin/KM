// URL: http://oj.leetcode.com/problems/linked-list-cycle/
//
// Problem: Given a linked list, determine if it has a cycle in it.
//
// Solution: Floyd’s cycle finding algorithm, also called the Tortoise and hare
//           algorithm.
//           
//           It uses two pointers (one slow pointer and one fast pointer). The
//           slow pointer advances one node at a time, while the fast pointer
//           traverses twice as fast. If the list has loop in it, eventually the
//           fast and slow pointer will meet at the same node. On the other
//           hand, if the loop has no loop, the fast pointer will reach the end
//           of list before the slow pointer does.
//

#include <cassert>
#include <cstddef>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    ListNode *p = head;
    ListNode *pp = NULL;
    if (p != NULL)
      pp = p->next;

    while (pp != NULL) {
      if (p == pp)
        return true;
      p = p->next;
      pp = pp->next;
      if (pp != NULL)
        pp = pp->next;
      else
        return false;
    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  ListNode l1(10);
  ListNode l2(10);
  ListNode l3(10);
  ListNode l4(10);
  ListNode l5(10);
  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  l4.next = &l5;
  Solution s;
  assert(s.hasCycle(&l1) == false);

  l5.next = &l2;
  assert(s.hasCycle(&l1) == true);

  return 0;
}
