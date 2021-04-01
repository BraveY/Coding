/*
 * @Author: your name
 * @Date: 2021-03-16 21:41:41
 * @LastEditTime: 2021-03-26 16:44:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\224basic-calculator.cc
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
#include <stack>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

/*
Wrong solution not consider case :1+-+1
class Solution {
  public:
    int calculate(string s) {
        stack<int>  numStack;
        stack<char> operatorStack;
        numStack.push(0); // 针对首个字符带符号的情况-2+1
        operatorStack.push('(');
        s += ")"; // 默认外层添加() 从而可以进行运算
        int val = 0;
        int i = 0;
        while (i < s.size()) {      
            if (isdigit(s[i])) {
                while(isdigit(s[i])) { //"123"多位数的读取
                    val = val * 10 + (s[i] - '0');
                    ++i;
                }
                if (operatorStack.top() == '-') { // 直接存入负数
                    val = -val;
                    operatorStack.pop();
                    operatorStack.push('+');
                }
                numStack.push(val);
                val = 0;
            }else {     
                if (s[i] == ' ') {
                    ++i;                    
                    continue;
                }                
                if (s[i] == ')') {             
                    while (operatorStack.top() != '(') { // 退栈直到匹配到第一个左括号
                        char op = operatorStack.top();
                        int sign = op == '+' ? 1 : -1;
                        int right = numStack.top(); // 取一个操作数
                        numStack.pop();
                        int left = numStack.top();
                        numStack.pop();
                        numStack.push(left + sign * right);
                        operatorStack.pop();
                    }
                    operatorStack.pop(); // 左括号出栈
                }else {
                    operatorStack.push(s[i]);
                }
                ++i;
            }
        }
        return numStack.top();
    }

  private:
};
*/

/*
Stack 来处理括号。
Runtime: 4 ms, faster than 98.80% of C++ online submissions for Basic Calculator.
Memory Usage: 8 MB, less than 58.25% of C++ online submissions for Basic Calculator.
*/
class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int number = 0;
        int sign = 1;
        stack<int> stackCal;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                number = number * 10 + (int) (c - '0');
            }else if (c == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            }else if (c == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            }else if (c == '(') {
                //result += sign * number; // 左括号前面的只能时符号而不是数字，所以左括号之前已经做了运算。
                stackCal.push(result);
                stackCal.push(sign);
                result = 0;
                sign = 1;
            }else if (c == ')') {
                result += sign * number; // 右括号前面的只能是数字而不是符号，所以右括号之前需要做运算
                result *= stackCal.top(); //栈的操作符是给括号里面的
                stackCal.pop();
                result += stackCal.top();
                stackCal.pop();
                number = 0;
                sign = 1;
            }
        }
        if (number != 0) result += sign * number; // 数字还没加到result上的情况
        return result;
    }
};


class Solution {
public:
    int calculate(string s) {
        
    }
};

void debug() {
	Solution sol;

    string str = "1+1";
    cout << sol.calculate(str) << endl;
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}