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
Runtime: 256 ms, faster than 64.85% of C++ online submissions for Queue Reconstruction by Height.
Memory Usage: 13 MB, less than 5.20% of C++ online submissions for Queue Reconstruction by Height.
*/
bool cmp(vector<int>& p1, vector<int>& p2){
    return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]); // true 的顺序与最终排列结果一致
}
class Solution {
  public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //sort(people.begin(), people.end(),cmp); 传统方式
        sort(people.begin(), people.end(),[](vector<int>& p1, vector<int>& p2){ // lambda 表达式 https://www.cnblogs.com/DswCnblog/p/5629165.html
            return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
        });
        vector<vector<int>> rtn;
        for(auto person : people){
            rtn.insert(rtn.begin() + person[1], person); // 在index 前插入 person元素。
        }
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