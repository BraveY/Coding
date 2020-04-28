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
	int solution() {}

 private:
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	// vector<int> nums2 = {2, 5, 6};
	sol.merge(nums1, nums2);
	for (auto i : nums1) {
		cout << i << ' ';
	}
	cout << endl;
	cout << sol.solution() << endl;
	system("pause");
	return 0;
}