#include "common.h"

char BUF[BUFN];

string uniqbeauti(string &s) {

  string ans, uniq;
  map<int, int> lastPos;

  for(int i=1; i<=s.length();++i) {
    lastPos[ s[i-1]-'a' ] = i;
  }

  for(int i =25; i>=0; --i) {
    if(lastPos[i]) {
      uniq.push_back('a'+i);
    }
  }

  int startPos = 1;
  while( ans.length() < uniq.length() ) {

    int minPos = s.length()+1;
    char ch;
    for(int i=0; i<26; ++i) {
      if(lastPos[i] && lastPos[i] < minPos) {
        minPos = lastPos[i];
        ch = 'a'+i;
      }
    }

    for(int k=0; k<uniq.length() && uniq[k] > ch; ++k) {
      if(!lastPos[ uniq[k]-'a' ]) continue;
      int pos = startPos;

      for(; pos<=minPos && s[pos-1] != uniq[k]; ++pos);
      if( pos <= minPos ) {
        ans.push_back( uniq[k] );
        lastPos[ uniq[k]-'a' ] = 0;
        startPos = pos+1;
      }
    }

    ans.push_back( ch );
    lastPos[ch-'a'] = 0;
    startPos = minPos+1;

  }
  return ans;
}

int main(int argc, char * argv[]) {

 while(cin.getline(BUF, BUFN)) {
   string s(BUF);
   cout << uniqbeauti(s) << endl;
 }

  return 0;
}
