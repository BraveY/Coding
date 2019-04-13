class Solution {
public:
	void replaceSpace(char *str,int length) {
        // if(str==NULL || length<=0) exit(1);
        int blank_size = 0;
        int i = 0;
        while(str[i] != '\0'){
            if (str[i] == ' ') blank_size ++;
            i++;
        }
        int new_len = length + 2*blank_size;
        if (new_len == length) return ;  // 没有空格的考虑
        int old_index = length; // 指向'\0'
        int new_index = new_len; // 指向'\0'
        while(old_index>=0 && new_index>=0){
            if(str[old_index] != ' '){
                str[new_index] = str[old_index];
                new_index--;
            }
            else{
                str[new_index--] = '0';
                str[new_index--] = '2';
                str[new_index--] = '%';
            }
            old_index--;
        }
	}
};
// 是直接对原来的字符串进行操作，
// 然后我觉得题目需要更严谨点，因为既然是针对原来的字符串操作，
// 应该说清原来的字符串空间是足够添加新字符的。