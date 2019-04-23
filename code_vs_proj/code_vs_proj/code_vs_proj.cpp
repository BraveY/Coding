// code_vs_proj.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

class ReSolution {
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
class FSolution {
public:
	int Fibonacci(int n) {
		vector<int> array;
		for (int i = 0; i <= n; i++) {
			if (i == 0) array.push_back(0);
			else if (i == 1) array.push_back(1);
			else array.push_back( array[i - 1] + array[i - 2]);
		}
		return array[n];
	}
};

class reSolution {
public:
	void reOrderArray(vector<int> &array) {
		int len = array.size();
		int odd = 0;
		int even = len - 1;
		int head = 0;
		int tail = len - 1;
		vector<int> tmp_array(len);
		for (int i = 0; i < len; i++) {
			if (array[head] % 2 == 1) {
				tmp_array[odd] = array[head];
				odd++;
			}
			if (array[tail] % 2 == 0) {
				tmp_array[even] = array[tail];
				even--;
			}
			head++;
			tail--;
		}
		for (int i = 0; i < len; i++) {
			std::cout << i << "is " << tmp_array[i] << std::endl;
			array[i] = tmp_array[i];
		}
	}

	/*    void swap(vector<int> &array, int ind_f, int ind_b){
			int tmp = array[ind_f];
			array[ind_f] = array[ind_b];
			array[ind_b] = tmp ;
		}*/
};


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode *merge_head = nullptr;
		if (pHead1 == nullptr) return pHead2;
		if (pHead2 == nullptr) return pHead1;
		if (pHead1->val < pHead2->val) {
			merge_head = pHead1;
			merge_head->next = Merge(pHead1->next,pHead2);
		}
		else {
			merge_head = pHead2;
			merge_head->next = Merge(pHead1, pHead2->next);
		}
		return merge_head;
	}
};
int main()
{
	//char str[] = "hello world";
	Solution sol;
	//sol.replaceSpace(str, strlen(str));
	// fib test
	//int rtn = sol.Fibonacci(3);
	//std::cout << rtn << std::endl;

	/* reorder test*/
	/*vector<int> in_array;
	for(int i = 1; i <= 7; i++) {
		in_array.push_back(i);
	}
	sol.reOrderArray(in_array);*/
	
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
