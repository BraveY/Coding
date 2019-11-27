#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
#include <string>
#include <stdio.h>
#include <queue>

using namespace std;

class Solution {
public:	
	int assign(std::vector<int>& monkey, std::vector<int>& banana){
		int len = banana.size();
		int time = 0;
		priority_queue <int,vector<int>,less<int> > m;
		priority_queue <int,vector<int>,less<int> > b;
		for(int i=0; i<len; i++){
			m.push(monkey[i]);
			b.push(banana[i]);
		}
		while(!m.empty()){
			time = max(time, abs(m.top()-b.top()));
			m.pop();
			b.pop();
		}
		return time;
	}
private:
	int abs(int a){
		if (a<0) return -a;
		else return a;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	ios::sync_with_stdio(false);
	// std::vector<int> monkey={5, 2, 8};
	// std::vector<int> banana={4, 3, 6};
	std::vector<int> input;
	std::vector<int> monkey;
	std::vector<int> banana;
	Solution sol;
	int a;
	while(cin>>a){
		input.push_back(a);
	}
	int len = input.size();
	for(int i=0; i<len; i++){
		if(i<len/2) monkey.push_back(input[i]);
		else banana.push_back(input[i]);
	}

	cout<<sol.assign(monkey, banana)<<endl;
	system("pause");	
	return 0;
}