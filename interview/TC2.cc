/*
 * @Author: your name
 * @Date: 2021-04-18 20:54:09
 * @LastEditTime: 2021-04-18 21:36:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\interview\TC2.cc
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


unordered_map<string, bool> dict;

bool solution(string a, string b) {
    bool rtn;
    int len = a.length();
    if (!len) return true;
    string key1 = a+b;
    string key2 = b+a;
    if (dict.count(key1)) return dict[key1];
    if (dict.count(key2)) return dict[key2];
    if (len % 2 == 0) {
        string a1 = a.substr(0, len / 2);
        string a2 = a.substr(len / 2);
        string b1 = b.substr(0, len / 2);
        string b2 = b.substr(len / 2);
        rtn = (solution(a1, b1) && solution(a2, b2)) || (solution(a1, b2) && solution(a2, b1)); 
    }else{
        rtn = a == b ? true : false;
    }
    dict[key1] = rtn;
    dict[key2] = rtn;
    return rtn;
}

void debug(){
    string a = "aaba";
    string b = "abaa";
    cout << solution(a,b) << endl;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
    int t;
    cin >> t;
    cin.ignore();
    char c;
    string a = ""; 
    string b = "";
    int cnt = 0;
    while(t--){
        getline(cin, a);
        getline(cin, b);
        bool rtn = solution(a, b);
        if (rtn) cout << "YES" << endl;
        else cout << "NO" << endl;
        a = "";
        b = "";
    }
	return 0;
}