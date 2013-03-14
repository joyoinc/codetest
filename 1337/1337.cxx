Please write complete compilable code.
Read input from standard input (STDIN) and print output to standard output(STDOUT).

class Solution {
public:

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
        if(r<0 || c<0 || r>=board.size() || c>=board[r].size()) return false;
        if(word[p] != board[r][c]) return false;
        
        visited[r][c]=1;
        int roff[4] = {-1, 1, 0 , 0};
        int coff[4] = {0, 0, -1, 1};
        for(int k=0; k<4; k++) {
            int rr = r+roff[k];
            int cc = c+coff[k];
            if(visited[rr][cc]) continue;
            if(match(board, visited, rr, cc, word, p+1))
                return true;
        }
        visited[r][c]=0; return false;
        
    }

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = inorder.size();
        if(!n) return 0;
        assert(n);
        int n2 = postorder.size();
        assert(n2); assert(n==n2);
        
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

	string intToRoman(int num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		string ones [] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		string tens [] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
		string huns [] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
		int sizes [] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2};

		int n = (num/1000);
		string ans(n, 'M');
		num %= 1000;

		ans += huns[num/100]; num %=100;
		ans += tens[num/10]; num %=10;
		ans += ones[num];

		return ans;
	}

	int romanToInt(string s) {
		int ans = 0; 
		int i = 0;
		while (s[i]=='M' && i<s.length()) { ans+=1000; i++; }
		
		while (i<s.length()) {
			if(s[i]=='D') { ans+=500; i++; } 
			if(s[i]=='C') { 
				if(i+1<s.length() && s[i+1]=='M') { ans+=900; i+=2; }
				else if(i+1<s.length() && s[i+1]=='D') { ans+=400; i+=2; }
				else { ans+=100; i++; }
				continue;
			}
			if(s[i]=='L') { ans+=50; i++; } 
			if(s[i]=='X') { 
				if(i+1<s.length() && s[i+1]=='C') { ans+=90; i+=2; }
				else if(i+1<s.length() && s[i+1]=='L') { ans+=40; i+=2; }
				else { ans+=10; i++; }
				continue;
			}
			if(s[i]=='V') { ans+=5; i++; } 
			if(s[i]=='I') { 
				if(i+1<s.length() && s[i+1]=='X') { ans+=9; i+=2; }
				else if(i+1<s.length() && s[i+1]=='V') { ans+=4; i+=2; }
				else { ans+=1; i++; }
				continue;
			}
		}
		return ans;
	}

	bool isValid(string s) {
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

	vector<int> grayCode(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> res(1,0);
		for(int j=1; j<=n; j++) {
			int size = res.size();
			for(int i=size-1; i>=0; i--) {
				res.push_back( res[i] + (1<<(j-1)));
			}
		}
		return res;
	}

	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		// to do
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int s=0; int e = intervals.size();
		int m;
		while(s<e) {
			m = (s+e)/2;
			if(intervals[m].start > newInterval.start) e = m;
			else s = m + 1;
		}

		return intervals;
	}

	void placeQueen(int r, vector<vector<string> > &res, vector<int> &work) {
		if(r == work.size()) {
			// output
			vector<string> sol;
			for(int i=0; i<work.size(); i++) {
				string s(".", work.size());
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
				bool aok = cdiff != 0 && cdiff != t-r && cdiff != r-t;
				ok &&= aok;
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

	int removeDuplicates(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n<2) return n;
		int i=n;
		while(i) {
			if(A[i-1]==A[i-2]) {
				for(int j=i-1; j<n; j++) { A[j] = A[j+1]; }
				n--;
			} 
			i--;
		}
		return n;
	}

	int removeDuplicates(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		const int rep = 3;
		if(n<rep) return n;
		int i=n;
		int count = rep-1;
		while(i) {
			if(!count) {
				for(int j=i-1; j<n; j++) { A[j] = A[j+1]; }
				n--; count++;
			}
			else if(A[i-1]==A[i-2]) {
				count--; i--;
			} else {
				count = rep-1; i--;
			}
		}
		return n;
	}

	ListNode *deleteDuplicates(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!head || !head->next) return head;
		ListNode *pre = head;
		ListNode *cur = head->next;

		while(cur) {
			if(pre->val==cur->val) {
				pre->next = cur->next;
				delete cur;
				cur = pre->next;
			} else {
				pre = pre->next;
				cur = cur->next;
			}
		}

		return head;
	}

	ListNode *deleteDuplicates(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ListNode sen(INT_MIN); sen.next = head;
		ListNode *pre = &sen;
		ListNode *cur = head;

		while(cur) {
			if(cur->val==sen.val) {
				pre->next = cur->next;
				delete cur;
				cur = pre->next;
			} else if(cur->next && cur->next->val==cur->val) {
				sen.val = cur->val;
			} else {
				pre = pre->next;
				cur = cur->next;
			}
		}

		return sen.next;
	}

	int removeElement(int A[], int n, int elem) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int t, end = n;
		while(end && A[end-1]==elem) end--;
		if(!end) return end;
		int i=0;
		while(i<end) {
			if(A[i] == elem) {
				t = A[i]; A[i] = A[end-1]; A[end-1] = t;
				end--;
				t = A[i]; A[i] = A[end-1]; A[end-1] = t;
			} else {
				i++;
			}
		}
		return end;
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

	string countAndSay(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		string s = "1";
		while(n>1) {
			string ns;
			int i=0; char tc=s[i]; int c=0;
			while(i<s.length()) {
				if(tc==s[i]) { c++; i++;}
				else { 
					ns.push_back(c+'0'); ns.push_back(tc);
					tc=s[i]; c=0;
				}
			}
			ns.push_back(c+'0'); ns.push_back(tc);
			s = ns;
			n--;
		}
		return s;
	}

	TreeNode *sortedListToBSTHelper(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!head) return NULL;
		if(!head->next) return new TreeNode(head->val);

		ListNode * fast = head;
		ListNode * slow = head;
		ListNode * prev = NULL;
		while(fast && fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = NULL;

		TreeNode * node = new TreeNode(slow->val);
		node->left = sortedListToBSTHelper(head);
		node->right = sortedListToBSTHelper(slow->next);
		return node;
	}

	TreeNode *sortedListToBST(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		return sortedListToBSTHelper(head);
	}

	TreeNode *sortedArrayToBSTHelper(vector<int> &num, int s, int e) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(s<=e) {
			int m = (s+e)/2;
			TreeNode * node = new TreeNode(num[m]);
			node->left = sortedArrayToBSTHelper(num, s, m-1);
			node->right = sortedArrayToBSTHelper(num, m+1, e);
			return node;
		}
		return NULL;
	}

	TreeNode *sortedArrayToBST(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		return sortedArrayToBSTHelper(num, 0, num.size()-1);
	}

	ListNode *swapPairs(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ListNode sen(0);
		sen.next = head;
		ListNode * slow = &sen;
		ListNode * fast;
		while(slow->next && slow->next->next) {
			fast = slow->next->next;
			slow->next->next = fast->next;
			fast->next = slow->next;
			slow->next = fast;
			slow = slow->next->next;
		}
		return sen.next;
	}

	void rotate(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = matrix.size();

		int tmp, r1, r2, r3, r4, c1, c2, c3, c4;
		for(int l=0; l<=n/2; l++) {
			for(int i=0; i<n-1-2*l; i++) {
				r1 = l ; c1 =  l+i;
				r2 = (n-1-l-i) ; c2 =  l;
				r3 = (n-1-l) ; c3 =  n-1-l-i;
				r4 = (l+i) ; c4 =  n-1-l;
				tmp = matrix[r1][c1];
				matrix[r1][c1] = matrix[r2][c2];
				matrix[r2][c2] = matrix[r3][c3];
				matrix[r3][c3] = matrix[r4][c4];
				matrix[r4][c4] = tmp;
			}
		}

	}

	int firstMissingPositive(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		for (int i=0; i<n; i++) 
			while (A[i] > 0 && A[i] <= n && A[i] != A[A[i]-1])
				swap(A[i], A[A[i]-1]);

		for (int i=0; i<n; i++)
			if(A[i] != i+1)
				return i+1;

		return n+1;
	}

	ListNode *partition(ListNode *head, int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ListNode sen0(0); ListNode sen1(0);
		ListNode * tail = &sen1;
		ListNode * prv = &sen0;
		sen0.next = head;
		ListNode * cur = head;
		while(cur) {
			if(cur->val >= x) {
				prv->next = cur->next;
				tail->next = cur;
				tail = tail->next;
			} else {
				prv = cur;
			}
			cur = cur->next;
		}
		tail->next = cur;
		prv->next = sen1.next;
		return sen0.next;
	}

	int maxArea(vector<int> &height) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		// Hint : to make it narrow , everytime move start/end the lower one.
		// Since move higher one makes no sence, has no hope to seek new candidate.
		if(height.size()<2) return 0;

		int s = 0;
		int e = height.size()-1;
		int res = 0;
		while(s<e) {
			int tmp = min(height[s], height[e]) * (e-s);
			res = max(res, tmp);
			if(height[s] < height[e]) s++;
			else e--;
		}

		return res;
	}

	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > res;
		if(root) {
			queue<TreeNode*> q;
			q.push(root);
			int lvl = 0;

			TreeNode *stop, *cur;
			while(!q.empty()) {
				vector<int> v;
				stop = q.back();
				lvl++;
				do {
					cur = q.front(); q.pop();
					v.push_back(cur->val);
					if(cur->left) q.push(cur->left);
					if(cur->right) q.push(cur->right);
				} while(cur != stop);

				if(lvl%2==0) { // reverse v
					int i,j,t;
					for(i=0, j=v.size()-1; i<j; i++, j--) {
						t = v[i]; v[i] = v[j]; v[j] = t;
					}
				}

				res.push_back(v);
			}
		} 

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
				if(res[i].size()<k)
					res[i].push_back(n);
			}
		}
	}


	vector<vector<int> > combine(int n, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		vector<vector<int> > res;   
		if(n<1 || k<1 || k>n) return res;
		int i = 1;
		int m = n;
		// while(m--) { i <<= 1; } at last, m = -1
		// when m=0, judge false, but m-- still runs
		while(m) { i <<= 1; m--; }
		for(m=1;m<i;m++) {
			int l=0;
			vector<int> v;
			for(int j =0; j<n; j++) {
				if(m & 1<<j) {
					v.push_back(j+1);
					l++;
				}
			}
			if(l==k) res.push_back(v);
		}

		return res;
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

	vector<int> inorderTraversal2(TreeNode *root) { 
		stack<TreeNode*> sk; // store all nodes
		vector<int> res;
		TreeNode * cur = root;

		while(cur || !sk.empty()) {
			if(cur) {
				sk.push(cur);
				cur = cur->left;
			} else {
				cur = sk.top(); sk.pop();
				res.push_back(cur->val);
				cur = cur->right;
			}
		}

		return res;
	}

	vector<int> preorderTraversal2(TreeNode *root) { 
		stack<TreeNode*> sk; // store all nodes
		vector<int> res;
		TreeNode * cur = root;

		while(cur || !sk.empty()) {
			if(cur) {
				res.push_back(cur->val);
				sk.push(cur->right);
				cur = cur->left;
			} else {
				cur = sk.top(); sk.pop();
			}
		}

		return res;
	}

	vector<int> postorderTraversal2(TreeNode *root) { 
		stack<TreeNode*> sk; 
		stack<TreeNode*> skr; 
		vector<int> res;
		TreeNode * cur = root;

		while(cur || !sk.empty()) {
			if(cur) {
				sk.push(cur);
				skr.push(cur->right);
				cur = cur->left;
			} else {
				cur = sk.top();
				if(skr.empty()) {
					res.push_back(cur->val);
					sk.pop(); cur = NULL;
				} else {
					while(cur->right != skr.top()) {
						res.push_back(cur->val);
						sk.pop(); cur = sk.top();
					}
					cur = skr.top(); skr.pop();
				}
			}
		}

		return res;
	}

	string addBinary(string a, string b) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		string c;

		int j, carry = 0;
		int m = a.length();
		int n = b.length();
		int i=0;
		while(i<n || i<m || carry) {
			j = carry;
			if(i<n) j += (b[n-1-i] - '0');
			if(i<m) j += (a[m-1-i] - '0');
			carry = j/2;

			c.insert(c.begin(),  j%2 + '0');
			i++;
		}

		return c;
	}

	vector<int> plusOne(vector<int> &digits) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> res;

		int n = digits.size();
		int c = 1;
		for(int i=0; i<n; i++) {
			c += digits[n-1-i];
			res.insert(res.begin(), c%10);
			c /= 10;
		}
		if(c)
			res.insert(res.begin(), 1);

		return res;
	}

	void merge(int A[], int m, int B[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int ai = m;
		int bi = n;
		int ci = m+n;

		while(ai && bi) {
			if(A[ai-1]>B[bi-1]) {
				A[ci-1] = A[ai-1]; ai--;
			} else {
				A[ci-1] = B[bi-1]; bi--;
			}
			ci--;
		}
		while(!ai && bi) {
			A[ci-1] = B[bi-1]; bi--;
			ci--;
		}
	}

	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ListNode * head, * tail;
		head = new ListNode();
		tail = head;

		while(l1 && l2) {
			if(l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			} else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}

		tail->next = l1 ? l1 : l2;

		tail = head->next;
		delete head;
		return tail;
	}

	double pow(double x, int n) {
		// overflow for -2^31 if use abs only
		// use unassigned int to deal with this boundary condition
		// abs trick : n^(n>>31) - (n>>31)
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		bool neg = n < 0;
		if(neg) n = -n;

		double odd=1;
		while(n) {
			if(n%2) odd *= x;
			x *= x;
			n = n >> 1;
		}

		if(neg) odd = 1 / odd;

		return odd;
	}


	bool isBalanced(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int depOfRoot = 0;
		return isBalancedHelp(root, depOfRoot);
	}

	bool isBalancedHelp(TreeNode *p, int &dep) {
		if(!p) { dep = 0; return true; }

		int ldep, rdep;
		bool balanced = true;
		balanced &= isBalancedHelp(p->left, ldep);
		balanced &= isBalancedHelp(p->right, rdep);
		dep = max(ldep, rdep) ;
		balanced &= dep - ldep < 2;
		balanced &= dep - rdep < 2;
		dep++;
		return balanced;
	}
};

void MorrisTraversal(struct tNode *root)
{
	struct tNode *current,*pre;

	if(root == NULL)
		return; 

	current = root;
	while(current != NULL)
	{
		if(current->left == NULL)
		{
			printf(" %d ", current->data);
			current = current->right;
		}
		else
		{
			/* Find the inorder predecessor of current */
			pre = current->left;
			while(pre->right != NULL && pre->right != current)
				pre = pre->right;

			/* Make current as right child of its inorder predecessor */
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}

			// MAGIC OF RESTORING the Tree happens here: 
			/* Revert the changes made in if part to restore the original
			   tree i.e., fix the right child of predecssor */
			else
			{
				pre->right = NULL;
				printf(" %d ",current->data);
				current = current->right;
			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */
}

01 double findKth(int a[], int m, int b[], int n, int k)
02     {
03         if (m > n) return findKth(b, n, a, m, k);
04 
05         if (m == 0) 
06             return b[k-1];
07         
08         if (k == 1) 
09             return min(a[0], b[0]);
10     
11         int pa = min(k/2, m), pb = k - pa;
12         
13         if (a[pa-1] < b[pb-1]) 
14             return findKth(a+pa, m-pa, b, n, k - pa);
15         else 
16             return findKth(a, m, b+pb, n-pb, k-pb);
17     }
18     
19     double findMedianSortedArrays(int A[], int m, int B[], int n) {
20         int total = m+n;
21          
22         if (total&0x1)
23             return findKth(A, m, B, n, total/2+1);
24         else
25             return (findKth(A, m, B, n, total/2) + findKth(A, m, B, n, 
total/2+1))/2;
26     }

