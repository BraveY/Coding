/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty() || vin.empty()) return NULL;
        /*TreeNode *parent_node ;
        // 父节点的初始化
        // 默认是叶子节点
        parent_node->val = pre[0];
        parent_node->left = NULL;
        parent_node->right = NULL;*/
        

        /*
        不能用上面的方式进行初始化节点，我的思路代码都是对的，因为上面的初始化问题，报了个运行错误，
        说什么检查数组越界，非法内存访问的，浪费了我一个晚上的时间，fuck
         */
        /*
        另外写代码对所有情况都需要考虑清除，然后对于传入空序列，说明没有节点，直接返回NULL就是了
         */
        
        // 父节点的初始化
        TreeNode *parent_node = new  TreeNode(pre[0]); // 默认是叶子节点
        int len = vin.size();
        int root_index = 0;
        if (len==1) return parent_node; // 加上这句后，运行时间快1ms，因为不用执行后面的语句
        vector<int> pre_tmp_left;
        vector<int> pre_tmp_right;
        vector<int> vin_tmp_left;
        vector<int> vin_tmp_right;
        // 得到左子树的前序与中序子序列  
        /*int i = 0;  //使用while循环比for循环慢1ms
        while (vin[i] != parent_node->val && i<len){
            vin_tmp_left.push_back(vin[i]);
            pre_tmp_left.push_back(pre[i+1]);
            i++;
        }*/
        for(int i=0; i<len; i++){
            if (vin[i]==pre[0]) {
                root_index = i;
                break;
            }
            else{
                vin_tmp_left.push_back(vin[i]);
                pre_tmp_left.push_back(pre[i+1]); 
            }
        }
        //parent_node->left = reConstructBinaryTree(pre_tmp_left, vin_tmp_left);  可以移到这儿来
        // 求右子树的前序与中序子序列
        /*
        i++; 
        while(i < len ){
            vin_tmp_right.push_back(vin[i]);
            pre_tmp_right.push_back(pre[i]);
            i++;
        }*/
        for(int i = root_index + 1; i<len; i++){
            vin_tmp_right.push_back(vin[i]);
            pre_tmp_right.push_back(pre[i]);
        }
        
        parent_node->left = reConstructBinaryTree(pre_tmp_left, vin_tmp_left); 
        parent_node->right = reConstructBinaryTree(pre_tmp_right, vin_tmp_right);
        return parent_node;
    }
};