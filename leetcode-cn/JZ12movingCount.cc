/*
 * @Author: your name
 * @Date: 2021-03-10 22:18:28
 * @LastEditTime: 2021-03-10 23:14:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode-cn\JZ12movingCount.cc
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
/*
执行用时：
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗：
6.9 MB
, 在所有 C++ 提交中击败了
34.67%
的用户
*/
class Solution {
  public:
    int counts = 0;
    int movingCount(int m, int n, int k) {
        vector<vector<int>> mesh(m, vector<int>(n, 0));
        
        if (m + n - 2 <= k ) { // 最大值都比k小，则矩阵均可访问
            return m*n;
        }
        int p, q;        
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ( digitSum(i, j) <= k) { // 注意审题不是简单相加
                    mesh[i][j] = 1;
                }
             
            }
        }

        DFS(mesh, 0, 0);
        return counts;

    }

  private:
    int digitSum(int p, int q) {
        int sum = 0;
        while(p / 10 != 0) {
            sum += p % 10;
            p = p / 10;
        }
        sum += p;
        while(q / 10 != 0) {
            sum += q % 10;
            q = q / 10;
        }
        sum += q;        
        return sum;   
    }
    void DFS(vector<vector<int>> &mesh, int i, int j) {
       if (mesh[i][j] <= 0 ) return; // 不能访问或者已经访问过
       counts++; //访问到mesh[i][j]     
       mesh[i][j] = -1; // 标志访问过
       if (i - 1 >= 0 ) {           
           DFS(mesh, i - 1, j);
       }
       if (i + 1 < mesh.size()) {
           DFS(mesh, i + 1, j);
       }
       if (j - 1 >= 0) {
           DFS(mesh, i , j - 1);
       }
       if (j + 1 < mesh[0].size()) {
           DFS(mesh, i , j + 1);
       }
   }
};


void debug() {
	Solution sol;
    cout << sol.movingCount(11, 8, 16) << endl;
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}