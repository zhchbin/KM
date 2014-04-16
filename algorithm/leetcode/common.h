#ifndef  COMMON_H_
#define  COMMON_H_

#include <iostream>
#include <vector>
using namespace std;

#!define ARRAY_SIZE(a) sizeof((a)) / sizeof((a)[0])

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif  // COMMON_H_

