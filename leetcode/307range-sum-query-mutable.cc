#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class FenwickTree {
  public:
	// 冒号后面：初始化列表，0不能参与索引，所以n+1
	FenwickTree(int n) : sums_(n + 1, 0) {}

	void update(int i, int delta) {
		while (i < sums_.size()) {
			sums_[i] += delta;
			i += lowbit(i);
		}
	}

	int query(int i) const {
		int sum = 0;
		while (i > 0) {
			sum += sums_[i];
			i -= lowbit(i);
		}
		return sum;
	}

  private:
	static inline int lowbit(int x) { return x & (-x); }
	vector<int> sums_;
};

class NumArray {
  public:
	NumArray(vector<int> nums) : nums_(std::move(nums)), tree_(nums_.size()) {
		for (int i = 0; i < nums_.size(); ++i) tree_.update(i + 1, nums_[i]);
	}

	void update(int i, int val) {
		tree_.update(i + 1, val - nums_[i]);
		nums_[i] = val;
	}

	int sumRange(int i, int j) { return tree_.query(j + 1) - tree_.query(i); }

  private:
	vector<int> nums_;
	FenwickTree tree_;
};

int main(int argc, char const* argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	// Solution sol;
	// cout << sol.solution() << endl;
	system("pause");
	return 0;
}