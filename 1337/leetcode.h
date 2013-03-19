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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(0) {}

  void free() { if(next){ next->free(); delete next; } }

  friend ostream& operator<< (ostream &os, ListNode * p) {
    if(!p) {}
    else if(p && p->next)
      os << p->val << ',' << p->next;
    else
      os << p->val;
    return os;
  }
} ;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(0), right(0) {}

  friend ostream& operator<< (ostream &os, TreeNode * p) {
    if(p) 
      os << p->val << p->left << p->right ;
    else
      os << '#' ;
    return os;
  }
};

template <class T>
ostream& operator<< (ostream &os, vector<T> &v) {
  os << "[";
  if(v.size())
    os << v[0];
  for(int i=1; i<v.size(); ++i)
    os << "," << v[i];
  os << "]";
  return os;
}

struct CompString1 {
  bool operator() (const string &s1, const string &s2) {
    const char * c1 = s1.c_str();
    const char * c2 = s2.c_str();
    return strcasecmp(c1, c2) < 0;
  }
};

struct Solution {
  bool isPalindrome(string s);
  void isPalindromeTest();

  vector<string> anagrams(vector<string> &strs);
  void anagramsTest();

  int minimumTotal(vector<vector<int> > &triangle) ;
  void minimumTotalTest() ;

  TreeNode * buildTreeFromInPostRecur(vector<int>::iterator i1, vector<int>::iterator i2, int n) ;
  TreeNode * buildTreeFromInPost(vector<int> &inorder, vector<int> &postorder) ;
  void buildTreeFromInPostTest() ;

  TreeNode * buildTreeFromPreInRecur(vector<int>::iterator i1, vector<int>::iterator i2, int n) ;
  TreeNode * buildTreeFromPreIn(vector<int> &preorder, vector<int> &inorder) ;
  void buildTreeFromPreInTest() ;

  vector<int> grayCode(int n);
  void grayCodeTest();

  ListNode * partition(ListNode *head, int x) ;
  void partitionTest() ;

  ListNode * reverseBetween(ListNode *head, int m, int n) ;
  void reverseBetweenTest() ;
};

#endif
