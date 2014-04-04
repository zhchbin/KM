// URL: http://oj.leetcode.com/problems/partition-list/

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    if (head == NULL)
      return head;

    ListNode* p = head;
    ListNode* head_left;
    ListNode* head_right;
    ListNode* tail_left;
    ListNode* tail_right;
    head_left = head_right = tail_left = tail_right = NULL;

    while (p != NULL) {
      if (p->val >= x) {
        if (head_right == NULL)
          head_right = tail_right = p;
        else
          tail_right = tail_right->next = p;
      } else {
        if (head_left == NULL)
          head_left = tail_left = p;
        else
          tail_left = tail_left->next = p;
      }
      p = p->next;
    }
    if (tail_left)
      tail_left->next = NULL;
    if(tail_right)
      tail_right->next = NULL;

    if (head_left == NULL)
      return head_right;

    tail_left->next = head_right;
    return head_left;
  }
};

int main(int argc, char *argv[]) {
  ListNode nodes[] = {1};
  for (int i = 0; i < sizeof(nodes) / sizeof(nodes[0]) - 1; ++i)
    nodes[i].next = &nodes[i + 1];
  Solution s;
  ListNode* head = s.partition(&nodes[0], 0);
  while (head) {
    cout << head->val << endl;
    head = head->next;
  }

  return 0;
}
