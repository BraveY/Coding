#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <sstream>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
class Solution {
  private:
  public:
	int solution() {}
};


int get_max_weight(int max_weight, const vector<int>& weight_list, const vector<int>& value_list) {
    int n = weight_list.size();
    if (!n) return 0;
    vector<vector<int>> dp(n+1, vector<int>(max_weight + 1, 0));
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= max_weight; ++j) {
            if (j - weight_list[i - 1] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight_list[i - 1]] + value_list[i-1]);
            }
        }
    }
    return dp[n][max_weight];
}

void fill_input_list(const string & input_str, vector<int>& input_list) {
    for(int i = 0; i < input_str.size(); ++i) {
        int num = 0;
        while (i < input_str.size() && input_str[i] != ',') {
            num = num*10 + (input_str[i] - '0');
            ++i;
        }
        input_list.push_back(num);
    }
}


// 读取不定数量的字符串，按逗号分割转换为数字并转到数组中。
void input(){

    string str; 
    vector<vector<int>> in_vec_list;

    while(cin >> str) { // 按行读取到string
        in_vec_list.push_back({});
        stringstream ss_line(str);//string 转换到stringstream
        string temp;
        while (getline(ss_line, temp, ',')) { // 对stringstream 按照','作为分隔符，把数据读取到temp 字符串
            //需要的话可以判断temp的字符串长度是不是为0，否则重复输入num。
            stringstream ss_int(temp);
            int num;
            ss_int >> num; // 字符串转到int
            in_vec_list.back().push_back(num);
        }
    }
    for(int i = 0; i < in_vec_list.size(); ++i) {
        cout_vector(in_vec_list[i]);
    }
}


int main(int argc, char const *argv[]) {
	/* code */
    int max_weight = 0; 
    int num = 0;
    char c;
    vector<int> weight_list;
    vector<int> value_list;
    cin >> max_weight;
    string input_str;
    int lines = 2;
    while (lines-- && cin >> input_str)
    {
        if (lines) {
            fill_input_list(input_str, weight_list);
        }else{
            fill_input_list(input_str, value_list);
        }
    }   
    cout << get_max_weight(max_weight, weight_list, value_list) << endl;
	return 0;
}