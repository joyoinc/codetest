#include "common.h"

char BUF[BUFN];

int T = 1;
int N = 1; // 1 <= N <= 100000
int Q = 1; // 1 <= Q <= 50000

int x[1000001];
int l[1000001];

int xorq(int p, int q, int a) {
    int i, tmp, ans= x[p]^a;

    for(i=p+1; i<=q; ++i) {
        tmp = x[i]^a;
        if(tmp > ans) ans = tmp;
    }

    return ans;
}

int main(int argc, char * argv[]) {

    scanf("%d", &T); gets(BUF);
    while(T) {
        scanf("%d %d", &N, &Q);
        gets(BUF);
        int i, a, p, q;
        for(i=1; i<=N; ++i) {
            scanf("%d", x+i);
        }
        gets(BUF);
        for(i=0; i<Q; ++i) {
            scanf("%d %d %d", &a, &p, &q);
            gets(BUF);
            printf("%d\n", xorq(p, q, a));
        }

        --T;
    }
    return 0;
}
