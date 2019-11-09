/*
http://theory.ict.ac.cn/grad_oj/contest/14/problem/51
*/
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

class Solution
{
public:
	/*使用nmk三维表内存爆掉*/
	int max_user(vector<vector<int> >& task, int disk, int mem, int nums){
		if(0==disk||0==mem||0==nums) return 0; //disk或者mem为0或者任务为0 则不可以进行服务返回0
		//总共的取值包括为0的情况，所以需要加1，顺便都全部初始为0
		vector<vector<vector<int> > > opt(nums+1, vector<vector<int> >(disk+1,vector<int>(mem+1,0)));
		/*可选的任务数，剩余硬盘数，剩余内存数都从1开始，开始填充opt表
		循环的顺序要严格和之前opt的声明顺序一直，第一维度是人数，第二维度是disk，第三维度是mem，不能乱*/ 
		for(int i=1;i<=nums;i++){ 
			int t=i-1; //i-1 表示对应的任务在task数组中的编号从第0个开始
			for(int j=1;j<=disk;j++){
				for(int k=1;k<=mem;k++){
					int disk_need = task[t][0];
					int mem_need = task[t][1];
					int user_served = task[t][2];
					//超过当前disk=j或者当前mem=k的限制，则不安排这个任务，考虑剩下i-1个任务
					if(disk_need>j||mem_need>k) opt[i][j][k]=opt[i-1][j][k]; 
					//未超过，考虑不安排该任务最终可服务的人数，与安排该任务最终所能够服务的人数谁更大
					else opt[i][j][k]=max(opt[i-1][j][k],opt[i-1][j-disk_need][k-mem_need]+user_served);
					// cout<<"i:"<<i<<"    j:"<<j<<"   k:"<<k<<endl;
					// cout<<opt[i][j][k]<<endl;
				}
			}
		}
		// cout<<opt[nums][disk][mem]<<endl;
		return opt[nums][disk][mem];
	}
	/*k的状态只与k-1相关因此可以只用两个nm的空间就可以了一次存储k-1，一个更新k*/
	/*TLE的解决*/
	int max_user2(vector<vector<int> >& task, int disk, int mem, int nums){
		if(0==disk||0==mem||0==nums) return 0; //disk或者mem为0或者任务为0 则不可以进行服务返回0
		//总共的取值包括为0的情况，所以需要加1，顺便都全部初始为0
		vector<vector<int> > opt_old(disk+1, vector<int>(mem+1,0));
		vector<vector<int> > opt_new(disk+1, vector<int>(mem+1,0));		
		/*可选的任务数，剩余硬盘数，剩余内存数都从1开始，开始填充opt表
		循环的顺序要严格和之前opt的声明顺序一直，第一维度是人数，第二维度是disk，第三维度是mem，不能乱*/ 
		for(int i=1;i<=nums;i++){ 
			int t=i-1; //i-1 表示对应的任务在task数组中的编号从第0个开始
			for(int j=1;j<=disk;j++){
				for(int k=1;k<=mem;k++){
					int disk_need = task[t][0];
					int mem_need = task[t][1];
					int user_served = task[t][2];
					//超过当前disk=j或者当前mem=k的限制，则不安排这个任务，考虑剩下i-1个任务
					if(disk_need>j||mem_need>k) opt_new[j][k]=opt_old[j][k]; 
					//未超过，考虑不安排该任务最终可服务的人数，与安排该任务最终所能够服务的人数谁更大
					else opt_new[j][k]=max(opt_old[j][k],opt_old[j-disk_need][k-mem_need]+user_served);
					// cout<<"i:"<<i<<"    j:"<<j<<"   k:"<<k<<endl;
					// cout<<opt[i][j][k]<<endl;
				}
			}
			opt_old =opt_new;
		}
		// cout<<opt[nums][disk][mem]<<endl;
		return opt_new[disk][mem];
	}	
	/*TLE的解决
	第二种方法因为有新旧opt的复制，所以实际的时间复杂度是第一种的2倍，因此有几个样例过不了
	实际上只用一个二维数组就够了，当从后往前遍历的时候就可以对于一个同一个二维数组使用了*/
	int max_user3(vector<vector<int> >& task, int disk, int mem, int nums){
		if(0==disk||0==mem||0==nums) return 0; //disk或者mem为0或者任务为0 则不可以进行服务返回0
		//总共的取值包括为0的情况，所以需要加1，顺便都全部初始为0
		vector<vector<int> > opt(disk+1, vector<int>(mem+1,0));
		// vector<vector<int> > opt_new(disk+1, vector<int>(mem+1,0));		
		/*可选的任务数，剩余硬盘数，剩余内存数都从1开始，开始填充opt表
		循环的顺序要严格和之前opt的声明顺序一直，第一维度是人数，第二维度是disk，第三维度是mem，不能乱*/ 
		for(int i=1;i<=nums;i++){ 
			int t=i-1; //i-1 表示对应的任务在task数组中的编号从第0个开始
			for(int j=disk;j>=1;j--){
				for(int k=mem;k>=1;k--){
					int disk_need = task[t][0];
					int mem_need = task[t][1];
					int user_served = task[t][2];
					//超过当前disk=j或者当前mem=k的限制，则不安排这个任务，考虑剩下i-1个任务
					if(disk_need>j||mem_need>k) opt[j][k]=opt[j][k]; 
					//未超过，考虑不安排该任务最终可服务的人数，与安排该任务最终所能够服务的人数谁更大
					else opt[j][k]=max(opt[j][k],opt[j-disk_need][k-mem_need]+user_served);
					// cout<<"i:"<<i<<"    j:"<<j<<"   k:"<<k<<endl;
					// cout<<opt[i][j][k]<<endl;
				}
			}
		}
		// cout<<opt[nums][disk][mem]<<endl;
		return opt[disk][mem];
	}	
	
};


int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int m, n, k;
	Solution Sol;
	int ans=0;
	int ans2=0;
	while(cin>>m>>n>>k){
		vector<vector<int> > task(k, vector<int>(3));
		for(int i=0; i<k; i++){
			for(int j=0; j<3; j++){
				cin>>task[i][j];
			}
		}
		// cout<<task[0][1];
		ans = Sol.max_user(task,m,n,k);
		ans2 = Sol.max_user3(task,m,n,k);
		cout<<ans<<endl;
		cout<<ans2<<endl;
	}
	return 0;
}