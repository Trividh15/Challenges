#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> rowFreq(n, 0);
        vector<int> colFreq(m, 0);
        unordered_map<int, pair<int, int>> posMap;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                posMap[mat[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            pair<int, int> cell = findIndex(posMap, arr[i]);
            if (!colorNcheck(rowFreq, colFreq, cell)) continue;
            else return i;
        }
        return -1;
    }

private:
    pair<int, int> findIndex(unordered_map<int, pair<int, int>>& posMap, int element) {
        return posMap[element]; 
    }

    bool colorNcheck(vector<int>& rowFreq, vector<int>& colFreq, pair<int, int> cell) {
        int r = cell.first, c = cell.second;
        rowFreq[r]++;
        colFreq[c]++;

        return rowFreq[r] == colFreq.size() || colFreq[c] == rowFreq.size();
    }
};
