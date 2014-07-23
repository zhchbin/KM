// URL: https://oj.leetcode.com/problems/copy-list-with-random-pointer/
#include "common.h"

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

typedef std::vector<RandomListNode*> Nodes;
typedef std::map<RandomListNode*, RandomListNode*> NodeMap;

class Solution {
 public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head)
      return NULL;

    RandomListNode dummy(0);
    RandomListNode* p = head;
    RandomListNode* cur =dummy;
    NodeMap node_map;
    while (p) {
      RandomListNode* tmp = new RandomListNode(p->label);
      node_map[p] = tmp;
      cur->next = tmp;
      cur = cur->next;
      p = p->next;
    }

    p = head;
    cur = dummy.next;
    while (p) {
      if (p->random)
        cur->random = node_map[p->random];
      cur = cur->next;
      p = p->next;
    }

    return dummy.next;
  }
};

int main(int argc, char *argv[]) {
  RandomListNode ns[] = {0, 1, 2, 3, 4, 5};
  for (int i = 0; i < ARRAY_SIZE(ns) - 1; ++i) {
    ns[i].next =ns[i + 1];
  }
  ns[2].random =ns[0];
  ns[4].random =ns[0];
  ns[5].random =ns[1];
  Solution s;
  RandomListNode* head = s.copyRandomList(&ns[0]);
  RandomListNode* t = head;
  while (head) {
    cout << head->label << " ";
    if (head->random != NULL)
      cout << " -> " << head->random->label << endl;
    else
      cout << endl;
    head = head->next;
  }

  // Clean up.
  while (t) {
    RandomListNode* n = t;
    t = t->next;
    delete n;
  }

  return 0;
}
