class Solution{
    public:
    int maxLen(vector<int>&A, int N)
    {   
        // Your code here
        unordered_map<int,int> mp;
    
        mp[0] = -1;
        int sum = 0;
        int max = 0;
        int temp;
        for(int i = 0;i<N;i++)
        {
            sum+=A[i];
            if(mp.find(sum)!=mp.end())
            {
                temp = i - mp[sum];
                if(temp > max)
                    max = temp;
            }
            else
                mp[sum] = i;
        }
        return max;
    }
};
