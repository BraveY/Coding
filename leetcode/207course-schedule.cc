#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/*
Runtime: 40 ms, faster than 45.34% of C++ online submissions for Course Schedule.
Memory Usage: 13.2 MB, less than 90.91% of C++ online submissions for Course Schedule.
 */
class Solution2 {
 public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		int n = prerequisites.size();
		graph_ = vector<vector<int>> (numCourses); //init
		for (int i = 0; i < n; i++) {
			graph_[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}
		// 0 :unk, 1 :visiting, 2 :visited
		vector<int> v(numCourses, 0);
		for (int i = 0; i < numCourses; i++) {
			if (dfs(i, v)) return false;
		}
		return true;
	}

 private:
	vector<vector<int>> graph_;
	bool dfs(int cur, vector<int>& v) {
		if (v[cur] == 1) return true; //cycle
		if (v[cur] == 2) return false; // no cycle
		v[cur] = 1;
		for (const int t : graph_[cur])//如果没有相邻的边直接跳过循环
			if (dfs(t, v)) return true;
		v[cur] = 2;
		return false;
	}
};


/*
BFS
Runtime: 40 ms, faster than 45.34% of C++ online submissions for Course Schedule.
Memory Usage: 13.2 MB, less than 90.91% of C++ online submissions for Course Schedule.
 */
class Solution {
 public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph_(numCourses);
		int n = prerequisites.size();
		vector<int> degree(numCourses, 0);
		for (int i = 0; i < n; i++) {
			graph_[prerequisites[i][0]].push_back(prerequisites[i][1]);
			degree[prerequisites[i][1]]++; // in degree
		}
		// for (auto &p : pre) {
		// 	graph_[p.second].push_back(p.first);
		// 	degree[p.first]++;
		// }
		queue<int> q;
		for (int i = 0; i < numCourses; i++)
			if (degree[i] == 0) q.push(i);
		while (!q.empty()) {
			int curr = q.front(); q.pop(); numCourses--;
			for (auto next : graph_[curr])
				if (--degree[next] == 0) q.push(next);
		}
		return numCourses == 0;
	}
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
	// cout << sol.solution() << endl;

	// 二维数组的输入
	int nums, m, n;
	while (cin >> nums >> m >> n) {
		vector<vector<int>> grid(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++ ) {
				cin >> grid[i][j];
			}
		}
		bool ans = sol.canFinish(nums, grid);
		cout << ans << endl;
	}
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}