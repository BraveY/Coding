#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate Image.
Memory Usage: 7.5 MB, less than 5.14% of C++ online submissions for Rotate Image.
 */
class Solution {
  public:
	void rotate(vector<vector<int>>& matrix) {
		const int n = matrix.size();
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				swap(matrix[i][j], matrix[j][i]); //First pass: mirror around diagonal
		for (int i = 0; i < n; ++i)
			reverse(begin(matrix[i]), end(matrix[i])); //Second pass: mirror around y axis
	}
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate Image.
Memory Usage: 7.2 MB, less than 56.48% of C++ online submissions for Rotate Image.
 */
class Solution1 {
  public:
	void rotate(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (!m) return;
		int n = matrix[0].size();
		if (!n || m != n) return;
		int count = m;
		queue<int> seq;
		int i = 0;
		while (count > 0) { //(i,i) is the corner start
			int j = i;
			// cout << "count: " << count <<  endl;
			// cout << "i: " << i <<  endl;
			for (int k = i; k < i + count - 1; ++k) {
				seq.push(matrix[j][k]);
			}
			// cout << "1" << endl;
			j = i + count - 1;
			for (int k = i; k < i + count - 1; ++k) {
				seq.push(matrix[k][j]);
			}
			// cout << "2" << endl;
			for (int k = i + count - 1; k > i; --k) {
				seq.push(matrix[j][k]);
			}
			// cout << "3" << endl;
			j = i;
			for (int k = i + count - 1; k > i ; --k) {
				seq.push(matrix[k][j]);
			}
			// cout << "4" << endl;
			j = i + count - 1;
			for (int k = i; k < i + count - 1; ++k) {
				matrix[k][j] = seq.front();
				seq.pop();
			}
			// cout << "-1" << endl;
			for (int k = i + count - 1; k > i; --k) {
				matrix[j][k] = seq.front();
				seq.pop();
			}
			// cout << "-2" << endl;
			j = i;
			for (int k = i + count - 1; k > i ; --k) {
				matrix[k][j] = seq.front();
				seq.pop();
			}
			// cout << "-3" << endl;
			for (int k = i; k < i + count - 1; ++k) {
				matrix[j][k] = seq.front();
				seq.pop();
			}
			// cout << "-4" << endl;
			count -= 2;
			++i;
		}
	}

  private:
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

	vector<vector<int>> mat = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
	sol.rotate(mat);
	//二维数组的输入
	//int m, n;
	// while (cin >> m >> n) {
	// 	vector<vector<int>> grid(m, vector<int>(n));
	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat.size(); j++ ) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
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