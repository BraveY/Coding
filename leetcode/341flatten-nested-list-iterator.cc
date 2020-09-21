#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

/*
Runtime: 28 ms, faster than 53.28% of C++ online submissions for Flatten Nested List Iterator.
Memory Usage: 14.9 MB, less than 20.17% of C++ online submissions for Flatten Nested List Iterator.
 */
class NestedIterator {
  public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		for (int i = nestedList.size() - 1; i >= 0; --i) {
			s.push(nestedList[i]);
		}
	}

	int next() {
		int ans = s.top().getInteger();
		s.pop();
		return ans;
	}

	bool hasNext() {
		while (!s.empty()) {
			NestedInteger temp = s.top();
			if (temp.isInteger()) return true;
			else {
				s.pop();
				vector<NestedInteger> tmpList = temp.getList();
				for (int i = tmpList.size() - 1; i >= 0; --i) {
					s.push(tmpList[i]);
				}
			}
		}
		return false;
	}

  private:
	stack<NestedInteger> s;
};


void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

void debug() {
	Solution sol;

	//一维数组的输入
	// vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	// cout << sol.solution(nums2) << endl;

	//二维数组的输入
	//int m, n;
	// while (cin >> m >> n) {
	// 	vector<vector<int>> grid(m, vector<int>(n));
	// 	for (int i = 0; i < m; i++) {
	// 		for (int j = 0; j < n; j++ ) {
	// 			cin >> grid[i][j];
	// 		}
	// 	}
	// 	int ans = sol.solution(grid);
	// 	cout << ans << endl;
	// }
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}