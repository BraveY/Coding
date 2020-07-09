#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <ctime>
#include <random>
using namespace std;

/*
Runtime: 180 ms, faster than 9.72% of C++ online submissions for Insert Delete GetRandom O(1).
Memory Usage: 22.6 MB, less than 98.91% of C++ online submissions for Insert Delete GetRandom O(1).
 */
class RandomizedSet1 {
  public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		data = {};
		srand(time(0));
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (!data.count(val)) {
			data.insert(val);
			return true;
		}
		return false;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (data.count(val)) {
			data.erase(val);
			return true;
		}
		return false;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int len = data.size();
		unordered_set<int>::iterator it = data.begin();
		int r = rand() % len;
		// cout << "r" << " " << time(0) << " " << r << endl;
		advance(it, r);
		return *(it);
	}
  private:
	unordered_set<int> data;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/*
Runtime: 84 ms, faster than 71.71% of C++ online submissions for Insert Delete GetRandom O(1).
Memory Usage: 22.8 MB, less than 79.66% of C++ online submissions for Insert Delete GetRandom O(1).
 */
class RandomizedSet {
  public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		data = {};
		srand(time(0));
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (lookup.count(val)) return false;
		lookup[val] = data.size(); // 记录每个val 在data 数组中的位置
		data.emplace_back(val);
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (!lookup.count(val)) return false;
		data[lookup[val]] = data.back();//用最后一个元素来填充删除的元素
		lookup[data.back()] = lookup[val];//更新lookup
		lookup.erase(val);
		data.pop_back();
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int len = data.size();
		int r = rand() % len;
		return data[r];
	}
  private:
	unordered_map<int, int> lookup;
	vector<int> data;
};
void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

void debug1() {
	int len = 10;
	const int SEED = 666;
	default_random_engine dre(SEED);
	uniform_int_distribution<int> dist(0, len - 1);
	int r = dist(dre);
	for (int i = 0; i < len ; i++) {
		cout << dist(dre) << " ";
	}
	cout << endl;
	// cout << "r" << r << endl;

}
void debug2() {
	const int SEED = 666;
	default_random_engine dre(SEED);

	// 1——10均匀分布的随机数生成器
	uniform_int_distribution<int> d(1, 10);

	// 创建一个vector用来接收
	const int LEN = 20;
	vector<int> v;
	v.reserve(LEN);

	for (int i = 0; i < LEN; ++i) {
		v.push_back(d(dre));
	}

	cout << "RESULT:" << endl;

	for (int i = 0; i < LEN; ++i) {
		cout << v[i] << " ";
	}

	cout << endl;
}
void debug() {
	RandomizedSet* obj = new RandomizedSet();
	bool param_1 = obj->insert(3);
	bool param_1a = obj->insert(2);
	bool param_1b = obj->insert(1);
	obj->insert(4);
	obj->insert(5);
	bool param_2 = obj->remove(2);
	cout << param_2 << endl;
	int param_3 = obj->getRandom();
	cout << param_3 << endl;
	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	// Solution sol;
	//一维数组的输入
	// vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	// cout << sol.solution(nums2) << endl;

	//二维数组的输入
	//int m, n;
	// while (cin >> m >> n) {
	// 	vector<vector<int>> grid(m, vector<int>(n));
	// 	for (int i = 0; i < m; i++) {
	// 		for (int j = 0; j < n; j++ ) {
	// 			cin >> grid[i][j];
	// 		}
	// 	}
	// 	int ans = sol.solution(grid);
	// 	cout << ans << endl;
	// }
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}