#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
/*
运行时间：3ms

占用内存：380k
最小堆
*/
class Solution1 {
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int, vector<int>, greater<int>> pq {input.begin(), input.end()};
        vector<int> ans;
        if (!k || k > input.size()) return {};
        for(int i = 0; i < k; ++i) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }

  private:
};

/*
api 排序
*/
class Solution2 {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(), input.end());
        if (!k || k > input.size()) return {};
        vector<int> rtn {input.begin(), input.begin() + k};
        return rtn;
    }
};

/*
运行时间：3ms

占用内存：504k
*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        quickSort(input, 0, input.size() - 1);
        if (!k || k > input.size()) return {};
        vector<int> rtn {input.begin(), input.begin() + k};
        return rtn;        
    }
private:
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r)  return ;
        int pivotIndex = getPivotIndex(nums, l, r);
        quickSort(nums, l, pivotIndex - 1); // 如果把pivot包含进去，左边依然会使用pivot来进行交换，造成无限递归，所以一定不能包含pivot
        quickSort(nums, pivotIndex + 1, r);
    }
    int getPivotIndex(vector<int>& nums, int l, int r) {
        int pivot = r;
        r--;
        while(l <= r) {
            if (nums[l] >= nums[pivot] && nums[r] <= nums[pivot]) swap(nums[l], nums[r]);
            if (nums[l] <= nums[pivot]) ++l;
            if (nums[r] >= nums[pivot]) --r;
        }
        swap(nums[l], nums[pivot]);
        return l;
    }
};

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
	//二叉树输入
	//TreeNode* root = stringToTreeNode("[3,9,20,null,null,15,7]")
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}