#ifndef _1k34h1h412j4_leetcode_
#define _1k34h1h412j4_leetcode_

#define BUFN 65535

extern char BUF[];

#include<iostream>
#include<sstream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<set>
#include<map>

using namespace std;

struct Solution {
  bool isPalindrome(string s);
  void isPalindromeTest();
  vector<string> anagrams(vector<string> &strs);
  void anagramsTest();
  int minimumTotal(vector<vector<int> > &triangle) ;
  void minimumTotalTest() ;
};

template <class T>
ostream& operator<< (ostream &os, vector<T> &v) {
  os << "[";
  if(v.size())
    os << v[0];
  for(int i=1; i<v.size(); ++i)
    os << "," << v[i];
  os << "]";
}

struct CompString1 {
  bool operator() (const string &s1, const string &s2) {
    const char * c1 = s1.c_str();
    const char * c2 = s2.c_str();
    return strcasecmp(c1, c2) < 0;
  }
};

#endif
