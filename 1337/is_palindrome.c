#include "leetcode.h"

bool Solution::isPalindrome(string s) {
  string ss;
  for(int i=0; i<s.size(); ++i) {
    if('A' <= s[i] && s[i] <= 'Z')
      s[i] += 'a' - 'A';
    if('a' <= s[i] && s[i] <= 'z')
      ss.push_back(s[i]);
    if('0' <= s[i] && s[i] <= '9')
      ss.push_back(s[i]);
  }

  int l = 0;
  int r = ss.size()-1;
  for(;l<r;++l,--r) {
    if ( ss[l] != ss[r] )
      return false;
  }
  return true;
}

void Solution::isPalindromeTest() {
  while(cin.getline(BUF, BUFN)) {
    string s(BUF);
    cout << isPalindrome(s) << endl;
  }
}
