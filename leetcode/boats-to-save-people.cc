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
leetcode 881
https://leetcode.com/problems/boats-to-save-people/
*/
class Solution {
 public:
  /* 桶排序 贪心的选择最胖的先走
  Runtime: 96 ms
  Memory Usage: 16.5 MB
  int numRescueBoats(vector<int>& people, int limit) {
  int num = people.size();
          if(num<=0) return 0;
  vector<int> person(limit+1, 0);
  for(int i=0; i<num; i++){
      person[people[i]]++;
  }
          int ans = 0;
          // int crossed = 0;
          for(int i = limit; i>0; i--){
                  for(int j=person[i]; j>0; j--){
                          ans++;
                          // crossed++;
                          person[i]--;// 运走一个人后 计数减1
                          int rest = limit - i;
                          for(int k=rest; k>0; k--){
                                  if(person[k]>0){
                                          person[k]--;
                                          if(k==i) j--; //
  如果减去的和当前指向的weight一样 则需要减去自身
                                          // crossed++;
                                          break;
                                  }
                          }
                  }
          }
          // if(crossed==num) cout<<"all crossed" <<endl;
          return ans;
  }*/
  /*排序后 双指针
      Runtime: 116 ms
      Memory Usage: 13.6 MB
  */
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int ans = 0;
    int i = 0;
    int j = people.size() - 1;
    while (i <= j) {
      if (people[i] + people[j] <= limit) {
        i++;
        j--;
        ans++;
      } else {
        j--;
        ans++;
      }
    }
    return ans;
  }
};