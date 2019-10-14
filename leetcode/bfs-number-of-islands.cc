/*https://leetcode.com/problems/number-of-islands/*/
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<int>>& grid) {
    	if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0; i<m; i++){
        	for(int j=0; j<n; j++){
        		if(grid[i][j]==1){
                    ans++; 
        		    bfs(grid, i, j, m, n);
                }
        	}
        }
        return ans;
    }

 private:
 	void bfs(vector<vector<int>>& grid, int x, int y, int m, int n){
        if(x<0||x>m-1||y<0||y>n-1||grid[x][y]==0) return;
        queue<pair<int,int>> island_q;
        push_q(grid, x, y, m, n, island_q);
        while(!island_q.empty()){
            pair<int,int> p = island_q.front();
            island_q.pop();
            int x_new = p.first;
            int y_new = p.second;
            push_q(grid, x_new, y_new, m, n, island_q);
        }
 	}

    void push_q(vector<vector<int>>& grid, int x, int y, int m, int n,queue<pair<int,int>>& island_q){
        // if(x<1||x>m-2||y<1||y>n-2||grid[x][y]=='0') return;
        if(x>=1&&grid[x-1][y]==1){
            grid[x-1][y]=2;
            island_q.push(make_pair(x-1,y));
        }
        if(x<=m-2&&grid[x+1][y]==1){
            grid[x+1][y]=2;
            island_q.push(make_pair(x+1,y));
        }
        if(y>=1&&grid[x][y-1]==1){
            grid[x][y-1]=2;
            island_q.push(make_pair(x,y-1));
        }
        if(y<=n-2&&grid[x][y+1]==1){
            grid[x][y+1]=2;
            island_q.push(make_pair(x,y+1));
        }
    }
};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int m,n;
    Solution Sol;
    int ans;
    while(cin>>m>>n){
        vector<vector<int>> grid(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j =0; j<n; j++ ){
                cin>>grid[i][j];
            }
        }
        ans = Sol.numIslands(grid);
        cout<<ans<<endl;
    }
    return 0;
}