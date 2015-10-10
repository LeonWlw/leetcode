//将二叉树置换成一个按先序遍历顺序的只含右子树的新树，原地置换
//先序遍历，更新当前节点，注意要先保存右子树，因更新时，右子树已被更新
class Solution {
public:
    TreeNode* pre = NULL;
    void flatten(TreeNode* root) {
	if (!root)
	    return;

	TreeNode* lastRight = root->right;
	if (pre) {
	    pre->left = NULL;
	    pre->right = root;
	}
	pre = root;
	flatten(root->left);
	flatten(lastRight);
    }
};
