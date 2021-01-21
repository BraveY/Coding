#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <stack>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Implement Queue using Stacks.
Memory Usage: 7 MB, less than 90.02% of C++ online submissions for Implement Queue using Stacks.
*/
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;    
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int rtn = 0;
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        rtn = s2.top();
        s2.pop();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return rtn;
    }
    
    /** Get the front element. */
    int peek() {
        int rtn = 0;
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        rtn = s2.top();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return rtn;        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() ? true : false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


void debug() {

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