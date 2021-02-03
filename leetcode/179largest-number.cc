#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
	static bool compare(int a, int b) {
		if (a == b) return false;
		string nums1 = to_string(a) + to_string(b);
		string nums2 = to_string(b) + to_string(a);
		int i = 0;
		// while (i < nums1.size()) {
		// 	if (nums1[i] != nums2[i]) {
		// 		return nums1[i] > nums2[i];
		// 		break;
		// 	}
		// 	i++;
		// }
		// return false;
		return nums1 > nums2; // 直接对两个字符串进行比较
	}
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), compare);//为compare(a,b)为true则a在b前面
		string rtn;
		for (int i = 0; i < nums.size(); i++) {
			rtn += to_string(nums[i]);
		}
		if (rtn[0] == '0') return to_string(0);
		return rtn;
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
	// cout << sol.compare(7, 32) << endl;
	//一维数组的输入
	// vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	vector<int> nums2;
	int i;
	while (cin >> i) {
		nums2.push_back(i);
	}
	cout << sol.largestNumber(nums2) << endl;
	cout_vector(nums2);

	//二维数组的输入
	// while (cin >> m >> n) {
	// 	vector<vector<char>> grid(m, vector<char>(n));
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