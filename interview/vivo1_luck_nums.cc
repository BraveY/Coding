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

const int LUCK_NUM = 7;
const char LUCK_NUM_CHAR = '7';

bool is_luck_num(int in_num) {
    if (in_num % LUCK_NUM == 0) return true;
    string in_str = to_string(in_num);
    for(int i = 0; i < in_str.size(); ++i) {
        if (in_str[i] == LUCK_NUM_CHAR) return true;
    }
    return false;
}

int luck_nums(const vector<int>& in_num_list) {
    int len = in_num_list.size();
    int ret = 0;
    for(int i = 0; i < len; ++i) {
        if (is_luck_num(in_num_list[i])) ++ret;
    }
    return ret;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
    vector<int> in_num_list;
    int input_num;
    while(cin >> input_num) {
        in_num_list.push_back(input_num);
    }
    cout << luck_nums(in_num_list) << endl;
	return 0;
}