/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		bool has_flag = false;
		if (pRoot1 == nullptr || pRoot2 == nullptr) return has_flag;
		//bool sub_flag = false; // 可以直接更行has_flag （一步一步的判断就可以），不用再申明一个bool变量
		if (pRoot1->val == pRoot2->val) {
			has_flag = sub_tree_find(pRoot1, pRoot2);
		}
        // 根节点不符合，遍历左节点
		if (!has_flag) {
			has_flag = HasSubtree(pRoot1->left, pRoot2); 
		}
        // 左节点不符合，遍历右节点
        if (!has_flag) {
            has_flag = HasSubtree(pRoot1->right, pRoot2);
        } 
		return has_flag;
		/*
        bool has_flag = false;
		if (pRoot1 == nullptr || pRoot2 == nullptr) return has_flag;
		bool sub_flag = false;
		if (pRoot1->val == pRoot2->val) {
			sub_flag = sub_tree_find(pRoot1, pRoot2);
		}
		if (!sub_flag) {
			sub_flag = HasSubtree(pRoot1->left, pRoot2) ||  HasSubtree(pRoot1->right, pRoot2); // 不应该用&&，只要有一个为真就是有子节点的
		}
		if (sub_flag == true) has_flag = true;
		return has_flag;*/
		
    }
    
    bool sub_tree_find(TreeNode *pRoot1, TreeNode *pRoot2) {
		bool sub_tree = false;
		if (pRoot1 == nullptr && pRoot2 != nullptr) return false;
		if (pRoot2 == nullptr) return true;
		if (pRoot1->val == pRoot2->val) {
			sub_tree = sub_tree_find(pRoot1->left, pRoot2->left) && sub_tree_find(pRoot1->right, pRoot2->right);
		}
		return sub_tree;
	}
};