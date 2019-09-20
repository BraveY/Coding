/*
https://leetcode.com/problems/reverse-pairs/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
	vector<int> tmp_vec;//把tmp_vec设置成共有变量，而不在函数中设置为临时变量可以减少多次对其创建与销毁，提高效率
public:
    int reversePairs(vector<int>& nums) {
    	int size = nums.size();
    	tmp_vec.resize(nums.size());
        return MergeSort(nums, 0, size-1); // 不用全局变量否则，多线程的时候会被修改。
    }

private:
	int MergeSort(vector<int>& vec, int lo, int hi){
		if(lo>=hi) return 0;// base case 递归必备
		int mid = lo + (hi -lo)/2; //防止两个超级大的int相加后造成溢出
		int ans = 0;
		ans += MergeSort(vec, lo, mid); //左边merge的计数
		ans += MergeSort(vec, mid+1, hi); //右边merge的计数
		ans += Merge(vec, lo, hi, mid);// 返回什么？ 本次merge的计数 也就是split 的情况
		return ans;
	}

	int Merge(vector<int>& vec, int lo, int hi, int mid){ //采用双指针来一次把左右两边已经merge后的小值冒泡出来放到合并后的数组中，同时完成对逆序数目的统计
		int p = lo;
		int q = mid + 1;
		int count = 0;//记录逆序数目
		int index = lo;
		while(p<=mid&&q<=hi){
			if((long)vec[p] > (long)vec[q]){
				count += mid-p+1;
				q++;
			}else{
				p++;
			}
		}
		//正常的merge操作
		p = lo ;
		q = mid + 1;
		while(p<=mid&&q<=hi){
			if(vec[p]>=vec[q]) tmp_vec[index++]=vec[q++];
			else tmp_vec[index++]=vec[p++];
		}
		while(p<=mid) tmp_vec[index++]=vec[p++];
		while(q<=hi) tmp_vec[index++]=vec[q++];
		for(int i=lo; i<=hi; i++){
			vec[i] = tmp_vec[i];
		}
		return count;
	}    
};

int main(){
	Solution Sol;
	vector<int> vec;
	int n ;
	while(cin>>n){
		//int tmp = n;
		int element;
		while(n--){
			cin>>element;
			vec.push_back(element);
		}
		cout<<Sol.reversePairs(vec)<<endl;
	}
	
}