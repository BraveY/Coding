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
Runtime: 4 ms, faster than 67.57% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 6.5 M
 */
class Solution1 {
 public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		if (n == 0) return -1;
		int rtn = -1;
		if (n == 1) {
			rtn = nums[0] == target ? 0 : -1;
			return rtn;
		}
		int lo = 0;
		int hi = n - 1;
		int pivot = findPivot(nums, lo, hi);
		if ( nums[pivot] > nums[pivot - 1]) {
			// 不是旋转数组
			return findTarget(nums, lo, pivot, target);
		}
		if (target == nums[lo]) return lo;
		else if (target > nums[lo])
			rtn = findTarget(nums, lo, pivot - 1, target);
		else
			rtn = findTarget(nums, pivot, hi, target);
		return rtn;
	}

 private:
	int findPivot(vector<int>& nums, int lo, int hi) {
		// 如果不是旋转数组最后返回的是最右端的index
		int rtn = -1;
		while (lo < hi) {
			if ((hi - lo) == 1) {
				rtn = hi;
				break;
			}
			int mid = lo + (hi - lo) / 2 ;
			if (nums[mid] > nums[lo]) lo = mid;
			else hi = mid;
		}
		return rtn;
	}
	int findTarget(vector<int>& nums, int lo, int hi, int target) {
		int rtn = -1;
		while (lo <= hi) {
			// 采用等号的时候可以对最后只有一个值的时候的进行判断
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] > target) hi = mid - 1;
			else if (nums[mid] < target) lo = mid + 1;
			else {
				rtn = mid;
				break;
			}
		}
		return rtn;
	}
};

/*
nums[mid]和0比较，判断在第几个阶段
在两个阶段中又确定一段有序得，依然可以进行二分
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;        
        int n = nums.size();
        int r = n - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {// 在第一阶段
                if (nums[0] <= target && target < nums[mid]) { // 不能缺少第一个的等号，否则丢失找的就是第一个情况
                    r = mid - 1;
                }else {
                    l = mid + 1;
                }
            }else { // 在第二阶段
                if (nums[mid] < target && target <= nums[n - 1]) {//不能缺少第二个等号，否则丢失找的最后一个情况
                    l = mid + 1;
                }else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	std::vector<int> v = {5, 1};
	cout << sol.search(v, 5) << endl;
	system("pause");
	return 0;
}