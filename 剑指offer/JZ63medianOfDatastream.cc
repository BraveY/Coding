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

占用内存：488k
*/
class Solution {
public:
    priority_queue<int> pq;
    int size = 0;
    void Insert(int num)
    {
        pq.push(num);
        ++size;
    }

    double GetMedian()
    { 
        double ans;
        int mid = size / 2;
        vector<int> tmpVec;
        for(int i = 0; i <= mid; ++i) {
            tmpVec.push_back(pq.top());
            pq.pop();
        }
        if (size & 1) {           
            ans = double(tmpVec[mid]);            
        }else {
            ans = double(tmpVec[mid] + tmpVec[mid - 1]) / 2;   // 偶数的数组取得mid 是右边得值，另一个应该是mid-1 
        }
        for(int i = 0; i <= mid; ++i){
            pq.push(tmpVec[i]);
        }        
        return ans;
    }

};


void debug() {
	Solution sol;

    sol.Insert(5);
    cout << sol.GetMedian() << endl;
    sol.Insert(2);
    cout << sol.GetMedian() << endl;

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