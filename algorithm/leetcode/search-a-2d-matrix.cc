// URL: http://oj.leetcode.com/problems/search-a-2d-matrix/
//
// Problem: Write an efficient algorithm that searches for a value in an
//          m x n matrix. This matrix has the following properties:
//            1. Integers in each row are sorted from left to right.
//            2.The first integer of each row is greater than the last integer of
//            the previous row.
//
// Solution: Binary search the martix, just take it as one dimension array. The
//           tricky part is how to mapping the one dimension index to the martix
//           array index.
//

#include <vector>
#include <cassert>
using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if (matrix.size() == 0)
      return false;

    int length = matrix.size() * matrix[0].size();
    rowSize_ = matrix[0].size();
    return binarySearch(matrix, 0, length - 1, target);
  }

  bool binarySearch(vector<vector<int> >& matrix, int hd, int tl, int target) {
    if (hd > tl)
      return false;

    int mid = (hd + tl) >> 1;
    int midValue = matrix[mid / rowSize_][mid % rowSize_];
    if (midValue == target) {
      return true;
    } else if (midValue > target) {
      return binarySearch(matrix, hd, mid - 1, target);
    } else {
      return binarySearch(matrix, mid + 1, tl, target);
    }
  }

  int rowSize_;
};

int main(int argc, char *argv[]) {
  Solution s;
  int arr[][4] = {
                  {1,   3,  5,  7},
                  {10, 11, 16, 20},
                  {23, 30, 34, 50}
                };
  vector<int> v1(arr[0], arr[0] + 4);
  vector<int> v2(arr[1], arr[1] + 4);
  vector<int> v3(arr[2], arr[2] + 4);
  vector<vector<int> > matrix;
  matrix.push_back(v1);
  matrix.push_back(v2);
  matrix.push_back(v3);

  assert(s.searchMatrix(matrix, 1) == true);
  assert(s.searchMatrix(matrix, 3) == true);
  assert(s.searchMatrix(matrix, 50) == true);
  assert(s.searchMatrix(matrix, 6) == false);
  assert(s.searchMatrix(matrix, 35) == false);
  assert(s.searchMatrix(matrix, 100) == false);

  return 0;
}
