#include "leetcode.h"

void Solution::minimumTotalTest() {
    vector<vector<int> > tri;
    while(cin.getline(BUF, BUFN)) {
        vector<int> line;
        int i;
        stringstream sin(BUF);
        for(; sin >> i; ) {
            line.push_back(i);
        }
        tri.push_back(line);
    }
    cout << minimumTotal(tri) << endl;
}

int Solution::minimumTotal(vector<vector<int> > &triangle) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int len = triangle.size();
    if(!len) return 0;

    vector<int> work(triangle[len-1]);

    for(int r=len-2; r>=0; --r) {
        for(int c=0; c<=r; ++c) {
            if(work[c+1] < work[c]) work[c] = work[c+1];
            work[c] += triangle[r][c];

        }

    }
    return work[0];
}
