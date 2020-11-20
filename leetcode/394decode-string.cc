#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
Memory Usage: 6.9 MB, less than 34.60% of C++ online submissions for Decode String.
*/
class Solution {
  public:
    string decodeString(string s) {
        return recursion(0, 0, s);
    }
    int right_brackets = -1;

  private:
    string recursion(int repeated_n, int start_ind, string s){
        string ans;
        for(int i = start_ind; i < s.size(); ++i){
            char c = s[i];
            if (isalpha(c)) ans += c;
            else if (isdigit(c)){ 
                string num;               
                while(isdigit(c)){
                    num += c;
                    c = s[++i];
                }// out while c = [
                ans += recursion(stoi(num), ++i, s); 
                if(right_brackets > 0){
                    i = right_brackets;
                    right_brackets = -1;
                }   
            }else{//meet ]
                right_brackets = i;
                string tmp_s = ans;
                // cout << "tmp_s " << tmp_s << endl;             
                --repeated_n;   // have add once .
                while(repeated_n){
                    ans += tmp_s;
                    --repeated_n;
                }                
                // cout << "ans " << ans << endl;
                return ans;
            }
        }
        // cout << " loop ans" << ans << endl;
        return ans;
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
    string s = "3[a]2[bc]";
    cout << sol.decodeString(s);
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}