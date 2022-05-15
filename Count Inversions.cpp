#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
long long  merge(vector< long long > &v,int p,int q,int r,long long  *inversions)
{
   // count inversions in the local arrays passed; 
   int n1 = q-p+1;
   int n2 = r-q;

   long long  left[n1+1];
   long long  right[n2+2];

   for(int i = 0;i<n1;i++)
      left[i] = v[p+i];
   for(int i = 0;i<n2;i++)
      right[i] = v[q+i+1];
    
   left[n1] = INT64_MAX;
   right[n2] = INT64_MAX;

    int x = 0,y = 0;
    for(int k = p;k<=r;k++)
    {
        if(left[x] <= right[y])
            v[k] = left[x++];
        else if(left[x] > right[y])
        {
            v[k] = right[y];
            if(left[x]!=INT_MAX)
            {
                //cout<<"left[i] = "<<left[x]<<" right[i] = "<<right[y]<<" ";
                *inversions+=(n1-x);
                //cout<<"n1 = "<<n1<<" n2 = "<<n2<<" x = "<<x<<" inversions = "<<*inversions<<endl;
            }
            y++;
        }
    }
    
    return *inversions;
}
long long  inversionSort(vector<long long>& v, int p, int r,long long  *inversion)
{
    if(p<r)
    {
        int q = floor((p+r)/2);

        inversionSort(v,p,q,inversion);
        inversionSort(v,q+1,r,inversion);

        long long ans = merge(v,p,q,r,inversion);

        return ans;
    }
    else
        return 0;
}
    long long int inversionCount(long long arr[], long long N)
    {
        vector<long long> v(N);

        for(int i= 0;i<N;i++)
            v[i] = arr[i];
        long long  ans = 0;
        long long  *p = &ans;

        ans = inversionSort(v,0,N-1,p);
        
        return ans;
        
        // Your Code Here
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
