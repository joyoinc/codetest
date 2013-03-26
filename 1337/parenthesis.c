#include "leetcode.h"

void Solution::generateParenthesisRecur(vector<string> &res, string current, int left, int right) {
    if (left == 0) {
        string s(right, ')');
        res.push_back(current + s);
        return;
    }

    if (right > left)
        generateParenthesisRecur(res, current + ")", left, right-1);

    generateParenthesisRecur(res, current + "(", left-1, right);
}

vector<string> Solution::generateParenthesis(int n) {

    vector<string> ans;

    generateParenthesisRecur(ans, "", n, n);

    return ans;
}

void Solution::generateParenthesisTest() {
    int n;
    while(cin >> n) {
        vector<string> strs = generateParenthesis(n);
        cout << strs << endl;
    }
}
