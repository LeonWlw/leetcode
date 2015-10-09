//层序遍历二叉树，每层最右的点加入数组，用queue保存每层
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	res.clear();
	if (!root)
	    return res;

	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
	    res.push_back(q.back()->val);
	    int qSize = q.size();
	    for (int i = 0; i < qSize; ++i) {
		TreeNode* p = q.front();
		q.pop();
		if (p->left)
		    q.push(p->left);
		if (p->right)
		    q.push(p->right);
	    }
	}
    }
};
