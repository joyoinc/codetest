#include <stack>
#include <set>
#include <vector>
#include <map>
#include "math.h"

using namespace std;
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

typedef struct HashNode* HashNodePtr;

struct HashNode {
	char * key;
	HashNodePtr next;
};

const int HASHMAX = 29989;
const int HASHMUL = 31;
unsigned int HashCode(char * c) {
	unsigned int ans = 0;
	for(; *c; c++)	{ ans *= HASHMUL; ans += *c; }
	return ans % HASHMAX;
}

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return trapRecur(A, 0, n);
    }
    
    int trapRecur(int A[], int start, int n) {
        if(n-start < 3) return 0;
        int j, i = start+1;
        for(; i<n && A[i]>A[i-1]; ++i);
        if(i>=n-1) return 0;
        int maxi = i, max=A[i];
        for(j=i+1; j<n && max<A[i-1]; ++j) {
            if(A[j] > max) {
                max = A[j];
                maxi = j;        
            }
        }
        
        int k, bh, sum = 0;
        bh = max < A[i-1] ? max : A[i-1];
        for(k=i; k<maxi; ++k)
            sum += bh - A[k];
        return sum + trapRecur(A, maxi, n);
    }

	    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s1.size();
        if(n<2) return s1==s2;
        
        map< pair< pair<int,int> , int> , int > v2d;
        
        return isScramble(s1, 0, n-1, s2, 0, n-1, v2d);
    }
    
      
        bool isScramble(string &s1, int l1, int r1, string &s2, int l2, int r2, map< pair< pair<int,int> , int> , int >  &m ) {
        
			pair< pair<int,int> , int> key = make_pair(make_pair(l1, l2) , r1-l1);
			if ( m.find( key )  != m.end() )
				return m[key] > 0 ;
        
        bool ans = false;   
        int i;
        for(i=l1; i<=r1 && s1[i] == s2[l2+i-l1]; ++i);
        ans = i > r1;        
        
        for(i=l1; i<=r1-1 && !ans; ++i) {

			if( isScramble(s1, l1, i, s2, l2, l2-l1+i, m) 
            && isScramble(s1, i+1, r1, s2, l2-l1+i+1, r2, m) ) {
                ans = true;
				
            }

            else if( isScramble(s1, l1, i, s2, r2+l1-i, r2, m) 
            && isScramble(s1, i+1, r1, s2, l2, r1+l2-i-1, m) ) {
                ans = true;
				
            }
            
        }
        
        m[key] = ans ? 1 : -1;
        return ans;

    }

	int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = triangle.size();
        if(!len) return 0;
        
        vector<int> work(triangle[len-1]);
        
        for(; len>1; --len) {
            
            for(int i=0; i<=len-2; --i) {
                
                if(work[i+1] < work[i]) work[i] = work[i+1];
                work[i] += triangle[len-2][i];
                
            }
            
        }      
        return work[0];
    }

	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    reverse(candidates.begin(), candidates.end());

    vector<vector<int> > ans;
    vector<int> work;
    dfs(ans, work, candidates, 0, target);

    return ans;
}

void dfs(vector<vector<int> > &res, vector<int> &work, vector<int> &input, int start, int target) {

    if(target < 0) { return; }
    if(target == 0) { res.push_back(work); return; }
	if(start == input.size()) {return;}

	int mx = target / input[start];
    int remain = target - mx * input[start];

	for(int i=mx; i>0; --i) work.push_back(input[start]);
	for(int i=mx; i>0; --i) {
	
		dfs(res, work, input, start+1, remain);
		work.pop_back();
        remain += input[start];
	}

}

    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        pair<int, int> * pivl;
        
        map<int, pair<int, int> * > mapIntvl;
        
        int maxSize = 0;
        for(int i=0; i<num.size(); ++i) {
            
            if( mapIntvl.find( num[i] ) != mapIntvl.end() )
                continue;
                
            int flag = 0;
            int size1 = 0;
            int size2 = 0;
            
            if( mapIntvl.find( num[i]+1 ) != mapIntvl.end() ) {
                flag |= 1;
                
                mapIntvl[ num[i]+1 ]->first = num[i];
                
                mapIntvl[ num[i] ] = mapIntvl[ num[i]+1 ];
                
                size1 = mapIntvl[ num[i]+1 ]->second - mapIntvl[ num[i]+1 ]->first + 1;
            }
            
            if( mapIntvl.find( num[i]-1 ) != mapIntvl.end() ) {
                flag |= 2;
                
                mapIntvl[ num[i]-1 ]->second = num[i];
                
                mapIntvl[ num[i] ] = mapIntvl[ num[i]-1 ];
                
                size2 = mapIntvl[ num[i]-1 ]->second - mapIntvl[ num[i]-1 ]->first + 1;
            }
            
            if(flag == 0) {
				pivl = new pair<int, int> (num[i], num[i]);
                mapIntvl[ num[i] ] = pivl;
                size1 = 1;
            }
            
            if(flag == 3) {
				              
                if( size1 > size2 ) {
					pivl = mapIntvl[ num[i]-1 ];

                    mapIntvl[ num[i]+1 ]->first = mapIntvl[ num[i]-1 ]->first;
                    
                    for(int j = mapIntvl[ num[i]-1 ]->first; 
                        j <= mapIntvl[ num[i]-1 ]->second; ++j)
                        mapIntvl[ j ] = mapIntvl[ num[i]+1 ];
                }
                else {
					pivl = mapIntvl[ num[i]+1 ];

                    mapIntvl[ num[i]-1 ]->second = mapIntvl[ num[i]+1 ]->second;
                    
                    for(int j = mapIntvl[ num[i]+1 ]->first; 
                        j <= mapIntvl[ num[i]+1 ]->second; ++j)
                        mapIntvl[ j ] = mapIntvl[ num[i]-1 ];

                }
				delete pivl;                
                size1 += size2 - 1;
            }
            
            if(size2 > size1) size1 = size2;
            
            if(size1 > maxSize) maxSize = size1;
            
        }
        
        return maxSize;
    }

	int N;
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        N = board.size();
        
        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
                if(board[i][j] == 'O')
                    if( i==0 || j==0 || i==N-1 || j==N-1 )
                        board[i][j] = 'S';
                
        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
				if(board[i][j] == 'S')
					visit(board, i, j);
                
        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
                if(board[i][j] == 'D')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
    }
    
    void visit(vector<vector<char>> &board, int r, int c) {
        if( r<0 || c<0 || r >= N || c > N
            || board[r][c] == 'X'
            || board[r][c] == 'P'
            || board[r][c] == 'D'
        ) return ;
        
        board[r][c] = 'P' ;
        
        visit(board, r-1, c);
        visit(board, r+1, c);
        visit(board, r, c-1);
        visit(board, r, c+1);
        
        board[r][c] = 'D';
    }
    

	bool isPalindrome(string s) {
         string ss;
        for(int i=0; i<s.size(); ++i) {
            if('A' <= s[i] && s[i] <= 'Z')
                s[i] += 'a' - 'A';
            if('a' <= s[i] && s[i] <= 'z'
			|| '0' <= s[i] && s[i] <= '9')
                ss.push_back(s[i]);
        }
        
        int l = 0;
        int r = ss.size()-1;
        for(;l<r;++l,--r) {
            if ( ss[l] != ss[r] )
                return false;
        }
        return true;
    }

	bool exist(vector<vector<char> > &board, string word) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<char> > visited = board;
		for(int i=0; i<board.size(); ++i)
			for(int j=0; j<board[i].size(); ++j)
				visited[i][j] = 0;
		for(int i=0; i<board.size(); ++i)
			for(int j=0; j<board[i].size(); ++j)
				if(match(board, visited, i, j, word, 0))
					return true;
		return false;
	}

	bool match(vector<vector<char> > &board, vector<vector<char> > &visited, int r, int c
		, string & word, int p) {		
			if(p == word.size()) return true;
			if(r<0 || c<0 || r>=visited.size() || c>=visited[r].size() 
				|| visited[r][c] 
				|| word[p] != board[r][c]) return false;


			visited[r][c]=1;
			int roff[4] = {-1, 1, 0 , 0};
			int coff[4] = {0, 0, -1, 1};
			for(int k=0; k<4; k++) {
				int rr = r+roff[k];
				int cc = c+coff[k];
				if(match(board, visited, rr, cc, word, p+1))
					return true;
			}
			visited[r][c]=0; return false;
	}

	int getLength(ListNode *p) {
		int len = 0;
		for(;p;p=p->next,len++);
		return len;
	}
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(getLength(l1)<getLength(l2))
			return addTwoNumbers(l2,l1);

		ListNode * prev;
		ListNode * ans = l1;
		int carry=0;
		while(l1) {
			carry += l1->val;
			carry += l2 ? l2->val : 0;
			l1->val = carry%10;
			carry /= 10;

			prev = l1;
			l1=l1->next;
			if(l2) l2=l2->next;
		}
		if(carry) {
			prev->next = new ListNode(1);
		}

		return ans;
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = inorder.size();

		return buildTreeHelper(inorder, postorder, 0, n-1, 0, n-1);   
	}


	TreeNode *buildTreeHelper(vector<int> &inorder, vector<int> &postorder
		,int is, int ie, int ps, int pe) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			if(is>ie||ps>pe) return NULL;

			TreeNode * root = new TreeNode(postorder[pe]);
			int i=is; while(i<=ie && inorder[i]!=postorder[pe]) i++;
			root->left = buildTreeHelper(inorder, postorder, is, i-1, ps, ps+i-1-is);
			root->right = buildTreeHelper(inorder, postorder, i+1, ie, ps+i-is, pe-1);
			return root;
	}

	void placeQueen(int r, vector<vector<string> > &res, vector<int> &work) {
		if(r == work.size()) {
			// output
			vector<string> sol;
			for(int i=0; i<work.size(); i++) {
				string s(work.size(), '.');
				s[work[i]] = 'Q';
				sol.push_back(s);
			}
			res.push_back(sol);
			return;
		}

		for(int c=0; c<work.size(); c++) {
			int t=0; bool ok = true; work[r]=c;
			while(t<r && ok) {
				int cdiff = work[t]-work[r];
				ok = cdiff != 0 && cdiff != t-r && cdiff != r-t;
				t++;
			}
			if(!ok) continue;
			placeQueen(r+1, res, work);
		}
	}

	vector<vector<string> > solveNQueens(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		vector<vector<string> > res;
		vector<int> v(n,-1);
		placeQueen(0, res, v);
		return res;
	}

	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		return intervals;
	}	

	int minDistance(string word1, string word2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int m = word1.length() + 1;
		int n = word2.length() + 1;
		vector<vector<int> > table;
		vector<int> row(n,0);
		for(int i=0; i<m; i++) { row[0] = i; table.push_back(row); }
		for(int i=0; i<n; i++) { table[0][i] = i; }

		for(int i=1; i<m; i++) {
			for(int j=1; j<n; j++) {
				int d1 = min(table[i-1][j], table[i][j-1]) + 1;
				int d2 = table[i-1][j-1] + (word1[i-1]==word2[j-1] ? 0 : 1);
				table[i][j] = min(d1,d2);
			}
		}
		return table[m-1][n-1];
	}
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

	}

	vector<int> inorderTraversal(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		stack<TreeNode*> sk; // store all nodes
		set<TreeNode*> st; //  node has expand
		vector<int> res;
		TreeNode * p;

		sk.push(root);

		while(!sk.empty()) {
			p = sk.top(); sk.pop();
			if(!p) continue;

			if(st.find(p) != st.end()) { // in set, expanded, just output
				res.push_back(p->val);
			} else { // not in set, to expand it
				sk.push(p->right);
				sk.push(p);
				sk.push(p->left);
				st.insert(p);
			}
		}

		return res;
	}

	vector<vector<int> > combine(int n, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		vector<vector<int> > res;   


		combineHelper(n, k, res);

		return res;
	}

	void combineHelper(int n, int k, vector<vector<int> > &res ) {

		vector<int> v;
		if(k==n) {
			for(int i=0; i<k; i++)
				v.push_back(i+1);
			res.push_back(v);
		} else if(k==1) {
			for(int i=0; i<n; i++) {
				vector<int> v;
				v.push_back(i+1);
				res.push_back(v);
			}
		} else {
			combineHelper(n-1, k, res);

			combineHelper(n-1, k-1, res);

			for(int i=0; i<res.size(); i++) {
				if(res[i].size()!=k)
					res[i].push_back(n);
			}
		}
	}



	vector<int> grayCode(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> res(2,0);
		res.back() = 1;
		for(int j=2; j<=n; j++) {
			int size = res.size();
			for(int i=size-1; i>=0; i--) {
				res.push_back( res[i] + 1<<(j-1));
			}
		}
		return res;
	}

	int divide(int dividend, int divisor) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		// if (!divisor)     
		bool neg = dividend < 0 && divisor > 0
			|| dividend > 0 && divisor < 0;

		unsigned int a, b;
		a = dividend < 0 ? (unsigned int) -dividend : (unsigned int) dividend;
		b = divisor < 0 ? (unsigned int) -divisor : (unsigned int) divisor;

		//if(b == 1<<31) return a == 1<<31 ? 1 : 0;

		int c = 0;
		while( a > b<<c && c<32 ) c++;

		unsigned int res = 0;

		while(c >= 0) {
			if( a >= b<<c ) {
				a -= b<<c;
				res += 1<<c;
			}
			c--;
		}

		return neg ? -res : res;

	}
};

class Base {
public :
	virtual void func1(int i) { cout << "Base :: func1" << endl; }
};

class Dev : public Base {
public :
	//virtual void func1(int i) { cout << "Dev :: func1" << endl; }
};