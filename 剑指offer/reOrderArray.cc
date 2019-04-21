/*https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        // 新建一个数组来暂时存储，O(N) 复杂度 3ms运行时间
		/*int len = array.size();
		int odd = 0;
		int even = len - 1;
		int head = 0;
		int tail = len - 1;
		vector<int> tmp_array(len);
		for (int i = 0; i < len; i++) {
			if (array[head] % 2 == 1) {
				tmp_array[odd] = array[head];
				odd++;
			}
			if (array[tail] % 2 == 0) {
				tmp_array[even] = array[tail];
				even--;
			}
			head++;
			tail--;
		}
		for (int i = 0; i < len; i++) {
			array[i] = tmp_array[i];
		}*/
        // 类似冒泡排序 前偶后奇就交换 最好O(N),最坏O(N^2)  5ms的运行时间
        for (int i = 0; i < array.size();i++)
        {
            for (int j = array.size() - 1; j>i;j--)
            {
                if (array[j] % 2 == 1 && array[j - 1]%2 == 0) //前偶后奇交换
                {
                    swap(array[j], array[j-1]);
                }
            }
        }
    }
      
};