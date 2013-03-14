#include "common.h"

char BUF[BUFN];

map<string, string> mP;
int N = 1; // 1 <= N <= 8
int K = 3; // 3 <= K <= 5

char r1(char in) {
	short s = in ^ (in-1);
    return (char) (s+1)>>1;
}

void output(string &e) {
  deque<string> q;
  string s;
  for(s=e; s!=mP[s]; s=mP[s])
    q.push_front(s);
  cout << q.size() << endl;
  for(int i=0; i<q.size(); ++i) {
    int k,kk;
    for(k=1; k<=K && s[k]==q[i][k]; ++k);
    char c = s[k] ^ q[i][k];
    for(kk=1+k; kk<=K && s[kk]==q[i][kk]; ++kk);
    if(c & s[k])
      cout << k << " " << kk << endl;
    else
      cout << kk << " " << k << endl;
    s = q[i];
  }
}

void bfs(string &s, string &e) 
{
  deque<string> q;
  q.push_back(s); mP[s] = s;
  while(!q.empty()) {
    string h = q.front(); q.pop_front();

    for(int i=1; i<=K; ++i) {
      if(h[i]) {
        for(int j=1; j<=K; ++j) {
          char c = r1(h[i]);
          if(j!=i &&  r1(h[i]|h[j]) == c ) {
            string as(h);
            as[i] &= ~(c);
            as[j] |= c;

            if(mP.find(as) == mP.end()) {
              q.push_back(as); mP[as] = h;

              if(as == e) {
                output(e);
                return;
              }
            }
          }
        }
      }
    }
  }
}
int main(int argc, char * argv[]) {

  cin >> N >> K;
  string s(6, 0);
  string e(s);
  int k;
  for(int i=0; i<N; ++i) {
    cin >> k;
    s[k] |= 0x1<<i;
  }
  for(int i=0; i<N; ++i) {
    cin >> k;
    e[k] |= 0x1<<i;
  }

  bfs(s,e);
  return 0;
}
