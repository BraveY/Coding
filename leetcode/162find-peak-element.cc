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
	int findPeakElement(vector<int>& nums) {
		int lo = 0;
		int hi = nums.size() - 1 ;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] > nums[mid + 1]) hi = mid ;
			else lo = mid + 1;
		}
		return lo;
	}

  private:
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
	cout << sol.findPeakElement(nums) << endl;
	system("pause");
	return 0;
}