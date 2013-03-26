#include "common.h"

void printPermutation(string &s, int currentIdx){
  if(currentIdx == s.size()) {
    cout << s << endl;
    return;
  }

  printPermutation(s, currentIdx+1);

  for(int i=currentIdx+1; i<s.size(); ++i) {
    swap(s[currentIdx], s[i]);
    printPermutation(s, currentIdx+1);
    swap(s[currentIdx], s[i]);
  }

}

int main(int argc, char * argv[]) {

  string s;
  cin >> s;
  
  printPermutation(s, 0);

  return 0;
}
