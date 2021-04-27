/*
 * @Author: your name
 * @Date: 2021-04-22 13:11:43
 * @LastEditTime: 2021-04-22 13:11:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\exps\LongesCommonSubstring.cc
 */
#include<iostream>
#include<algorithm> 

using namespace std;
const int N = 1010;

int dp[N][N];	
//dp[i][j] 为字符串A的前i个字符 与字符串B的前j个字符做匹配得到的公共子序列，属性为最大长度

int main()
{
	string a,b;
	cin>>a>>b;
	a = " "+a,b = " "+b;
	int n = a.size(),m = b.size();
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(a[i]==b[j]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
		}
	}
	string ans = "";
	for(int i=n-1,j=m-1;i&&j;){			//倒叙寻找上一个状态
		if(a[i]==b[j]) ans+=a[i],i--,j--;
		else if(dp[i-1][j]>dp[i][j-1]) i--;
		else j--;
	}
	reverse(ans.begin(),ans.end());		//反转输出
	cout<<ans<<endl;
	//cout<<dp[n-1][m-1]<<endl;  //长度 
	return 0;
}