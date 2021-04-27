/*
 * @Author: your name
 * @Date: 2021-04-22 21:09:23
 * @LastEditTime: 2021-04-22 23:27:03
 * @LastEditors: Please set LastEditors
 * @Description: 不使用递归实现DFS查找无重复值的树，输出路径，可以不用path
 * @FilePath: \Coding\interview\TencentCSIG_firstInterview_DFSwithStack.cpp
 */
#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <stack>
#include "../binarytree.h"

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
class Solution {
  private:
  public:
	vector<int> solution(TreeNode* root, int value){
		if (!root) return {};        
		vector<int> rtn;
		stack<TreeNode*> s;
		unordered_set<TreeNode*> visited;
		s.push(root);		
		while(!s.empty()){
			TreeNode* cur = s.top();			
			if (cur->val == value) {				
				break;
			}			
			if (cur->left != nullptr && !visited.count(cur->left)) s.push(cur->left);
			else if (cur->right != nullptr && !visited.count(cur->right)) s.push(cur->right);
			else {
				visited.insert(s.top());
				s.pop();
			}			
		}
		while(!s.empty()) {
			rtn.push_back(s.top()->val);
			s.pop();
		}
		reverse(rtn.begin(), rtn.end());
		return rtn;
	}
};

void debug() {
	Solution sol;
	string line = "[1,2,3,4,5,6,7]";
	TreeNode* root = stringToTreeNode(line);
	vector<int> rtn = sol.solution(root, 7);
	cout_vector(rtn);
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}