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
struct node{//这是一种自定义设置优先队列优先级的方法，重载默认的 < 符号
    int m;
    int b;
    friend bool operator < (node A,node B){
        if(A.b==B.b)
            return A.m>B.m;/*注意这里的比较，这是写的数据越小优先级越高，即先取出数值小的元素其实也可以这么理解，队列我们是可以用数组来存储的，比较sort函数里我们写的cmp ，return a>b时 是按降序来排列的，eg ：6 5 4 3 2 1，因为队列又是满足先进先出的原则，所以我们首先取出的是1，也就是数值最小的那个*/
        return A.b>B.b;
    }
};

	void update_queue(vector<char>& pos, priority_queue <node>& mb, int k){
		vector<int> M;
		while(!mb.empty()){
			M.push_back(mb.top().m);
			mb.pop();
		}
		node no;
		int plen = pos.size();
		for(int i=0; i<M.size(); i++){
			int num = 0;
			int mpos = M[i];
			for(int j=0; j<=k; j++){
				if((mpos+j<plen)&&pos[mpos+j]=='B') num++;
				if((mpos-j>=0)&&pos[mpos-j]=='B') num++;
			}
			no.m = mpos;
			no.b = num;
			if(no.b!=0) mb.push(no);
		}		
	}

	int max_eaten_banana(vector<char>& pos, vector<int>& M, int k){
		int ans = 0;
		if(k==0) return 0;
		priority_queue <node> mb;
		node no;
		int plen = pos.size();
		//第一次扫描得到每个猴子在k步之内可以吃的香蕉
		for(int i=0; i<M.size(); i++){
			int num = 0;
			int mpos = M[i];
			for(int j=0; j<=k; j++){
				if((mpos+j<plen)&&pos[mpos+j]=='B') num++;
				if((mpos-j>=0)&&pos[mpos-j]=='B') num++;
			}
			no.m = mpos;
			no.b = num;
			if(no.b!=0) mb.push(no);
		}
		// while(!mb.empty()){
		// 	cout<<"m pos :"<<mb.top().m<<" num :"<< mb.top().b<<endl;
		// 	mb.pop();
		// }
		//将可以吃的最小的给拿出来
		while(!mb.empty()){
			node top = mb.top();
			int mpos = top.m;
			for(int j=0; j<=k; j++){
				if((mpos+j<plen)&&pos[mpos+j]=='B') {
					pos[mpos+j]='0';
					ans++;
					break;
					cout<<"no break"<<endl;
				}
				if((mpos-j>=0)&&pos[mpos-j]=='B') {
					pos[mpos-j]='0';
					ans++;
					break;
				}
			}			
			mb.pop();
			update_queue(pos, mb, k);
			// 重新更新新的结果
		}		

		// int mlen = M.size();
		// int blen = B.size();
		// for(int i=0; i<mlen; i++){
		// 	int max_dist = -1;
		// 	int dist = 0;
		// 	for(auto iter=B.begin(); iter!=b.end(); iter++){
		// 		dist = abs(M[i]-*iter);
		// 		if(dist<=k) max_dist = max(max_dist, dist);
		// 	}

		// }
		// int m_pos = mlen;
		// while(m_pos--){
		// 	int max_dist = -1;
		// 	for(int i=0; i<=k; i++){
		// 		if()
		// 	}
		// }
		return ans;
	}
private:

};

int main(int argc, char const *argv[])
{
	/* code */
	// ios::sync_with_stdio(false);
	// char ch;
	// vector<char> pos;
	// std::vector<int> M;
	// // std::vector<int> B;
	// int i=0;
	// int k=0;	
	// while(cin>>ch){
	// 	if(ch=='M' || ch=='B') {
	// 		pos.push_back(ch);
	// 		if(ch=='M') M.push_back(i);
	// 		i++;
	// 	}
	// 	else k=ch-'0';
	// }
	// // cout<<"M len: "<<M.size()<<endl;
	// // cout<<"B len: "<<B.size()<<endl;
	// // cout<<"pos len: "<<pos.size()<<endl;	
	// // cout<<"k : "<<k<<endl;
	// // cout<<pos<<end;
	// Solution sol;
	// cout<<sol.max_eaten_banana(pos, M, k)<<endl;
	// system("pause");	
	// return 0;
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