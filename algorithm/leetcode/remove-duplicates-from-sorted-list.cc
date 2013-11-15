#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *last_node = NULL;
    ListNode *p = head;
    while (p != NULL) {
      if (last_node && last_node->val == p->val) {
        ListNode *tmp = p;
        last_node->next = p->next;
        p = p->next;
        delete tmp;
      } else {
        last_node = p;
        p = p->next;
      }
    }

    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *n1 = new ListNode(1);
  ListNode *n2 = new ListNode(1);
  ListNode *n3 = new ListNode(2);
  ListNode *n4 = new ListNode(3);
  ListNode *n5 = new ListNode(3);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  Solution s;
  ListNode *p = s.deleteDuplicates(n1);
  while (p != NULL) {
    cout << p->val << endl;
    p = p->next;
  }


  return 0;
}
