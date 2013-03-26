
#include "common.h"

char BUF[BUFN];

int bin2int(char * pch) {
    int n=0;
    while(pch && (*pch)) {
        if((*pch) == '0' || '1'==(*pch)) {
            n <<=1;
            n += (*pch)-'0';
        }
        ++pch;
    }
    return n;
}

char * int2bin(int n) {
    int i=0;
    while(n) {
        BUF[i++] = n%2+'0';
        n>>=1;
    }
    BUF[i]=0;
    int j=0;
    for(;j<i-1; ++j, --i) {
        BUF[j] ^= BUF[i-1];
        BUF[i-1] ^= BUF[j];
        BUF[j] ^= BUF[i-1];
    }
    return BUF;
}

int setIJofN2IJofM(int n, int m, int i, int j) {
    int ms1, ms2, ms;
    ms1 = (1<<i)-1;
    ms2 = (1<<j)-1;
    ms = ms2-ms1;
    return (m & ms) | (n & ~ms);
}

int swapIJ(int n, int i, int j) {
    if( (n>>i ^ n>>j) & 0x1) {
        n ^= (1<<i | 1<<j);
    }
    return n;
}

int main() {

    char ch;
    int n,m,i,j;
    while( scanf("%c", &ch) ) {
        switch(ch) {
            case 'b':
                gets(BUF);
                printf("%d\n", bin2int(BUF));
                break;
            case 'i':
                scanf("%d", &n);
                printf("%s\n", int2bin(n));
                gets(BUF);
                break;
            case 's':
                scanf("%d %d %d", &n, &i, &j);
                printf("%d\n", swapIJ(n,i,j));
                gets(BUF);
                break;
            case 'u':
                scanf("%d %d %d %d", &n, &m, &i, &j);
                printf("%d\n", setIJofN2IJofM(n,m,i,j));
                gets(BUF);
                break;
            default:
                return 0;
        }
    }
    return 0;
}

