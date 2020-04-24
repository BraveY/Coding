#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
Runtime: 208 ms, faster than 10.35% of C++ online submissions for Gas Station.
Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Gas Station.
 */
class Solution {
 public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		for (int i = 0; i < n; i++) {
			int gas_left = 0;
			int index = i;
			int count = 0;
			while (gas[index] + gas_left >= cost[index]) {
				if (count == n) break;
				gas_left = gas_left + gas[index] - cost[index];
				if (index + 1 < n )
					index++;
				else index = 0;
				count++;
			}
			if (count == n) return i;
		}
		return -1;
	}

 private:
};

/*
Runtime: 4 ms, faster than 98.11% of C++ online submissions for Gas Station.
Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Gas Station.
 */
class Solution2 {
 public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		int cur_gas = 0;
		int sum = 0;
		int start = 0;
		for (int i = 0; i < n; i++) {
			cur_gas += gas[i] - cost[i];
			sum += gas[i] - cost[i];
			if (cur_gas < 0) {
				cur_gas = 0;
				start = i + 1;
			}
		}
		if (sum < 0) return -1;
		else return start;
	}

 private:
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	vector<int> gas = {1, 2, 3, 4, 5};
	vector<int> cost = {3, 4, 5, 1, 2};
	cout << sol.canCompleteCircuit(gas, cost) << endl;
	system("pause");
	return 0;
}