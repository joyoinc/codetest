#include "leetcode.h"

void Solution::findSubstringTest() {
  vector<string> L;
  string s;
  while(cin.getline(BUF, BUFN)) {
    stringstream sin(BUF);
    L.clear();
    for(; sin >> s; )
      L.push_back(s);
    L.pop_back();
    vector<int> ans = findSubstring(s, L);
    cout << ans << endl;
  }
}

vector<int> Solution::findSubstring(string S, vector<string> &L) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  int wordlen = L[0].size();
  int len = L.size();
  int wordslen = wordlen * len;
  int i,j,k,startPos, cntMatch;
  vector<int> ans;
  map<string, int> wordcnt;
  for(j=0; j<len ; ++j) {
    if( wordcnt.find(L[j]) != wordcnt.end() )
      wordcnt[L[j]] += 1;
    else
      wordcnt[L[j]] = 1;
  }
  map<string, int>::iterator itor;

  for(i=0; i<wordlen; ++i) {
    map<string, int> wordcnt1(wordcnt);
    startPos = i;
    cntMatch=0;
    for( ; startPos+wordslen <= S.size();  ) {
        string s = S.substr(startPos + cntMatch*wordlen, wordlen);
        if( wordcnt1.find(s) == wordcnt1.end() ) {
            wordcnt1 = wordcnt;
            startPos += (cntMatch+1)*wordlen;
            cntMatch = 0;
        }
        else if(wordcnt1[s]==0) {
            for(k=startPos; S.substr(k, wordlen)!=s; k+=wordlen) {
                wordcnt1[ S.substr(k, wordlen) ] += 1;
                --cntMatch;
            }
            startPos = k + wordlen;
        }
        else {
            wordcnt1[s] -= 1;
            ++cntMatch;
            if(cntMatch==len) {
                ans.push_back(startPos);
                string s = S.substr(startPos, wordlen);
                wordcnt1[s] += 1;
                --cntMatch;
                startPos += wordlen;
            }
        }
    }
  }
  sort(ans.begin(), ans.end());
  return ans;
}

void Solution::minWindowTest() {
  string s, t;
  while(cin.getline(BUF, BUFN)) {
    stringstream sin(BUF);
    sin >> s >> t;
    string ans = minWindow(s, t);
    cout << ans << endl;
  }
}

string Solution::minWindow(string S, string T) {
  struct entry { int val; entry *prev; entry *next;
    //entry(int i=0) : val(i), prev(0), next(0) {}
  };
  entry * cht[128] = {0} ;
  int i;
  for(i=0; i<T.size(); ++i) {
    entry * p = cht[T[i]];
    if(!p) cht[T[i]] = p = new entry();
    p->val++;
  }

  int minSize = S.size();
  int minPos, ansPos=0;
  int j,k;
  bool found=false;
  bool updateSize;
  for(i=0; i<S.size(); ++i) {
    entry * p = cht[S[i]];
    if(!p) continue;
    updateSize = false;

    if(found) {
        int replaced = p->next->val;
        p->next->val = i;
        p->next = p->next->next;
        if(replaced==minPos)
            updateSize=true;
    }
    else {
        if(p->val==0) {
            p->next->val = i;
            p->next = p->next->next;
        }
        else {
            p->val--;
            entry *nnode = new entry();
            nnode->val = i;
            if(!p->next) {
                p->next = nnode->next = nnode->prev = nnode;
            }
            else {
                nnode->next = p->next;
                nnode->prev = p->next->prev;
                nnode->prev->next = nnode->next->prev = nnode;
            }
            for(j=0; j<128 && (!cht[j] || !cht[j]->val); ++j);
            updateSize = found = j==128;
        }
    }

    if(updateSize) {
        minPos = S.size();
        for(j=0; j<128; ++j) {
            if(cht[j]) {
                k = cht[j]->next->val;
                if(k<minPos) minPos=k;
            }
        }
        if( (i-minPos+1) < minSize ) {
            minSize = (i-minPos+1);
            ansPos = minPos;
        }
    }
  }

  if(found)
      return S.substr(ansPos, minSize);
  else
      return "";
}

void Solution::strStrTest() {
  char *d;
  while(cin.getline(BUF, BUFN)) {
    d = strchr(BUF, ' ');
    *d++ = 0;
    string ans = strStr(BUF, d);
    cout << ans << endl;
  }

}

char * Solution::strStr(char *haystack, char *needle) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int n = strlen(needle);
    if(!n) return haystack;
    int * next = (int*)malloc((n+1)*sizeof(int));
    // next start from 1
    // express the max length of true suffix which is also prefix
    // calc next
    int i, j, lenOflongestPrefix=0;
    next[1] = 0;
    for(i=2; i<=n; ++i) {
        while(lenOflongestPrefix && needle[lenOflongestPrefix]!=needle[i-1])
            lenOflongestPrefix = next[lenOflongestPrefix];
        if(needle[lenOflongestPrefix]==needle[i-1])
            lenOflongestPrefix++;
        next[i] = lenOflongestPrefix;
    }

    // use next to match
    for(i=0,j=0; haystack[i]; ++i) {
        while(j && haystack[i]!=needle[j]) j = next[j];
        if(haystack[i]==needle[j]) 
            ++j;
        if(j==n) return haystack+i-(n-1);
    }
    free(next);
    return 0;
}

void Solution::isValidTest() {
    while(cin.getline(BUF, BUFN)) {
        string s(BUF);
        bool ans = isValid(s);
        cout << ans << endl;
    }
}

bool Solution::isValid(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    stack<char> sk; sk.push('^');

    for(int i=0; i<s.length(); i++) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') 
            sk.push(s[i]);

        if(s[i]==')') { if(sk.top()=='(') sk.pop(); else return false;}
        if(s[i]=='}') { if(sk.top()=='{') sk.pop(); else return false;}
        if(s[i]==']') { if(sk.top()=='[') sk.pop(); else return false;}
    }
    return sk.top()=='^';
}

