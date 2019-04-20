/*https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking*/
class Solution {
public:
    double Power(double base, int exponent) {
        if(base==0.0&&exponent<0){
            return 0.0;
        }
        unsigned int absexp = (unsigned int) exponent;
        if(exponent < 0){
            absexp = (unsigned int) (-exponent);
        }
        double result = uint_power(base,absexp);
        if(exponent<0){
            result = 1.0/result; //
        }
        return result;
    }
    /*double uint_power(double base, unsigned int exp){ //O(N)的复杂度
        double u_rst = double(1);
        if(exp==0) return u_rst; // 不需要这一步，==0的话就不会进入循环，最终也是返回1
        else {
             for(int i=1; i<=exp; i++ ){
                 u_rst *= base;
             }
        }
        return u_rst;
    }*/
    // 使用递归来优化乘法次数复杂度为O(N)
    /*double uint_power(double base, unsigned int exp){
        if(exp==0) return 1;
        if(exp==1) return base;
        double rtn ;
        if(exp%2==0) { 
            rtn = uint_power(base, exp/2);
            rtn *= rtn;
        }
        else {
            rtn = uint_power(base,(exp-1)/2);
            rtn = rtn*rtn*base;
        }
        return rtn;
    }*/
    double uint_power(double base, unsigned int exp){
        if(exp==0) return 1;
        if(exp==1) return base;
        double rtn = uint_power(base,exp>>1); //右移1位代替除法，因为相当于除以2，取整，
                                              // 所以奇数除以2也是(n-1)/2
        rtn *= rtn;
        if(exp&0X1==1) rtn *= base;  //与2做位与运算就是取余运算（奇数始终会有一个2^0，
                                      //也就是二进制的最低位是1）
        return rtn;
    }
};