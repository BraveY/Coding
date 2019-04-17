/*https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking*/
class Solution {
public:
    int jumpFloor(int number) {
        int result[3] = {0,1,2};
        if(number<3) return result[number];
        int fib_one = result[1];
        int fib_two = result[2];
        int fib;
        for(int i=3; i<=number; i++){
            fib = fib_one + fib_two;
            fib_one = fib_two;
            fib_two = fib;
        }
        return fib;
    }
};