#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <queue>

using namespace std;


void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

/*
Runtime: 236 ms, faster than 5.26% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 10.2 MB, less than 25.55% of C++ online submissions for Kth Largest Element in an Array.
 */
class Solution1 {
  public:
	int findKthLargest(vector<int>& nums, int k) {
		int n = nums.size();
		quicksort(nums, 0, n - 1, n - k);
		return ans;
	}
  private:
	int ans;
	void quicksort(vector<int>& nums, int lo , int hi, int k) {
		if (lo >= hi) {
			ans = nums[hi];
			return ;
		}
		int piv = partition(nums, lo, hi);
		if (piv == k) {
			ans = nums[k];
			return;
		} else if (k < piv ) quicksort(nums, lo , piv - 1, k);
		else quicksort(nums, piv + 1, hi, k );
	}
	int partition(vector<int>& nums, int lo, int hi) {
		int loNow = lo - 1;
		int piv = hi;
		for (int i = lo; i <= hi - 1; i++) {
			if (nums[i] <= nums[piv]) {
				loNow++;
				swap(nums[loNow], nums[i]);
			}
		}
		swap(nums[loNow + 1], nums[piv]);
		piv = loNow + 1;
		return piv;
	}
};

/*
Runtime: 12 ms, faster than 94.93% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 10.3 MB, less than 93.45% of C++ online submissions for Kth Largest Element in an Array.
*/
class Solution2 {
  public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), greater<int>());
		//int length = nums.size();
		return nums[k - 1];
	}
};

/*
Runtime: 20 ms, faster than 66.90% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 10.7 MB, less than 23.03% of C++ online submissions for Kth Largest Element in an Array.
*/
class Solution3 {
  public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> pq(nums.begin(), nums.end());
		for(int i = 0; i < k - 1; ++i) {
			pq.pop();
		}
		return pq.top();
	}
};

class Solution4 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        buildMaxHeap(nums);
        for (int i = 0; i < k - 1; i++) {
            swap(nums[0], nums[--heapSize]);//堆顶换到最后，同时heapSize--表示换到后面的已被淘汰不再有机会上浮。
            maxHeapify(nums, 0);
        }
        return nums[0];
    }
private:
    int heapSize;
    
    int left(int i) {
        return (i << 1) + 1; //左节点2*i + 1
    }
    
    int right(int i) {
        return (i << 1) + 2; //右节点2*i + 2
    }
    
    void maxHeapify(vector<int>& nums, int i) {// 将输入的元素一直调整到满足最大堆的要求。
        int largest = i, l = left(i), r = right(i);
        if (l < heapSize && nums[l] > nums[largest]) {
            largest = l;
        }
        if (r < heapSize && nums[r] > nums[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest);
        }
    }
    
    void buildMaxHeap(vector<int>& nums) {
        heapSize = nums.size();
        for (int i = (heapSize >> 1) - 1; i >= 0; i--) {//只对前面一半的部分进行调整。就可以完整建立。
            maxHeapify(nums, i);
        }
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, kth;
        while (true) {
            int idx = partition(nums, left, right);
            if (idx == k - 1) {
                kth = nums[idx];
                break;
            }
            if (idx < k - 1) {
                left = idx + 1; 
            } else {
                right = idx - 1;
            }
        }
        return kth;
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] <= pivot && nums[r] >= pivot) { // 必须先判断是否需要交换，放在后面会造成逻辑错误,区间判断可以加上等号
                swap(nums[l], nums[r]);
            }
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }
        swap(nums[left], nums[r]); //以左边为pivot则必须与right交换，反之以右边为pivot则必须交换left
        return r;
    }
};
void debug() {
	Solution sol;

	//一维数组的输入
	vector<int> nums1 = {99, 99};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	cout << sol.findKthLargest(nums1, 1) << endl;
	


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