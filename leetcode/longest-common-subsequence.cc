/*
https://leetcode.com/problems/longest-common-subsequence/
*/
#include<iostream>
#include<vector>
// #include<queue>
#include<utility>
#include<algorithm>
#include <string>

using namespace std;


class Solution {
public:
	/*不进行优化纯粹递归 TLE*/
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.length();
        int len2=text2.length();
        if(len1<1||len2<1) return 0;
        char c1=text1.at(len1-1);
        char c2=text2.at(len2-1);
        string substr1=text1.substr(0, len1-1);
        string substr2=text2.substr(0, len2-1);
        int lcs1 = longestCommonSubsequence(substr1, text2);
        int lcs2 = longestCommonSubsequence(text1, substr2);
        int lcs3 = 0;
        if(c1==c2) lcs3 = longestCommonSubsequence(substr1, substr2)+1;
        else lcs3 = longestCommonSubsequence(substr1, substr2);
        return max(max(lcs1,lcs2), lcs3);
    }
    /*使用完整的opt二维数组len1*len2存储opt表 
    Runtime: 20 ms
	Memory Usage: 14.9 MB */
    int longestCommonSubsequence2(string text1, string text2) {
    	int len1=text1.length();
        int len2=text2.length();
        if(len1<1||len2<1) return 0;
        vector<vector<int> > opt(len1+1, vector<int>(len2+1, 0)); //二维数组大小都要要加1
        int lcs = 0;
        for(int i=1; i<=len1; i++){
        	for(int j=1; j<=len2; j++){
        		// 截取前i个字符
        		// string substr1 = text1.substr(0, i); //不需要复制
        		// string substr2 = text2.substr(0, j);
        		//子字符串中的最后一位
        		char c1=text1.at(i-1);
        		char c2=text2.at(j-1);
        		//最后一个匹配则加1
        		if(c1==c2) lcs=opt[i-1][j-1]+1;
        		else lcs=opt[i-1][j-1];
        		opt[i][j] = max(lcs, max(opt[i-1][j], opt[i][j-1]));
        	}
        }
        return opt[len1][len2];
    }
    /*使用opt二维数组2*len2存储opt表
    因为opt[i][j]的状态至于左边opt[i][j-1]下边opt[i-1][j]与左下opt[i-1][j-1]有关
    所以只用两行就可以了
    Runtime: 24 ms
	Memory Usage: 8.7 MB*/
    int longestCommonSubsequence3(string text1, string text2) {
    	int len1=text1.length();
        int len2=text2.length();
        if(len1<1||len2<1) return 0;
        vector<vector<int> > opt(2, vector<int>(len2+1, 0)); //二维数组大小都要要加1
        int lcs = 0;
        string substr1;
        string substr2;
        char c1;
        char c2;
        for(int i=1; i<=len1; i++){
        	for(int j=1; j<=len2; j++){
        		// 截取前i个字符
        		// substr1 = text1.substr(0, i);
        		// substr2 = text2.substr(0, j);
        		//子字符串中的最后一位
        		c1=text1.at(i-1);
        		c2=text2.at(j-1);
        		//最后一个匹配则加1
        		if(c1==c2) lcs=opt[0][j-1]+1;
        		else lcs=opt[0][j-1];
        		opt[1][j] = max(lcs, max(opt[0][j], opt[1][j-1]));
        	}
        	opt[0]=opt[1];// 新旧交换
        }
        return opt[1][len2];
    }

        /*使用完整的opt二维数组len1*len2存储opt表 当两个不等的时候不用考虑opt[i-1][j-1],
        因为这个状态被opt[i-1][j]与opt[i][j-1]包含了
        Runtime: 16 ms
		Memory Usage: 14.7 MB*/
    int longestCommonSubsequence4(string text1, string text2) {
    	int len1=text1.length();
        int len2=text2.length();
        if(len1<1||len2<1) return 0;
        vector<vector<int> > opt(len1+1, vector<int>(len2+1, 0)); //二维数组大小都要要加1
        // int lcs = 0;
        for(int i=1; i<=len1; i++){
        	for(int j=1; j<=len2; j++){
        		//子字符串中的最后一位
        		char c1=text1.at(i-1);
        		char c2=text2.at(j-1);
        		//最后一个匹配则加1
        		if(c1==c2) opt[i][j]=opt[i-1][j-1]+1;
        		else opt[i][j] = max(opt[i-1][j], opt[i][j-1]);
        		
        	}
        }
        return opt[len1][len2];
    }
}; 

int main(int argc, char const *argv[])
{
	Solution Sol;
	int pair;
	int len1, len2;	
	while(cin>>pair){
		string str,tmp_str, str1, str2;
		while(pair--){
			cin>>len1;
			cin>>len2;
			cin>>str1;
			cin>>str2;
			// cout<<str2<<endl;
			cout<<Sol.longestCommonSubsequence4(str1, str2)<<endl;
		}
	}
	// string str1="oxcpqrsvwf";
	// string str2="shmtulqrypy";
	// // cout<<Sol.longestCommonSubsequence(str1, str2)<<endl;
	// cout<<Sol.longestCommonSubsequence4(str1, str2)<<endl;	
	// int a;
	// cin>>a;
	return 0;
}
