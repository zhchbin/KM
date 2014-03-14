// URL: http://oj.leetcode.com/problems/reverse-linked-list-ii/

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x = 0) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m == n)
      return head;

    ListNode* m_prev = NULL;
    ListNode* m_p = NULL;
    ListNode* n_next = NULL;
    ListNode* cur = head;

    int i;
    for (i = 1; i < m; ++i) {
      m_prev = cur;
      cur = cur->next;
    }
    m_p = cur;

    for (; i < n; ++i)
      cur = cur->next;

    n_next = cur->next;
    cur->next = NULL;
    ListNode* h = reverseList(m_p);
    m_p->next = n_next;
    if (m_prev != NULL) {
      m_prev->next = h;
      return head;
    } else {
      return h;
    }
  }

  ListNode* reverseList(ListNode* head) {
    ListNode* cur = head;
    ListNode* prev = NULL;
    while (cur) {
      ListNode* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    return prev;
  }
};

class BetterSolution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* m_prev = NULL;
    ListNode* prev = &dummy;

    for (int i = 1; i <= n; ++i) {
      if (i == m)
        m_prev = prev;
      if (i > m) {
        prev->next = head->next;
        head->next = m_prev->next;
        m_prev->next = head;
        head = prev;
      }

      prev = head;
      head = head->next;
    }

    return dummy.next;
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
  BetterSolution s;
  ListNode* h = s.reverseBetween(&list[0], 1, 3);
  while (h) {
    cout << h->val << " ";
    h = h->next;
  }
  cout << endl;

  return 0;
}
