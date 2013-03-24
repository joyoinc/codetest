#include "common.h"
#include "trie.h"

TrieNode root;
char BUF[BUFN];

void buildTrie(char * pch) {
    TrieNode * cur = &root;
    for(; *pch; ++pch) {
        char ch = *pch;
        int idx=0;
        if('a'<=ch && ch<='z') idx = ch-'a'+1;
        else if('A'<=ch && ch<='Z') idx = ch-'A'+1;
        if( !cur->next[idx] )
            cur->next[idx] = new TrieNode();
        cur = cur->next[idx];
    }
}

TrieNode * findWord(TrieNode * p, char * pch) {
    if(p && *pch) {
        char ch = *pch;
        int idx=0;
        if('a'<=ch && ch<='z') idx = ch-'a'+1;
        else if('A'<=ch && ch<='Z') idx = ch-'A'+1;
        if(p->next[idx])
            return findWord(p->next[idx], pch+1);
    }
    return p;
}

void printTrie(TrieNode * tree, string s) {
    if(!tree) { cout << endl; }
    int i, j=0;
    for(i=0; i<TRIE_KIDS; ++i) {
        if(tree->next[i]) {
            ++j; 
            string st(1, 'a'+i-1);
            printTrie(tree->next[i], s+st);
        }
    }
    if(!j)
        cout << s << endl;
}

int main() {
    //while(cin.getline(BUF, BUFN)) {
    while(gets(BUF)) {
        if(strstr(BUF, "$$$"))
            printTrie(&root, "");
        else if(strstr(BUF, "^^^"))
            printTrie(findWord(&root, &BUF[3]), "");
        else
            buildTrie(BUF);
    }

    return 0;
}
