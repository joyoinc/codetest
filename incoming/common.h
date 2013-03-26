#ifndef _43jrlskfabnd_common_
#define _43jrlskfabnd_common_

#define BUFN 65535

extern char BUF[];

#include <iostream>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;

template <class T>
ostream& operator<< (ostream &os, vector<T> &v) {
  os << "[";
  if(v.size())
    os << v[0];
  for(int i=1; i<v.size(); ++i)
    os << "," << v[i];
  os << "]";
}

struct Comp {
  string sig(string &in) {
    string ans(in);
    for(int i=0; i<ans.size(); ++i)
      if('A'<=ans[i] && ans[i]<='Z') ans[i] += 'a'-'A';
    return ans;
  }
  bool operator() (const string &s1, const string &s2) {
    string sig1(s1), sig2(s2);
    return sig(sig1) < sig(sig2);
  }
};

#endif
