#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:	
	int cross(int limit, int num, vector<int>& person){
		if(num<=0) return 0;
		int ans = 0;
		int crossed = 0;
		for(int i = limit; i>0; i--){
			for(int j=person[i]; j>0; j--){
				ans++;
				crossed++;
				person[i]--;
				int rest = limit - i;
				for(int k=rest; k>0; k--){
					if(person[k]>0){
						person[k]--;
						if(k==i) j--; // 如果减去的和当前指向的weight一样 则需要减去自身
						crossed++;
						break;
					}
				}
			}
		}
		// if(crossed==num) cout<<"all crossed" <<endl;
		return ans;
	}
private:
};

int main(int argc, char const *argv[])
{
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	int limit; 
	int num;
	cin >> num>>limit;
	std::vector<int> vec(limit+1, 0);
	int weight = 0;
	int len = num;
	while(len--){
		cin>>weight;
		vec[weight]++;
	}
	cout<<sol.cross(limit, num, vec)<<endl;
	system("pause");	
	return 0;
}