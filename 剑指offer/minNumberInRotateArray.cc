/*
https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 */
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        /* 暴力解法 O(N)
        if(rotateArray.empty()) return 0;
        int len = rotateArray.size();
        // if(len==1|| rotateArray[0] == rotateArray[len-1]) return rotateArray[0]; 
        // 首尾相等包含有分界点的情况，{1,1,1,1,2,2,1,1} 这种
        if(len==1]) return rotateArray[0]; // 可以不要，因为为0的时候不会进入for循环
        int rotate_index = 0;
        for(int i=0; i<len-1; i++){ 	// 会使用数组后一位的时候，遍历条件是小于len-1，不然当迭代到len-1的时候会造成越界
            if(rotateArray[i]>rotateArray[i+1]){
                rotate_index = i+1;
                break;
            }
        }
        return rotateArray[rotate_index];
        */
    }
};