#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <string>
#include <stdio.h>
#include <cmath>

using namespace std;

class Solution {
public:	
	int max_eaten_banana(vector<char>& pos, vector<int>& M, int k){
		int ans = 0;
		int plen = pos.size();
		if(k==0||plen==0) return 0;		
		for(int i=0; i<M.size(); i++){
			int mpos = M[i];
			int find = 0;
			for(int j=k; j>0; j--){
				if((mpos-j>=0)&&pos[mpos-j]=='B') {
					pos[mpos-j] = '0';
					ans++;
					find = 1;
					break;
				}								
			}
			if(0==find){
				for(int j=1; j<=k; j++){			
					if((mpos+j<plen)&&pos[mpos+j]=='B') {
						pos[mpos+j]='0';
						ans++;
						break;
					}
				}	
			}		
		}
		return ans;
	}
private:

};

int main(int argc, char const *argv[])
{
	/* code */
	ios::sync_with_stdio(false);
	char ch;
	vector<char> pos;
	std::vector<int> M;
	int i=0;
	int k=0;	
	string str;
	cin>>str;
	cin>>k;
	for(int i=0; i<str.size(); i++){
		ch = str[i];
		if(ch=='M' || ch=='B') {
			pos.push_back(ch);
			if(ch=='M') M.push_back(i);
		}		
	}
	Solution sol;
	cout<<sol.max_eaten_banana(pos, M, k)<<endl;
	system("pause");	
	return 0;
}