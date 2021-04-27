/*
 * @Author: your name
 * @Date: 2021-04-17 16:38:18
 * @LastEditTime: 2021-04-17 16:47:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\912sort-an-array.cc
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

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
class Solution {
  private:
    int partition(vector<int>&arr, int l, int r){
        int pivot = r;
        --r;
        while(l <= r) {
            if (arr[l] >= arr[pivot] && arr[r] <= arr[pivot]) {
                swap(arr[l], arr[r]);
            }
            if (arr[l] <= arr[pivot]) ++l;
            if (arr[r] >= arr[pivot]) --r;
        }
        swap(arr[l], arr[pivot]);
        return l;
    }
    
    void quickSort(vector<int>& arr, int l, int r) {              
        if (l >= r) return;        
        int pivot = partition(arr, l, r);
        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }
    
    void merge(vector<int>&arr, int l, int r){
        int m = l + (r - l) / 2;
        int l1 = l;
        int l2 = m + 1;
        int iter = 0; //临时数组从0开始不是l
        vector<int> tmp(r-l+1); // 使用一个临时数组来防止合并的数组
        while(l1 <= m && l2 <= r) {
            if (arr[l1] <= arr[l2]) {
                tmp[iter++] = arr[l1++];                
            }else{
                tmp[iter++] = arr[l2++];
            }
        }
        while(l1 <= m) tmp[iter++] = arr[l1++];
        while(l2 <= r) tmp[iter++] = arr[l2++];
        for(int i = 0; i < tmp.size(); ++i){
            arr[l+i] = tmp[i];
        }
    }
/*
Runtime: 144 ms, faster than 8.88% of C++ online submissions for Sort an Array.
Memory Usage: 72.1 MB, less than 12.30% of C++ online submissions for Sort an Array.
*/
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return ;
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr,l,r);
        return;
    }  
  public:
	vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        mergeSort(nums, 0, nums.size() - 1);
        vector<int> rtn(nums.begin(), nums.end());
        return rtn;
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
	//链表输入使用lclist.h
    //ListNode* head = stringToListNode("[1,3,2]");
	// prettyPrintLinkedList(head);
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}