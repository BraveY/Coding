/*
https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
 */
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        /*if(rotateArray.empty()) return 0;
        int len = rotateArray.size();
        if(len==1) return rotateArray[0];
        int rotate_index = 0;
        for(int i=0; i<len; i++){
            if(rotateArray[i]>rotateArray[i+1]){
                rotate_index = i+1;
                break;
            }
        }
        return rotateArray[rotate_index];
        */
        // 二分查找 O(logn)
        if(rotateArray.empty()) return 0;
        int len = rotateArray.size();
        int ind = len/2;
        int head = 0;
        int tail = len-1;
        while(head<tail){  //这个是不能退出循环的到最后只有两个元素是会陷入死循环，所以需要设置退出条件
            if((tail-head)==1){  //退出条件tail比head大一
                ind = tail;
                break;
            }
            if(rotateArray[ind]>= rotateArray[head]) { //在第一个递增数组，移动head指针
                head = ind;  
            }
            if(rotateArray[ind]<=rotateArray[tail]){  // 在第二个递增数组，移动tail指针
                tail = ind;
            }
            ind = (head+tail)/2;
        }
        return rotateArray[ind];
    }
};