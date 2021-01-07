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

/*
Runtime: 852 ms, faster than 5.22% of C++ online submissions for Find All Anagrams in a String.
Memory Usage: 31.1 MB, less than 5.26% of C++ online submissions for Find All Anagrams in a String.
*/

class Solution1 {
  public:    
    vector<int> findAnagrams(string s, string p) {
        int m = s.size();
        int n = p.size();
        if(!m || !n || m < n) return {};
        for(int i = 0; i < n; ++i){
            dict[p[i] - 'a']++;
        }
        vector<int> ans;
        for(int i = 0; i <= m - n; ++i){
            if(isAnagrams(s, i, i + n - 1))
                ans.push_back(i);
        }
        return ans;
    }

  private:    
    vector<int> dict = vector<int>(26, 0);
    bool isAnagrams(string&s, int iStart, int iEnd){
        vector<int> dictLocal(26, 0);
        for(int i = iStart; i <= iEnd; ++i){
            dictLocal[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; ++i){
            if(dict[i] != dictLocal[i])
                return false;
        }
        return true;
    }
};

/*
Runtime: 20 ms, faster than 56.38% of C++ online submissions for Find All Anagrams in a String.
Memory Usage: 9 MB, less than 38.52% of C++ online submissions for Find All Anagrams in a String.
滑动窗口的字典是动态更新的，只需要加入新进入窗口的，减少不是窗口的状态就可以了。暴力的每次都需要重新建立。
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<int> ans;
        vector<int> vs(26, 0);
        vector<int> vp(26, 0);
        for(int i = 0; i < n; ++i) {
            ++vp[p[i] - 'a'];
        }
        for(int i = 0; i < m; ++i) {
            if ( i >= n) {
                --vs[s[i - n] - 'a'];
            }
            ++vs[s[i] - 'a'];
            if( vs == vp) ans.push_back( i - n + 1);
        }
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
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}