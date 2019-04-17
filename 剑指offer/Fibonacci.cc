/*
https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 */
class Solution {
public:
    int Fibonacci(int n) {
        /* 当n很大的时候申请的空间会比较大，因为不需要返回序列，只需要返回值 所以可以不用数组来存放 */
        /*int array[n+1];
        for(int i=0; i<=n; i++){
            if(i==0) array[i]=0;
            else if(i==1) array[i]=1;
            else array[i] = array[i-1] + array[i-2];
        }
        return array[n];*/
        int result[2] = {0,1};
        if (n <2) return result[n];
        int fib_one = result[0];
        int fib_two = result[1];
        int fib;
        for (int i=2; i<=n; i++){
            fib = fib_one + fib_two;
            fib_one = fib_two;
            fib_two = fib;
        }
        return fib;
    }
};