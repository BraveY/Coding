//https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=11163&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    int rectCover(int number) {
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