#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <../binarytree.h>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        LP(root);
        return ans;
    }
private:
    int LP(TreeNode* root){//LP函数返回该节点左右子树中的最大深度+1（因为root节点到左右子节点还需要一个路径1）
        if(!root) return -1;// root为空则返回-1，说明上一个节点是一个叶子节点，-1+1=0说明叶子节点的左右子树的最大深度是0
        int l = LP(root->left)+1; //递归调用求左子树的最大深度
        int r = LP(root->right)+1;//递归调用求右子树的最大深度
        ans = max(ans, l+r); //因为对于一个根节点其最大深度为左右子树的最大深度相加，所以对ans进行更新
        return max(l,r); //返回此几点的最大子树深度
    }
};

class Solution1 {
  private:
  public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        DFS(root, ans);
        return ans-1;
    }    
    int DFS(TreeNode* root, int &ans) {
        if (!root) return 0;
        int lDia = DFS(root->left, ans);
        int rDia = DFS(root->right, ans);
        int maxDia = max(lDia, rDia) + 1;
        ans = max(ans, lDia + rDia + 1);
        return maxDia;
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