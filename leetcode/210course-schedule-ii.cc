#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

/*
DFS without queue ,
Runtime: 36 ms, faster than 60.84% of C++ online submissions for Course Schedule II.
Memory Usage: 14.1 MB, less than 82.76% of C++ online submissions for Course Schedule II.
 */
class Solution {
 public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		int n = prerequisites.size();
		graph_ = vector<vector<int>> (numCourses);
		vector<int> state(numCourses);

		for (int i = 0; i < n; i++) {
			graph_[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}
		for (int i = 0; i < numCourses; i++) {
			if (!DFS(i, state)) {
				ans.clear();
				return ans; // 不能finish
			}
		}
		return ans;
	}

 private:
	vector<vector<int>> graph_;
	vector<int> ans;
	bool DFS(int node, vector<int>& state) {
		if (state[node] == 2) return true; // canFinish
		if (state[node] == 1) return false; // can not canFinish
		state[node] = 1;
		bool rtn = true;
		for (const int i : graph_[node]) {
			// cout << node << " " << i << endl;
			rtn &= DFS(i, state); //使用并逻辑会比用if语句快4ms
		}
		state[node] = 2;
		ans.push_back(node); //可以直接插入
		return rtn;
	}
};

/*
DFS 访问顺讯就是先被标记为visited的在前面 使用queue
Runtime: 36 ms, faster than 60.84% of C++ online submissions for Course Schedule II.
Memory Usage: 14 MB, less than 86.21% of C++ online submissions for Course Schedule II.
 */
class Solution1 {
 public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		int n = prerequisites.size();
		graph_ = vector<vector<int>> (numCourses);
		vector<int> state(numCourses);

		for (int i = 0; i < n; i++) {
			graph_[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}
		vector<int> ans;
		for (int i = 0; i < numCourses; i++) {
			if (!DFS(i, state)) return ans; // 不能finish
		}
		while (!q.empty()) {
			ans.push_back(q.front());
			q.pop();
		}
		return ans;
	}

 private:
	vector<vector<int>> graph_;
	queue<int> q;
	bool DFS(int node, vector<int>& state) {
		if (state[node] == 2) return true; // canFinish
		if (state[node] == 1) return false; // can not canFinish
		state[node] = 1;
		bool ans = true;
		for (const int i : graph_[node]) {
			// cout << node << " " << i << endl;
			ans &= DFS(i, state); //使用并逻辑会比用if语句快4ms
		}
		state[node] = 2;
		q.push(node); //可以直接插入
		return ans;
	}
};

/*
BFS
入度为0的最后上，最下层的课最先上。
Runtime: 44 ms, faster than 37.53% of C++ online submissions for Course Schedule II.
Memory Usage: 13.6 MB, less than 86.21% of C++ online submissions for Course Schedule II.
 */

class Solution2 {
 public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		int n = prerequisites.size();
		graph_ = vector<vector<int>> (numCourses);
		vector<int> indegree(numCourses);
		vector<int> ans;
		queue<int> q;
		for (int i = 0; i < n; i++) {
			graph_[prerequisites[i][0]].push_back(prerequisites[i][1]);
			indegree[prerequisites[i][1]]++;
		}
		for (int i = 0; i < numCourses; i++) {
			if (!indegree[i]) q.push(i);
		}
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			ans.insert(ans.begin(), cur);// 插入的是当前入度为0的，表示当前最晚上的课，是一个逆序，所以插入在最前
			numCourses--;
			for (const int i : graph_[cur]) {
				if (--indegree[i] == 0) q.push(i);
			}
		}
		if (!numCourses) return ans;
		ans.clear();
		return ans;
	}

 private:
	vector<vector<int>> graph_;
};

//使用优先队列来输出有顺序要求的结果
class Solution3 {
 public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		int n = prerequisites.size();
		graph_ = vector<vector<int>> (numCourses);
		vector<int> indegree(numCourses);
		vector<int> ans;
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 0; i < n; i++) {
			graph_[prerequisites[i][1]].push_back(prerequisites[i][0]); // 将图反向了，现在开始入度为0表示没有依赖的课程了
			indegree[prerequisites[i][0]]++;
		}
		for (int i = 0; i < numCourses; i++) {
			if (!indegree[i]) q.push(i);
		}
		while (!q.empty()) {
			int cur = q.top();
			q.pop();
			// ans.insert(ans.begin(), cur);// 插入的是当前入度为0的，表示当前最晚上的课，是一个逆序，所以插入在最前
            ans.push_back(cur);
			numCourses--;
			for (const int i : graph_[cur]) {
				if (--indegree[i] == 0) q.push(i);
			}
		}
		if (!numCourses) return ans;
		ans.clear();
		return ans;
	}

 private:
	vector<vector<int>> graph_;
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
		vector<int> ans = sol.findOrder(nums, grid);
		cout_vector(ans);
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