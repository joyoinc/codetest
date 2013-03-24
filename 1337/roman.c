#include "leetcode.h"

string Solution::intToRoman(int num) {
    string ones [] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens [] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string huns [] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    int sizes [] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2};

    string ans( num/1000, 'M'); num %= 1000;
    ans += huns[ num/100 ]; num %= 100;
    ans += tens[ num/10 ]; num %= 10;
    ans += ones[ num ]; 

    return ans;
}

void Solution::intToRomanTest() {
    int n;
    while(cin >> n) {
        cout << intToRoman(n) << endl;
    }
}
