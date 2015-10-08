//一个二维矩阵，每个位置的生与死由1与0代表，满足4条规则决定其生死，要求能inplace更新矩阵，int可表示这里所需的4种状态
//0，死->死，1，生->生，2，生->死，3，死->生
class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
	int rows = board.size();
	if (rows == 0)
	    return;
	int colums = board[0].size();
	if (colums == 0)
	    return;
	for (int i = 0; i < rows; ++i)
	    for (int j = 0; j < colums; ++j) {
		int sum = getNeighbor(board, rows, colums, i ,j);
		if (sum == 2)					//活细胞有2个活邻居，活到下一代
		    continue;
		else if (sum == 3)				//活细胞有3个活邻居，活到下一代；死细胞有3个活邻居，下一代复活
		    board[i][j] = board[i][j] == 0 ? 3 : 1;
		else						//活细胞有少于2个活邻居或多余3个活邻居，下一代死
		    board[i][j] = board[i][j] == 1 ? 2 : 0;
	    }
	for (int i = 0; i < rows; ++i)
	    for (int j = 0; j < colums; ++j)
		board[i][j] %= 2;
    }
private:
    int getNeighbor(vector<vector<int> >& board, int rows, int colums, int x, int y) {
	int sum = 0;
	for (int i = x - 1; i < x + 2; ++i)
	    for (int j = y - 1; j < y + 2; ++j) {
		if (i == x && j == y)
		    continue;
		if (i >= 0 && i < rows && j >= 0 && j < colums && (board[i][j] == 1 || board[i][j] == 2))
		    ++sum;
	    }
	return sum;
    }
};
