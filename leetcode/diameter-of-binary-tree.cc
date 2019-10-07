/*https://leetcode.com/problems/diameter-of-binary-tree/*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        LP(root);
        return ans;
    }
private:
    int LP(TreeNode* root){//LP函数返回该节点左右子树中的最大深度+1（因为root节点到左右子节点还需要一个路径1）
        if(!root) return -1;// root为空则返回-1，说明上一个节点是一个叶子节点，-1+1=0说明叶子节点的左右子树的最大深度是0
        int l = LP(root->left)+1; //递归调用求左子树的最大深度
        int r = LP(root->right)+1;//递归调用求右子树的最大深度
        ans = max(ans, l+r); //因为对于一个根节点其最大深度为左右子树的最大深度相加，所以对ans进行更新
        return max(l,r); //返回此几点的最大子树深度
    }
};