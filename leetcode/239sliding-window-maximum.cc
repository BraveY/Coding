/*
 * @Author: your name
 * @Date: 2021-03-09 16:42:06
 * @LastEditTime: 2021-03-10 14:24:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\239sliding-window-maximum.cc
 */
#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <set>
#include <queue>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
/*
O(NK)
Time Limit Exceeded
*/
class Solution1 {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        int l = 0;
        int r = l + k - 1;
        while(r < nums.size()){
            ret.push_back(*max_element(nums.begin() + l, nums.begin() + r + 1)); // [first, last)
            l++;
            r++;
        }
        return ret;
    }

  private:
};

/*
最坏情况仍然是O(NK)
Time Limit Exceeded 
*/
class Solution2 {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        int l = 0;
        int r = l + k - 1;
        int maxLast = *max_element(nums.begin() + l, nums.begin() + r + 1);
        ret.push_back(maxLast);
        l++;
        r++;
        while(r < nums.size()){
            if ( nums[r] >= maxLast ){
                maxLast = nums[r];
                ret.push_back(maxLast);
            } else {
                if ( nums[l - 1] < maxLast) {
                    ret.push_back(maxLast);
                }else {
                    maxLast = *max_element(nums.begin() + l, nums.begin() + r + 1);
                    ret.push_back(maxLast);
                }
            }
            l++;
            r++;
        }
        return ret;
    }

  private:
};

/*
set的
Time complexity: O((n – k + 1) * logk)
Space complexity: O(k)
Runtime: 572 ms, faster than 19.86% of C++ online submissions for Sliding Window Maximum.
Memory Usage: 185.7 MB, less than 6.48% of C++ online submissions for Sliding Window Maximum.
*/
class Solution3 {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (nums.empty()) return {};
        multiset<int> window(nums.begin(), nums.begin() + k - 1);  //容器范围初始[first, last) 总共有k-1个元素初始进去
        for (int i = k - 1; i < nums.size(); ++i) {
            window.insert(nums[i]);
            ret.push_back(*window.rbegin()); // multiset是有序的，所以逆序的begin 就是最大值
            if ( i - k + 1 >= 0){ // i 是右边的索引 减去窗口长度加上1是左边的索引
                window.erase(window.equal_range(nums[i - k + 1]).first); //erase() 删除所有值相同的元素，但只能删除一个
            }
        }
        return ret;
    }

  private:
};


class MonotonicQueue {
  public:
    void push(int val) {
        while(!data.empty() && val > data.back()) { // 只要比队尾的元素大就删除，相等也会进入队列
          data.pop_back();
        }
        data.push_back(val); 
    }
    void pop() {
      data.pop_front();
    }
    int getMax() const { // const 修饰表示只对成员变量进行只读访问
        return data.front(); // 队头是最大的
    }
  private:
    deque<int> data;
};

/*
Runtime: 248 ms, faster than 70.97% of C++ online submissions for Sliding Window Maximum.
Memory Usage: 131.6 MB, less than 23.21% of C++ online submissions for Sliding Window Maximum.
O(N)
*/
class Solution4 {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        MonotonicQueue q;
        for (int i = 0; i < nums.size(); ++i) { // i是右侧的值
          q.push(nums[i]);
          if (i - k + 1 >= 0) { //左侧大于等于0 表示窗口形成
            ret.push_back(q.getMax());
            if (nums[i - k + 1] == q.getMax()) { //滑动窗口要移除的值等于队列最大值时队列才会pop
              q.pop();
            }
          }
        }
        return ret;
    }

  private:
};

/*
Runtime: 236 ms, faster than 73.71% of C++ online submissions for Sliding Window Maximum.
Memory Usage: 131.9 MB, less than 21.58% of C++ online submissions for Sliding Window Maximum.
*/
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) { // i是右侧的值          
          while (!q.empty() && nums[i] > q.back()) {
            q.pop_back();
          }
          q.push_back(nums[i]);
          if (i - k + 1 >= 0) { //左侧大于等于0 表示窗口形成
            ret.push_back(q.front());
            if (nums[i - k + 1] == q.front()) { //滑动窗口要移除的值等于队列最大值时队列才会pop
              q.pop_front();
            }
          }
        }
        return ret;
    }

  private:
};

void debug() {
	Solution sol;

	//一维数组的输入
	vector<int> nums1 = {1,3,-1,-3,5,3,6,7};
    sol.maxSlidingWindow(nums1, 3);
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