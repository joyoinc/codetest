#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i,j,n,cnt=0;
    cin >> n;
    vector<int> ar(n,0);
    for(i=0; i<n; ++i) {
        cin >> ar[i];
    }

    vector<int>::iterator ii;

    for(i=1; i<n; ++i) {
        j = ar[i];
        ii = upper_bound(ar.begin(), ar.begin()+i, j);
        if( ar.begin()+i != ii)
            ++cnt;
        for(int k=i; ar.begin()+k!=ii; --k)
            ar[k] = ar[k-1];
        *ii = j;
    }
    cout << cnt << endl;
}

