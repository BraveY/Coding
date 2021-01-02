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
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
Memory Usage: 6.8 MB, less than 90.86% of C++ online submissions for Spiral Matrix.
 */
class Solution1 {
  public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (!m) return {};
		int n = matrix[0].size();
		if (!n) return {};
		vector<int> ans;
		int top = 0, down = m - 1;
		int left = 0, right = n - 1;
		while (top <= down || left <= right) {
			if (ans.size() == m * n) break;
			for (int i = left; i < right; ++i) {
				ans.push_back(matrix[top][i]);
			}
			if (top == down) { // one row
				ans.push_back(matrix[top][right]);
				break;
			} else {
				for (int i = top; i < down; ++i) {
					ans.push_back(matrix[i][right]);
				}
				if (right == left) { // one col
					ans.push_back(matrix[down][right]);
					break;
				} else {
					for (int i = right; i > left; --i) {
						ans.push_back(matrix[down][i]);
					}

					for (int i = down; i > top; --i) {
						ans.push_back(matrix[i][left]);
					}
				}
			}
			++top;
			--right;
			--down;
			++left;
		}
		return ans;
	}

  private:
};

//方向的更新带来步数的更新，完成一次对应方向的对应步数后，对应的步数减少1。
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
Memory Usage: 7.5 MB, less than 5.11% of C++ online submissions for Spiral Matrix.
*/
class Solution {
  public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		int m = matrix.size(); 
		if(!m) return ans;
		int n = matrix[0].size();
		if(!n) return ans;
		vector<vector<int>> Dir {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; //四个方向的坐标加减 以4为循环
		vector<int> nSteps {n, m - 1}; //每个方向对应走的步数 以2为循环 最开始需要走的步数是col列数和行数减一不要弄反了
		int idir = 0; //开始方向 右
		int ir = 0, ic = -1; //矩阵遍历的坐标
		while(nSteps[idir % 2]){ //方向为偶数坐标对应着横坐标需要修改，奇数对应着列坐标
			for(int i = 0; i < nSteps[idir % 2]; ++i) {
				ir += Dir[idir][0];
				ic += Dir[idir][1];
				ans.push_back(matrix[ir][ic]);
			}
			nSteps[idir % 2]--;
			idir = (idir + 1) % 4;
		}
		return ans;

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