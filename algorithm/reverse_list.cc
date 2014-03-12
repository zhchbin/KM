#include <cassert>
#include <cstddef>

#define SIZE 1000
#define EXPECT_EQUAL(expect, actual) assert((expect) == (actual))

struct Node {
  int value;
  Node* next;
  Node(int v = 0, Node* n = NULL) : value(v), next(n) {}
};

void ReverseList(Node*& head) {
  Node* cur = head;
  Node* prev = NULL;
  while (cur) {
    Node* next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }

  head = prev;
}

int main(int argc, char *argv[]) {
  Node node[SIZE];
  for (int i = 0; i < SIZE; ++i) {
    node[i].value = i;
    node[i].next = i != SIZE - 1 ? &node[i + 1] : NULL;
  }

  Node* p = &node[0];
  ReverseList(p);
  for (int i = SIZE - 1; i >= 0; --i) {
    EXPECT_EQUAL(i, p->value);
    p = p->next;
  }

  return 0;
}
