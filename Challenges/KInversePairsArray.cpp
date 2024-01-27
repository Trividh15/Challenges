class Solution {
public:
    int kInversePairs(int n, int k) {
        const int m = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return findPairs(n, k, m, dp);
    }

private:
    int findPairs(int n, int k, const int m, vector<vector<int>>& dp) {
        if (k < 0) return 0;
        if (n == 0) return k == 0;

        if (dp[n][k] != -1) return dp[n][k];

        int ans = 0;
        for (int i = 0; i <= min(k, n - 1); i++) {
            ans += findPairs(n - 1, k - i, m, dp);
            ans %= m;
        }

        dp[n][k] = ans;
        return ans;
    }
};
