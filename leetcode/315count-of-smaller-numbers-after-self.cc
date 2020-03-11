#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <memory>

using namespace std;

// class Solution {
//  public:
//   vector<int> countSmaller(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> ans(n, -1);
//     for (int i = n - 1; i >= 0; i--) {
//       helper(nums, ans, i, n);
//     }
//     return ans;
//   }

//  private:
//   int helper(vector<int>& nums, vector<int>& ans, int ind, int n) {
//     if (ans[ind] > 0) return ans[ind];
//     int count = 0;
//     for (int i = ind + 1; i < n; i++) {
//       if (nums[i] < nums[ind]) {
//         int tmp_count = helper(nums, ans, i, n);
//         if(tmp_count>0){
//           count = 1+
//         }
//       }
//     }
//     ans[ind] = count;
//     return count;
//   }
// };
//TLE
class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int size = nums.size();
    tmp_vec.resize(size);
    rtn.resize(size);
    //将rtn元素都清0
    for (int i = 0; i < size; i++) {
      rtn[i] = 0;
      hash[nums[i]].push_back(i);
    }
    // 不用全局变量否则，多线程的时候会被修改。
    MergeSort(nums, 0, size - 1);
    return rtn;
  }
  //把tmp_vec设置成共有变量，而不在函数中设置为临时变量可以减少多次对其创建与销毁，提高效率
  vector<int> tmp_vec;
  vector<int> rtn;
  std::map<int, std::vector<int> > hash;

 private:
  void MergeSort(vector<int>& vec, int lo, int hi) {
    if (lo >= hi) return;          // base case 递归必备
    int mid = lo + (hi - lo) / 2;  //防止两个超级大的int相加后造成溢出
    MergeSort(vec, lo, mid);  //左边的子数组内统计其对应的每个元素的计数
    MergeSort(vec, mid + 1, hi);  //右边的子数组内统计其对应的每个元素的计数
    Merge(vec, lo, hi, mid);  // 统计交叉的情况
  }

  void Merge(vector<int>& vec, int lo, int hi, int mid) {
    //采用双指针来一次把左右两边已经merge后的小值冒泡出来放到合并后的数组中，同时完成对逆序数目的统计
    int p = lo;
    int q = mid + 1;
    int index = lo;
    while (p <= mid && q <= hi) {
      if ((long)vec[p] > (long)vec[q]) {
        // 如果存在逆序则对应左边的所有元素都要加上1个计数。p后面的每一个元素都会比q大
        for (int i = p; i <= mid; i++) {
          int ind;
          // cout << vec[i] << endl;
          int ind_size = hash[vec[i]].size();
          if (ind_size > 1) {  //对应的值出现了多次
            int add_count = 0;  //统计同一个值中所有在mid左边的个数
            for (int j = 0; j < ind_size; j++) {
              ind = hash[vec[i]][j];  //对应的值在原输入数组的索引
              int value = vec[i];
              if (ind >= lo && ind <= mid) {
                rtn[ind]++;  //只有在mid左边的才加+
                add_count++;
              }
            }
            //在上个循环里面已经把所有的值都给加+1了，所以往后面移动到下一个不同的值
            if (add_count) i += add_count - 1;
          } else {
            ind = hash[vec[i]][0];  //值不重复 则其对应的索引加+1
            rtn[ind]++;
          }
        }
        q++;
      } else {
        p++;
      }
    }
    //正常的merge操作
    p = lo;
    q = mid + 1;
    while (p <= mid && q <= hi) {
      if (vec[p] >= vec[q])
        tmp_vec[index++] = vec[q++];
      else
        tmp_vec[index++] = vec[p++];
    }
    while (p <= mid) tmp_vec[index++] = vec[p++];
    while (q <= hi) tmp_vec[index++] = vec[q++];
    for (int i = lo; i <= hi; i++) {
      vec[i] = tmp_vec[i];
    }
  }
};


//TLE
class Solution2 {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int size = nums.size();
    // tmp_vec.resize(size);
    // data.resize(size);
    // cout << data.size() << endl;
    rtn.resize(size);
    //将rtn元素都清0
    for (int i = 0; i < size; i++) {
      rtn[i] = 0;
      vector<int> node(2);
      node[0] = nums[i];  //存入一个dict 里面存有每个值对应的索引
      node[1] = i;
      data.push_back(node);
      tmp_vec.push_back({0, 0});
    }
    // for (int i = 0; i < size; i++) {
    //   tmp_vec[i] = data[i];
    // }

    // 不用全局变量否则，多线程的时候会被修改。
    MergeSort(data, 0, size - 1);
    // for (int i = 0; i < size; i++) {
    //   cout << tmp_vec[i][0] << " " << tmp_vec[i][1] << endl;
    //   cout << "**************" << endl;
    // }
    return rtn;
  }
  //把tmp_vec设置成共有变量，而不在函数中设置为临时变量可以减少多次对其创建与销毁，提高效率
  vector<vector<int> > tmp_vec;
  vector<vector<int> > data;
  vector<int> rtn;
  // std::map<int, std::vector<int> > hash;

 private:
  void MergeSort(vector<vector<int> >& vec, int lo, int hi) {
    if (lo >= hi) return;          // base case 递归必备
    int mid = lo + (hi - lo) / 2;  //防止两个超级大的int相加后造成溢出
    MergeSort(vec, lo, mid);  //左边的子数组内统计其对应的每个元素的计数
    MergeSort(vec, mid + 1, hi);  //右边的子数组内统计其对应的每个元素的计数
    Merge(vec, lo, hi, mid);  // 统计交叉的情况
  }

  void Merge(vector<vector<int> >& vec, int lo, int hi, int mid) {
    //采用双指针来一次把左右两边已经merge后的小值冒泡出来放到合并后的数组中，同时完成对逆序数目的统计
    int p = lo;
    int q = mid + 1;
    int index = lo;
    while (p <= mid && q <= hi) {
      // int value_p = vec[p][0];
      // int value_q = vec[q][0];
      if ((long)vec[p][0] > (long)vec[q][0]) {
        for (int i = p; i <= mid; i++) {
          int ind = vec[i][1];
          rtn[ind]++;
        }
        q++;
      } else {
        p++;
      }
    }
    //正常的merge操作
    p = lo;
    q = mid + 1;
    while (p <= mid && q <= hi) {
      if (vec[p][0] >= vec[q][0])
        tmp_vec[index++] = vec[q++];
      else
        tmp_vec[index++] = vec[p++];
    }
    while (p <= mid) tmp_vec[index++] = vec[p++];
    while (q <= hi) tmp_vec[index++] = vec[q++];
    for (int i = lo; i <= hi; i++) {
      vec[i] = tmp_vec[i];
    }
  }
};

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
/*
Runtime: 28 ms, faster than 91.55% of C++ online submissions for Count of Smaller Numbers After Self.
Memory Usage: 11.2 MB, less than 58.33% of C++ online submissions for Count of Smaller Numbers After Self.
 */
class Solution3 {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    // 排序并且 去重,转换成set 自动红黑树排序，并且去重
    set<int> sorted(nums.begin(), nums.end());
    // 建立每个的索引 ,unordered_map 是哈希表实现， map是红黑树实现
    // 哈希表执行效率更高，红黑树是log(n)
    unordered_map<int, int> ranks;
    int rank = 0;
    // 建立值的rank
    for (const int num : sorted)
      //必须是++在前面，这样rank从1开始而不是从0开始
      //从0开始的话后面查询的时候update的时候会出现0，陷入死循环
      ranks[num] = ++rank;

    std::vector<int> ans;
    FenwickTree tree(ranks.size());
    //逆序扫描
    for (int i = nums.size() - 1; i >= 0; --i) {
      // cout << i << endl;
      ans.push_back(tree.query(ranks[nums[i]] - 1));
      tree.update(ranks[nums[i]], 1);
    }
    std::reverse(ans.begin(), ans.end());
    // for (const int i : ans) cout << i << endl;
    return ans;
  }

 private:


};



/*
Runtime: 28 ms, faster than 91.55% of C++ online submissions for Count of Smaller Numbers After Self.
Memory Usage: 20.3 MB, less than 50.00% of C++ online submissions for Count of Smaller Numbers After Self.
 */

struct BSTNode {
  int val;
  int count;
  int left_count;
  BSTNode *left;
  BSTNode *right;
  //构造函数
  BSTNode(int val): val(val), count(1), left_count(0), left{nullptr}, right{nullptr} {}
  //析构函数
  ~BSTNode() {delete left; delete right;}
  int less_or_equal() const {return count + left_count;}
};


class Solution4 {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    if (nums.empty()) return {};
    std::reverse(nums.begin(), nums.end());
    std::unique_ptr<BSTNode> root(new BSTNode(nums[0]));
    vector<int> ans{0};
    for (int i = 1; i < nums.size(); ++i)
      ans.push_back(insert(root.get(), nums[i]));
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
 private:
  // Returns the number of elements smaller than val under root.
  // 树的插入是递归实现的。
  int insert(BSTNode* root, int val) {
    if (root->val == val) {
      ++root->count;
      return root->left_count;
    } else if (val < root->val) {
      ++root->left_count;
      if (root->left == nullptr) {
        root->left = new BSTNode(val);
        return 0;
      }
      return insert(root->left, val);
    } else  {
      if (root->right == nullptr) {
        root->right = new BSTNode(val);
        return root->less_or_equal();
      }
      return root->less_or_equal() + insert(root->right, val);
    }
  }
};
int main(int argc, char const * argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution4 sol;
  // std::vector<int> v = {26,78,27,100,33,67,90,23,66,5,38,7,35,
  //                       23,52,22,83,51,98,69,81,32,78,28,94,13,
  //                       2,97,3,76,99,51,9,21,84,66,65,36,100,41};
  // std::vector<int> v=
  // {26,78,27,101,103,67,90,23,96,5,38,7,35,33,52,22,83,41,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
  std::vector<int> v = {26, 78, 27, 31, 43, 78};
  vector<int> ans = sol.countSmaller(v);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  // cout << sol.countSmaller(v) << endl;
  system("pause");
  return 0;
}