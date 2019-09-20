/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
 */
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class Solution{
	private:
		
	public:
		int ans;
		void quicksort(vector<int>& vec, int lo, int hi, int k){
			if(lo>=hi) { //正常情况下退出时相等的情况，为了避免其他逻辑错误因此再加上lo大于hi的情况
				ans = vec[hi]; // 递归到最后还没有找到说明就是最后的这个元素就是要找的第k大，不考虑k大len的情况。
				return; // base case 递归必备，有个出口只有一个元素的时候不会再递归。
			}
			int piv = partition(vec, lo, hi);
			if(piv==k){
				ans = vec[k];
				return;
			}
			else if(k<piv) quicksort(vec,lo,piv-1,k);//左边递归 piv不再参与两边的快排,因为已经找到它的位置了。
			else quicksort(vec,piv+1,hi,k);//右边递归
		}

		int partition(vector<int>&vec,int lo, int hi){
			int loNow = lo - 1;
			int piov = hi;
			for(int i = lo; i<=hi-1; i++){ // 必须小于等于，因为hi是下标而不是数组长度，
											//如果是长度的话i<len-1,会访问到倒数第二个，下标的话就不会。
				if(vec[i]<=vec[piov]){
					loNow++;
					swap(vec, loNow, i);
				}
			}
			swap(vec, loNow+1, piov);
			piov = loNow+1;
			return piov;
		}

		void swap(vector<int>& vec, int a, int b){
			int tmp = vec[a];
			vec[a] = vec[b];
			vec[b] = tmp;
		}
};


int main()
{
	int len, k;
	Solution Sol;
	vector<int> vec;
	//while(cin>>len>>k)
	while(scanf("%d %d", &len, &k)!=EOF)
	{
		int tmp_len = len ;
		while(tmp_len--) {
			int element;
			scanf("%d",&element);
			vec.push_back(element);
		}
		Sol.quicksort(vec, 0, len-1, len-k);
		cout<<Sol.ans<<endl;
	}
 	return 0;
}