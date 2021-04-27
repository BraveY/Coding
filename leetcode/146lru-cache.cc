/*
 * @Author: your name
 * @Date: 2021-01-02 19:50:28
 * @LastEditTime: 2021-04-25 23:09:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\146lru-cache.cc
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
#include <list>

using namespace std;

class Solution {
  public:
	int solution() {}

  private:
};

/*
Runtime: 140 ms, faster than 73.18% of C++ online submissions for LRU Cache.
Memory Usage: 43.3 MB, less than 12.74% of C++ online submissions for LRU Cache.
使用链表的有序来进行排序，而不重新使用排序来得到。
*/
class LRUCache {
  public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if(!kv.count(key)) return -1;
        updateLRU(key);
        return kv[key];
    }
    
    void put(int key, int value) {
        if(!kv.count(key) && kv.size() == _capacity) {
            evict();
        }
        updateLRU(key);//updateLRU()的逻辑会先判断kv里面是否存在key,所以必须先执行updateLRU的操作，再往kv中插入，顺序不能乱。
        kv[key] = value;        
    }

  private:
    int _capacity;
    list<int> lru; //链表按序存放使用的key,新使用的放在最前面
    unordered_map<int, list<int>::iterator> mp; //记录key在链表的位置。需要使用迭代器而不是指针，list::erase()需要传入指针
    unordered_map<int, int> kv;

    void updateLRU(int key) { 
        if (kv.count(key)){ //在kv中的key必须保证存在于lru链表中，所以必须先更新lru再插入新的key在kv中。
            lru.erase(mp[key]); //已经存在的key需要删除后提到最前。 需要传入迭代器
        }
        lru.push_front(key); 
        mp[key] = lru.begin();
    }
    void evict(){
        mp.erase(lru.back()); // map::erase() 直接传入值就可以，因为是唯一的key
        kv.erase(lru.back());
        lru.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

void debug() {
	Solution sol;
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}