//中序递归查找BST中第k小的数，O(K)
class Solution {
public:
    int kthSmallest(treeNode* root, int k) {
	midSort(root, k);
	return ans;
    }
    void midSort(treeNode* root, int& k) {
	if (root == NULL)
	    return;
	midSort(root->left, k);
	if (--k == 0) {
	    ans = root->val;
	    return;
	}
	midSort(root->right, k);
    }
private:
    int ans;
};
