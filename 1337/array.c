#include "leetcode.h"

int ary[BUFN];
void Solution::searchInsertTest() {
    int i, target;
    while (cin.getline(BUF, BUFN)) {
        stringstream sin(BUF);
        sin >> target;
        for(i=0; sin >> ary[i]; ++i);
        cout << searchInsert(ary, i, target) << endl;
    }
}

int Solution::searchInsert(int A[], int n, int target) {
    if(!n) return 0;
    int s=0,e=n,mid;
    while(s<e) {
        mid = s + (e-s >> 1) ;
        if(A[mid]==target) return mid;
        else if(A[mid] < target) { s = mid+1; }
        else { e = mid; }
    }
    return e;
}

void Solution::removeElementTest() {
    int i, n, elem, ans;
    int * ar;
    cin >> n >> elem;
    ar = (int *) malloc(n*sizeof(int));
    for(i=0; i<n; ++i) cin >> ar[i];
    ans = removeElement(ar, n, elem);
    for(i=0; i<ans; ++i)
      cout << ar[i] << ' ';
    cout << endl;
    free(ar);
}

int Solution::removeElement(int A[], int n, int elem) {
  int i,j;
  for(i=0, j=0; i<n; ++i) {
    if(A[i]!=elem)
      A[j++] = A[i];
  }
  return j;
}

void Solution::removeDuplicatesTest() {
    int i, n, ans;
    int * ar;
    cin >> n ;
    ar = (int *) malloc(n*sizeof(int));
    for(i=0; i<n; ++i) cin >> ar[i];
    ans = removeDuplicates(ar, n);
    for(i=0; i<ans; ++i)
      cout << ar[i] << ' ';
    cout << endl;
    free(ar);
}

int Solution::removeDuplicates(int A[], int n) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  if(n<2) return n;
  int i,j;
  i=1, j=0;
  for(; i<n; ++i) {
    if (A[i]!=A[j])
      A[++j] = A[i];
  }
  return j+1;
}

void Solution::removeDuplicates2Test() {
    int i, n, ans;
    int * ar;
    cin >> n ;
    ar = (int *) malloc(n*sizeof(int));
    for(i=0; i<n; ++i) cin >> ar[i];
    ans = removeDuplicates2(ar, n);
    for(i=0; i<ans; ++i)
      cout << ar[i] << ' ';
    cout << endl;
    free(ar);
}

int Solution::removeDuplicates2(int A[], int n) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  if(n<3) return n;
  int i = 1, j= 0, cnt = 1;
  for( ; i<n; ++i) {
    if( A[i] != A[j] ) {
      A[++j] = A[i];
      cnt = 1;                
    }
    else if ( cnt ) {
      A[++j] = A[i];
      cnt--;
    }
    else {

    }

  }

  return j+1;
}
