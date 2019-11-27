#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
#include <string>
#include <stdio.h>
#include <queue>

using namespace std;



int abs(int a){
	if (a<0) return -a;
	else return a;
}

int main(int argc, char const *argv[])
{
	/* code */
	ios::sync_with_stdio(false);
	std::vector<int> input;
	priority_queue <int,vector<int>,less<int> > m;
	priority_queue <int,vector<int>,less<int> > b;
	int a;
	while(cin>>a){
		input.push_back(a);
	}
	int len = input.size();
	for(int i=0; i<len; i++){
		if(i<len/2) m.push(input[i]);
		else b.push(input[i]);
	}
	int time = 0;
	while(!m.empty()){
		time = max(time, abs(m.top()-b.top()));
		m.pop();
		b.pop();
	}
	cout<<time<<endl;
	system("pause");	
	return 0;
}