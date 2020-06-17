#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
Runtime: 8 ms, faster than 52.23% of C++ online submissions for Generate Parentheses.
Memory Usage: 11.8 MB, less than 73.71% of C++ online submissions for Generate Parentheses.
 */
class Solution {
  public:
	vector<string> generateParenthesis(int n) {
		backtrack(n, 0);
		return ans;
	}

  private:
	vector<string> ans;
	string path;
	//front mean unused  （, end mean unused )
	void backtrack(int front, int end) {
		if (front == 0 && end == 0) {
			ans.push_back(path);
			return;
		}
		if (front > 0) {
			path += "(";
			front--;
			end++;
			backtrack(front, end);
			path.erase(path.length() - 1 );
			front++;
			end--;
		}
		if (end > 0) {
			path += ")";
			end--;
			backtrack(front, end);
			path.erase(path.length() - 1 );
			end++;
		}

	}
};

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

void debug() {
	Solution sol;
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}