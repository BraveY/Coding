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
	vector<int> searchRange(vector<int>& nums, int target) {
		int lo = 0;
		int hi = nums.size() - 1 ;
		int begin = -1, end = -1 ;
		vector<int> rtn;
		if (lo == hi && nums[lo] == target) {
			rtn.push_back(lo);
			rtn.push_back(hi);
			return rtn;
		}
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] > target) hi = mid ;
			else if (nums[mid] < target) lo = mid + 1;
			else {
				begin = mid;
				end = mid;
				break;
			}
		}
		if (lo == hi && nums[lo] == target) {
			rtn.push_back(lo);
			rtn.push_back(hi);
			return rtn;
		}
		if (begin != -1) {
			while (begin >= 0) {
				if (nums[begin] == target) begin--;
				else break;
			}
			while (end <= nums.size() - 1) {
				if (nums[end] == target) end++;
				else break;
			}
			begin++;
			end--;
		}
		rtn.push_back(begin);
		rtn.push_back(end);
		return rtn;
	}

  private:
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	vector<int> v = {5, 7, 7, 8, 8, 10};
	cout << sol.searchRange(v, 8)[0] << sol.searchRange(v, 8)[1] << endl;
	system("pause");
	return 0;
}