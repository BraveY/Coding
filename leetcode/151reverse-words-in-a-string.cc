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
/*
Runtime: 8 ms, faster than 46.87% of C++ online submissions for Reverse Words in a String.
Memory Usage: 7.9 MB, less than 45.99% of C++ online submissions for Reverse Words in a String.
*/
class Solution {
  public:
    string reverseWords(string s) {
        vector<string> words;
        int flag = 0;
        string rtn;
        string str;
        for(int i = 0; i < s.size(); ++i){
            if(!flag && s[i]==' ') continue;
            else if (!flag && s[i]!=' '){
                flag = 1;
                str += s[i];
            }
            else if (flag && s[i] != ' ') str += s[i];
            else {
                flag = 0;
                words.push_back(str);
                str = "";
            }
        }
        if (str.size()) words.push_back(str);
        for(int i = words.size() - 1; i >= 0; --i){
            rtn += words[i];
            if (i) rtn += " ";
        }
        return rtn;
    }

  private:
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