#include "leetcode.h"

void Solution::buildTreeFromInPostTest() {
  while(cin.getline(BUF, BUFN)) {
    stringstream sin(BUF);
    int i;
    vector<int> inorder;
    for(; sin >> i; )
      inorder.push_back(i);
    cin.getline(BUF, BUFN);
    stringstream sin2(BUF);
    vector<int> postorder;
    for(; sin2 >> i; )
      postorder.push_back(i);
    cout << buildTreeFromInPost(inorder, postorder) << endl;
  }
}

TreeNode * Solution::buildTreeFromInPostRecur(vector<int>::iterator i1, vector<int>::iterator i2, int n) {
  if(!n) return 0;
  int i,k = *(i2+n-1);
  TreeNode * h = new TreeNode(k);
  for(i=0; i<n && *(i1+i)!=k; ++i);
  h->left = buildTreeFromInPostRecur(i1, i2, i);
  h->right = buildTreeFromInPostRecur(i1+i+1, i2+i, n-1-i);
  return h;
}

TreeNode * Solution::buildTreeFromInPost(vector<int> &inorder, vector<int> &postorder) {
  return buildTreeFromInPostRecur(inorder.begin(), postorder.begin(), postorder.size());
}

void Solution::buildTreeFromPreInTest() {
  while(cin.getline(BUF, BUFN)) {
    stringstream sin(BUF);
    int i;
    vector<int> preorder;
    for(; sin >> i; )
      preorder.push_back(i);
    cin.getline(BUF, BUFN);
    stringstream sin2(BUF);
    vector<int> inorder;
    for(; sin2 >> i; )
      inorder.push_back(i);
    cout << buildTreeFromPreIn(preorder, inorder) << endl;
  }
}

TreeNode * Solution::buildTreeFromPreInRecur(vector<int>::iterator i1, vector<int>::iterator i2, int n) {
  if(!n) return 0;
  int i,k = *(i1);
  TreeNode * h = new TreeNode(k);
  for(i=0; i<n && *(i2+i)!=k; ++i);
  h->left = buildTreeFromPreInRecur(i1+1, i2, i);
  h->right = buildTreeFromPreInRecur(i1+i+1, i2+i+1, n-1-i);
  return h;
}

TreeNode * Solution::buildTreeFromPreIn(vector<int> &preorder, vector<int> &inorder) {
  return buildTreeFromPreInRecur(preorder.begin(), inorder.begin(), inorder.size());
}
