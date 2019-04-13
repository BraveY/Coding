class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        // if (array.empty()) exit(1); 牛客网上不考虑，否则不会在主函数 return 0
        int row = array.size();
        int col = array[0].size();
        int i = 0; int j = col - 1;
        while(i<row && j>=0){
            if (array[i][j] == target ) return true ;
            else if (array[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};

// vector 容器判断非空用empty()
// 二维的vector, 行数 row = vector.size() 
// 列数 col = vector[0].size