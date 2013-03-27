#include "common.h"

int M, N;

void dfs(vector< vector<int> > &v2d, int r, int c) {

  if( r<0 || c<0 || r>=M || c>=N || !v2d[r][c])
    return;

  v2d[r][c] = 0;
  dfs(v2d, r+1, c);
  dfs(v2d, r-1, c);
  dfs(v2d, r, c+1);
  dfs(v2d, r, c-1);
}

int group1s(vector< vector<int> > &v2d) {
  int cnt=0;
  for(int i=0; i<M; ++i) {
    for(int j=0; j<N; ++j) {
      if(v2d[i][j]) {
        dfs(v2d, i, j);
        ++cnt;
      }
    }
  }
  return cnt;
}

int main(int argc, char * argv[]) {

  cin >> M >> N;

  vector<int> v(N, 0);
  vector< vector<int> > v2d;

  for(int i=0; i<M; ++i) {
    for(int j=0; j<N; ++j) {
      cin >> v[j];
    }
    v2d.push_back(v);
  }
  
  cout << group1s(v2d) << endl;

  return 0;
}


