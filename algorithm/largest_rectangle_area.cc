// http://poj.org/problem?id=2559
//    Given n non-negative integers representing the histogram's bar heights
//    where the width of each bar is 1, find the area of largest rectangle
//    include the histogram.
//
// Thanks
//  http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html
//

#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long int ll;
ll data[100001];

ll largestRectangleArea(vector<ll>& heights) {
  stack<ll> s;
  heights.push_back(0);

  ll sum = 0;
  for (int i = 0; i < heights.size(); i++) {
    if (s.empty()) {
      s.push(i);
      continue;
    }

    if (heights[i] > heights[s.top()]) {
      s.push(i);
    } else {
      ll tmp = s.top();
      s.pop();
      sum = max(sum, heights[tmp] * (s.empty() ? i : i - s.top() - 1));
      i--;
    }
  }

  return sum;
}

int main(int argc, char *argv[]) {
  int N;
  while (scanf("%d", &N) && N != 0) {
    for (int i = 0; i < N; i++) {
      scanf("%lld", &data[i]);
    }
    vector<ll> heights(data, data + N);
    printf("%lld\n", largestRectangleArea(heights));
  }

  return 0;
}
