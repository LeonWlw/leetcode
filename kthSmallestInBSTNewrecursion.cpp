//左树大小与k做比，O(h)
class Solution {
public:
    int calcTreeSize(TreeNode * root) {
	if (root == NULL)
	    return 0;
	return 1 + calcTreeSize(root->left) + calcTreeSize(root->right);
    }
    int kthSmallest(TreeNode * root, int k) {
	if (root == NULL)
	    return 0;
	int leftSize = calcTreeSize(root->left);
	if (leftSize == k - 1)
	    return root->val;
	else if (leftSize >= k)
	    return kthSmallest(root->left, k);
	else
	    return kthSmallest(root->right, k - leftSize - 1);
    }
}
