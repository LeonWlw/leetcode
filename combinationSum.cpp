//递归DFS
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> tmp;

		sort(candidates.begin(), candidates.end());
		DFS(candidates, target, 0, tmp, res);
		return res;
	}
	void DFS(vector<int>& candidates, int target, int index, vector<int>& tmp, vector<vector<int>>& res) {
		if (target < 0)
			return;
		if (target == 0) {
			res.push_back(tmp);
			return;
		}
		for (int i = index; i < candidates.size(); ++i) {
			tmp.push_back(candidates[i]);
			DFS(candidates, target - candidates[i], i, tmp, res);
			tmp.pop_back();
		}
	}
};
