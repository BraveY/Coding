/*https://leetcode.com/problems/number-of-islands/*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    	if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++){
        	for(int j=0; j<n; j++){
        		ans += grid[i][j] - '0'; //次数的统计不用if语句，直接相减就可以了
        		dfs(grid, i, j, m, n);
        	}
        }
        return ans;
    }

 private:
 	void dfs(vector<vector<char>>& grid, int x, int y, int m, int n){
 		if(x<0||x>m-1||y<0||y>n-1||grid[x][y]=='0') return;
 		grid[x][y]='0';	//置为0的好处，方便上面代码的直接减0来统计小岛的数目，虽然置为0，
 						// 会对小岛的坐标进行两次遍历，不过本来也就是O(mn),所以能接受.
 						//一定要访问之后进行标记，不然后续的也会访问回来，形成无限递归。
 		dfs(grid,x-1, y, m, n);
 		dfs(grid,x+1, y, m, n);
 		dfs(grid,x, y+1, m, n);
 		dfs(grid,x, y-1, m, n);
 	}
};