class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int N ) 
    {
        //code here
        int count = 0;
        unordered_map<int,int> mp;

        int sum = 0;
        mp[0] = 1;

        for(int i = 0;i<N;i++)
        {
            sum+=arr[i];
            if(mp.find(sum)!=mp.end())
            {
                count+=mp[sum];
                mp[sum]++;
            }
            else
                mp[sum] = 1;
        }
        return count;
    }
};
// we start with outside of array i.e. index -1. At index -1, sum = 0. From there we start our algorithm.
