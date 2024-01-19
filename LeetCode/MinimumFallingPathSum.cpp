class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minPathSum = INT_MAX;
        unordered_map<string, int> memo;

        for (int i = 0; i < matrix[0].size(); ++i) {
            minPathSum = min(minPathSum, calculatePath(matrix, 0, i, memo));
        }

        return minPathSum;
    }

private:
    int calculatePath(vector<vector<int>>& matrix, int row, int col, unordered_map<string, int>& memo) {
        if (row == matrix.size() - 1) {
            return matrix[row][col];
        }

        string key = to_string(row) + "_" + to_string(col);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int currentCell = matrix[row][col];
        int nextRow = row + 1;

        int left = (col > 0) ? calculatePath(matrix, nextRow, col - 1, memo) : INT_MAX;
        int middle = calculatePath(matrix, nextRow, col, memo);
        int right = (col < matrix[row].size() - 1) ? calculatePath(matrix, nextRow, col + 1, memo) : INT_MAX;

        int result = currentCell + min(left, min(middle, right));
        memo[key] = result;

        return result;
    }
};
