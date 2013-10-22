// 题目：http://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
//
// 题意：给定一个已经排好序的单链表，将其中出现重复的元素删除。比如：
//       输入：1->2->3->3->4->4->5   输出：1->2->5
//       输入：1->1->1->2->3         输出：2->3
//
// 解法：在纸上先画出操作的过程，然后照着写的，注意head的更新。
//

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode* p) : val(x), next(p) {}
};

#define INF 0x3FFFFFFF;

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode* p = head;
    ListNode* lastNode = NULL;
    int cur = INF;   // assuming that INF is an invalid integer int the list.
    while (p != NULL) {
      // There are two situation that we should delete the current node:
      //    1. the value of current node is equal to value of last deleted node;
      //    2. if next node isn't null and their values are equal.
      if (cur == p->val || p->next != NULL) {
        if (cur == p->val || p->val == p->next->val) {
          cur = p->val;
          ListNode* t = p;
          if (lastNode == NULL) {
            head = p->next;
          } else {
            lastNode->next = p->next;
          }
          p = p->next;
          delete t;
          continue;
        }
      }

      lastNode = p;
      p = p->next;
    }
    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode* t = new ListNode(5);
  t = new ListNode(4, t);
  t = new ListNode(4, t);
  t = new ListNode(3, t);
  t = new ListNode(3, t);
  t = new ListNode(2, t);
  t = new ListNode(1, t);
  t = new ListNode(1, t);
  t = new ListNode(1, t);
  t = new ListNode(1, t);

  Solution s;
  t = s.deleteDuplicates(t);
  while (t != NULL) {
    cout << t->val << endl;
    ListNode *tmp = t;
    t = t->next;
    delete tmp;
  }

  return 0;
}
