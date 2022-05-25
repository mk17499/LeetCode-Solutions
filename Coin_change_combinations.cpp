class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int m = coins.size();
        int n = amount;
        long long int dp[m][n+1];
        for(int i = 0;i<m;i++)
            dp[i][0] = 1;
        for(int i = 1;i<n+1;i++)
        {
            if(i<coins[0])
                dp[0][i] = 0;
            else
            {
                if(dp[0][i-coins[0]] == 1)
                    dp[0][i] = 1;
                else
                    dp[0][i] = 0;
            }
        }
        for(int i = 1;i<=m-1;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(coins[i] > j)
                    dp[i][j] = dp[i-1][j];
                else if(coins[i] <=j)
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
            }
        }
        return dp[m-1][n];    
    }
};
// Using Bottom Up tabulation
