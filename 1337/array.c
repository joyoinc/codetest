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
