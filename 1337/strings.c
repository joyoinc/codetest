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

vector<int> Solution::findSubstring(string S, vector<string> &L) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  int wordlen = L[0].size();
  int len = L.size();
  int wordslen = wordlen * len;
  int i,j;
  vector<int> ans;
  map<string, int> wordcnt;
  for(j=0; j<len ; ++j) {
    if( wordcnt.find(L[j]) != wordcnt.end() )
      wordcnt[L[j]] += 1;
    else
      wordcnt[L[j]] = 1;
  }
  map<string, int>::iterator itor;
  int offset = 0;
  for(itor=wordcnt.begin(); itor!=wordcnt.end() ; ++itor)
    offset += sprintf(BUF+offset, "%s%d", itor->first.c_str() ,itor->second);
  string wordsig(BUF);

  for(i=0; i<=(int)(S.size() - wordslen); ++i) {
    map<string, int> wordcnt1;
    for(j=0; j < len ; ++j ) {
      string s = S.substr(i+j*wordlen, wordlen);
      if( wordcnt1.find(s) != wordcnt1.end() )
        wordcnt1[s] += 1;
      else
        wordcnt1[s] = 1;
    }
    offset=0;
    for(itor=wordcnt1.begin(); itor!=wordcnt1.end() ; ++itor)
      offset += sprintf(BUF+offset, "%s%d", itor->first.c_str() ,itor->second);
    string wordsig1(BUF);

    if(wordsig1 == wordsig) {
      ans.push_back(i);
    }
  }
  return ans;
}

void Solution::minWindowTest() {
  string s, t;
  while(cin.getline(BUF, BUFN)) {
    stringstream sin(BUF);
    sin >> s >> t;
    string ans = minWindow(s, t);
    cout << ans << endl;
  }
}

string Solution::minWindow(string S, string T) {
  
  int i;
  for(i=0; i<T.size(); ++i)
  
  struct entry { int pos, entry *next; };


  return "";
}
