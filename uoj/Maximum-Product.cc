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
	int cut(int n){
		// if(n<4) return n;
		int product = 1;
		while(n>0){
			if(n<=4) break;
			product *= 3;
			n -= 3;
		}
		product *= n;
		return product;
	}
private:
};

int main(int argc, char const *argv[])
{
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	int n;
	while (cin>>n){
		cout<<sol.cut(n)<<endl;
	}
	system("pause");	
	return 0;
}