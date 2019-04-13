// code_vs_proj.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL || length <= 0) exit(1);
		int blank_size = 0;
		for (int i = 0; i < length; i++) {    
			if (str[i] == ' ') blank_size++;
		}
		std::cout << blank_size  <<"\n";
		int new_len = length + 2 * blank_size + 1;
		std::cout << "new_len " << new_len << "\n";
		char *tmp_str = new char[new_len];
		tmp_str[--new_len] = '\0';
		std::cout << "new_len "<< new_len << "\n";
		int old_index = length -1 ;
		int new_index = new_len-1;
		std::cout << "old_index " << old_index << "\n";
		std::cout << "new_index " << new_index << "\n";
		while (old_index >= 0 && new_index >= 0) {
			if (str[old_index] != ' ') {
				tmp_str[new_index] = str[old_index];
				new_index--;
			}
			else {
				tmp_str[new_index--] = '0';
				tmp_str[new_index--] = '2';
				tmp_str[new_index--] = '%';
			}
			old_index--;
		}
		std::cout << "tmp str is " << tmp_str << "\n";
		str = tmp_str;
		delete tmp_str;
	}
};
int main()
{
	char str[] = "hello world";
	Solution sol;
	sol.replaceSpace(str, strlen(str));
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
