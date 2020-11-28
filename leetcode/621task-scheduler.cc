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
Runtime: 100 ms, faster than 86.51% of C++ online submissions for Task Scheduler.
Memory Usage: 34.7 MB, less than 92.77% of C++ online submissions for Task Scheduler.
最大频率有多个的情况
ans = max(task_size, (k-1)*(n+1) + p )
k is the max count, p tasks has the max count.
*/
class Solution {
  public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (const char task : tasks)
            ++count[task - 'A'];
        int max_count = *max_element(count.begin(), count.end());
        size_t ans = (max_count - 1) * (n + 1);
        ans += count_if(count.begin(), count.end(),
                        [max_count](int c){return c == max_count;});
        return max(tasks.size(), ans);                        
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
	// vector<vector<int>> grid{{1,3,1},{1,5,1},{4,2,1}};
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}