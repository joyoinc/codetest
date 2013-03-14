#include "leetcode.h"

void Solution::anagramsTest() {
  while(cin.getline(BUF, BUFN)) {
    vector<string> strs, ans;
    char * pch = strtok(BUF, ", ");
    for(; pch; pch=strtok(0, ", "))
      strs.push_back(pch);
      ans = anagrams(strs);
      cout << ans << endl;
  }
}
vector<string> Solution::anagrams(vector<string> &strs) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  multimap<string, string> map;
  set<string> keys;
  pair<multimap<string,string>::iterator, multimap<string,string>::iterator> its;
  multimap<string, string>::iterator mit;
  for(int i=0; i<strs.size(); i++) {
    string s = strs[i];
    std::sort(s.begin(), s.end());
    map.insert( pair<string, string>(s, strs[i]));
    keys.insert(s);
  }

  vector<string> res;
  set<string>::iterator kit;
  for(kit=keys.begin(); kit!=keys.end(); kit++) {
    if(map.count(*kit)>1) {
      its = map.equal_range(*kit);
      for(mit=its.first; mit!=its.second; mit++)
        res.push_back(mit->second);
    }
  }
  return res;
}
