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
Runtime: 4 ms, faster than 49.84% of C++ online submissions for Sort Colors.
Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Sort
 */
class Solution {
 public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		vector<int>  ans(3);
		for (int i = 0; i < n; i++) {
			ans[nums[i]]++;
		}
		// 虽然两个for循环，但是每个元素只遍历了一遍，因此是O(n)
		int count = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < ans[i]; j++) {
				nums[count] = i;
				count++;
			}
		}
	}

 private:
};

class Solution2 {
 public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		int pmin = 0;
		int pmax = n - 1;
		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) { // 加了 i>pmin 的情况 0 ，1 ，0无法通过，遇到0就++
				swap(nums[i], nums[pmin]);
				pmin++;
			} else if (nums[i] == 2 && i < pmax) {
				swap(nums[i], nums[pmax]);
				pmax--;
				i--;//对换过的在原点开始走，跳过的的话{1,2,0}这种会将0给跳过
			}
		}
	}

};


int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution2 sol;
	vector<int> nums = {1, 2, 0};
	sol.sortColors(nums);
	for (auto i : nums) {
		cout << i << " ";
	}
	cout << endl;
	// cout << sol.sortColors(nums) << endl;
	system("pause");
	return 0;
}