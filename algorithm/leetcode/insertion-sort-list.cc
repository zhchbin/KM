// URL: http://oj.leetcode.com/problems/insertion-sort-list/

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *insertionSortList(ListNode *head) {
    if (head == NULL)
      return head;

    ListNode* sorted = head;
    head = head->next;
    sorted->next = NULL;

    while (head) {
      ListNode* tmp = head;
      head = head->next;

      ListNode* pp = NULL;
      ListNode* p = sorted;
      while (p && p->val < tmp->val) {
        pp = p;
        p = p->next;
      }

      tmp->next = p;
      if (pp)
        pp->next = tmp;
      else
        sorted = tmp;
    }

    return sorted;
  }
};

#define ARRAY_SIZE(a) (sizeof(a)/sizeof((a)[0]))

int main(int argc, char *argv[]) {
  ListNode list[] = {0, 4, 1, 3, 5, 10, 2};
  for (int i = 0; i < ARRAY_SIZE(list) - 1; ++i)
    list[i].next = &list[i + 1];
  Solution s;
  ListNode* head = s.insertionSortList(&list[0]);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;

  return 0;
}
