#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <utility>


using namespace std;
// 需要放到类得外面
bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.second > b.second; // 降序排列
}

/*
Runtime: 32 ms, faster than 85.24% of C++ online submissions for Top K Frequent Elements.
Memory Usage: 14.1 MB, less than 32.45% of C++ online submissions for Top K Frequent Elements.
 */
class Solution {
  public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> dict;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (!dict.count(nums[i])) {
				dict[nums[i]] = 1;
			} else dict[nums[i]]++;
		}
		vector<pair<int, int>> vec;
		for (unordered_map<int, int>::iterator it = dict.begin();
		        it != dict.end(); it++) {
			vec.push_back(pair<int, int>(it->first, it->second) );
		}
		sort(vec.begin(), vec.end(), cmp);
		vector<int> ans;
		for (int i = 0; i < k; i++) {
			ans.push_back(vec[i].first);
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