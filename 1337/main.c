#include "leetcode.h"

char BUF[BUFN];

void run(char * funcname) {
  Solution sol;
  map<string, void(Solution::*)() , CompString1> mpFunc;
  mpFunc["isPalindrome"] = &Solution::isPalindromeTest;
  mpFunc["anagrams"] = &Solution::anagramsTest;

  string strfunc(funcname);
  if(mpFunc.find(strfunc) != mpFunc.end()) {
    (sol.*mpFunc[strfunc])();
  }
  else {
    cout << "No such function :" << funcname << endl;
  }
}

int main(int argc, char * argv[]) {

  if(argc < 2) {
    CompString1 comp;
    cout << comp( "aa","isPalindromeTest") << endl;
    cout << "Usage: leetcode <function name> " << endl;
    return 0;
  }
  
  run(argv[1]);
  return 0;
}