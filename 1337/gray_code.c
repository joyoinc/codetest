#include "leetcode.h"

void Solution::grayCodeTest() {
  while(cin.getline(BUF, BUFN)) {
    int n = atoi(BUF);
    vector<int> ans = grayCode(n);
    cout << ans << endl;
  }
}

// <<, >> shift is lower than +,-
vector<int> Solution::grayCode(int n) {
  vector<int> ans(1<<n, 0);
  int i;
  for(i=1; i<=n; ++i) {
    for(int j=0; j< 1<<i-1; ++j)
      ans[(1<<i)-1-j] = ans[j] | 1<<i-1 ;
  }
  return ans;
}
