#ifndef _a9f7ahfas872332b_trie_
#define _a9f7ahfas872332b_trie_

#ifndef TRIE_KIDS
#define TRIE_KIDS 26+1
#endif

struct TrieNode {
    struct TrieNode * next[TRIE_KIDS] ;
    void * pData;

    TrieNode() : pData(0){for(int i=0;i<TRIE_KIDS;++i)next[i]=0;}
};

#endif
