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
Runtime: 20 ms, faster than 43.63% of C++ online submissions for Minimum Path Sum.
Memory Usage: 10.5 MB, less than 26.47% of C++ online submissions for Minimum Path Sum.
*/
class Solution
{
public:
	int minPathSum(vector<vector<int>> &grid)
	{
		int m = grid.size();
		if (!m)
			return -1;
		int n = grid[0].size();
		vector<vector<int>> path(m, vector<int>(n, 0));
		path[0][0] = grid[0][0];
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i >= 1 && j >= 1)
					path[i][j] = min(path[i - 1][j], path[i][j - 1]) + grid[i][j];
				else if (i >= 1 && j < 1)
					path[i][j] = path[i - 1][j]  + grid[i][j];
				else if (i < 1 && j >= 1)
					path[i][j] = path[i][j - 1]  + grid[i][j];				
			}
		}
		return path[m - 1][n - 1];
	}

private:
};

void cout_vector(vector<int> &nums)
{
	for (auto i : nums)
	{
		cout << i << ' ';
	}
	cout << endl;
}

void debug()
{
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
	vector<vector<int>> grid{{1,3,1},{1,5,1},{4,2,1}};
	cout << sol.minPathSum(grid);
	return;
}

int main(int argc, char const *argv[])
{
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}