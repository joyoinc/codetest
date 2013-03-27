#include "leetcode.h"

void Solution::findSubstringTest() {
  vector<string> L;
  string s;
  while(cin.getline(BUF, BUFN)) {
    stringstream sin(BUF);
    L.clear();
    for(; sin >> s; )
      L.push_back(s);
    L.pop_back();
    vector<int> ans = findSubstring(s, L);
    cout << ans << endl;
  }
}

bool isInL(string s, int len, vector<string> &L, vector<int> &mask) {
  int i;
  for(i=0; i<L.size() && mask[i] ; ++i);
  bool allFound = i==L.size();
  if(allFound) return true;
  if(!s.size()) return false;

  for(i=0; i<L.size(); ++i) {
    if(mask[i]) continue;
    if(s.substr(0, len) == L[i]) {
      mask[i] = 1;
      return isInL(s.substr(len), len, L, mask);
    }
  }
  return false;
}

vector<int> Solution::findSubstring(string S, vector<string> &L) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  vector<int> ans;
  vector<int> mask(L.size(), 0);
  int wordlen = L[0].size();
  for(int i=0; i<S.size(); ++i) {
    if( isInL(S.substr(i), wordlen, L, mask) ) {
      ans.push_back(i);

    }
    for(int j=0; j<L.size(); ++j) mask[j]=0;
  }
  return ans;
}
