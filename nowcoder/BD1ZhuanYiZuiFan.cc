/*
 * @Author: your name
 * @Date: 2021-04-11 14:28:54
 * @LastEditTime: 2021-04-11 15:39:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\nowcoder\BD1ZhuanYiZuiFan.cc
 */
/*
 * @Author: your name
 * @Date: 2019-11-22 15:00:25
 * @LastEditTime: 2021-04-10 14:22:45
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \Coding\solution_template.cc
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

/*
https://www.nowcoder.com/practice/b7b1ad820f0a493aa128ed6c9e0af448?tpId=143&tqId=33925&rp=1&ru=%2Fta%2Fexam-baidu&qru=%2Fta%2Fexam-baidu%2Fquestion-ranking&tab=answerKey
运行时间：14ms
超过47.57%用C++提交的代码
占用内存：1324KB
超过71.51%用C++提交的代码
*/
class Solution {
  private:
  public:
	int solution(int n, int t, int c, vector<int>& nums) {
        int l = 0, r = 0;
        int sum = 0;
        int count = 0;
        while(r < c - 1) {
            sum += nums[r];
            ++r;            
        }         
        while(r < nums.size()) {
            sum += nums[r];
            if (sum <= t) count++;
            sum -= nums[r- c + 1];
            ++r;            
        }
        return count;
    }
    int solution2(){
        int n,t,c;//n已有人数，c抽出人数，t为c个人的罪值
        while(cin>>n>>t>>c){
            int val[n],ans=0,sum=0;
            for(int i=0 ; i<n;i++)
                cin>>val[i];
            if(c>n){
                cout<<ans<<endl;
                continue;
            }
            for(int i=0;i<c-1;i++)
                sum+=val[i];//前c-1个
            for(int i=c-1;i<n;i++){
                sum+=val[i];
                if(sum<=t)
                    ans++;
                sum-=val[i-c+1];
            }
            cout<<ans<<endl;
        }
    }    
};


int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
    int n , t, c;
    int value;
    vector<int> nums;
    Solution sol;
     
    while (cin >> n >> t >> c)
    {
        nums = {};
        while (n--)
        {
            cin >> value;
            nums.push_back(value);
        }
        cout << sol.solution(n, t, c, nums) << endl;
    } 
	return 0;
}