class Solution {
public:
    int climbStairs(int n) {
        vector <int> memo(n+1, -1);
        return staircounter(n, memo);
    }

private:
    int staircounter(int n, vector<int> &memo)
    {

        if(n<=2)
        {
            return n;
        }

        if(memo[n] != -1)
        {
            return memo[n];
        }

        memo[n] = staircounter(n-1, memo) + staircounter(n-2, memo);
        return memo[n];

    }

};
