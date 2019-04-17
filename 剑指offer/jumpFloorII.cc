class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> result;
        result.push_back(1); // f(0) =1 ;
        for(int i=1; i<=number; i++){
            int sum = 0;
            for(int j=0; j<i; j++){ // f(n)=f(n-1)+f(n-2)+...f(1)+f(0)
                sum += result[j];
            }
            result.push_back(sum);
        }
        return result[number];
    }
};