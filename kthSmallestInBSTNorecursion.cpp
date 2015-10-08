//用栈处理中序遍历查找BST，O(K)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
	if (root == NULL)
	    return 0;
	stack<TreeNode*> stk;
	TreeNode* p = root;
	while (p || !stk.empty()) {
	    while (p) {
		stk.push(p);
		p = p->left;
	    }
	    p = stk.top();
	    if (--k == 0)
		return p->val;

	    stk.pop();
	    p = p->right;
	}
    }
};
