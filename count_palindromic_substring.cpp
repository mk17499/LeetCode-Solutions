class Solution {
public:
    int countSubstrings(string s) 
    {
        if(s.size() == 1)
            return 1;
        bool dp[s.size()][s.size()];
        int count = 0;

        for(int i = 0;i<s.size();i++)
        {
            for(int j = 0;j<=i;j++)
            {
                if(i==j)
                {
                    dp[i][j] = 1;
                    count++;
                }
                else
                    dp[i][j] = 0;
            }
        }
        int i = 0,j = 1;
        while(i<=s.size()-1 && j<=s.size()-1)
        {
            if(s[i] == s[j])
            {
                dp[i][j] = 1;
                count++;
            }
            else
                dp[i][j] = 0;
            i++;
            j++;
        }
    
        i = 0;j = 2;
        int j_itr = 2;
        int itr = s.size()-2;
        while(itr--)
        {
            while(i<s.size() && j<s.size())
            {
                if(s[i] == s[j])
                {
                    if(dp[i+1][j-1] == 1)
                    {
                        count++;
                        dp[i][j] = 1;
                    }
                    else
                        dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = 0;
                }
                i++;
                j++;
            }
            j_itr++;
            i = 0;
            j = j_itr;
        }
        return count;
    }
};
//using DP, we do this in O(n^2)
