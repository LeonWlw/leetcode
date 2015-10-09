//DFS右子树并遍历记录深度，若当前深度大于记录深度，证明此子树为下层右子树，因为我为优先右子树进入下层。
class Solution {
    int maxDep = 0;
public:
    vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	res.clear();
	if (root == NULL)
	    return res;

	DFS(root, res, 1);
	return res;
    }
    void DFS(TreeNode* root, vector<int>& res, int dep) {
	if (dep > maxDep) {
	    maxDep = dep;
	    res.push_back(root->val);
	}
	if (root->right)
	    DFS(root->right, res, dep + 1）；
	if (root->left)
	    DFS(root->left, res, dep + 1）；
    }
};
