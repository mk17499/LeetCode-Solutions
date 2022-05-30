#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int N,K;
    cin>>N>>K;
    vector<int> ans;
    vector<int> v;

    for(int i = 0;i<N;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int m = INT_MIN;
    int counter;
    for(int i = 0;i<K;i++)
    {
        if(v[i]>m)
        {
            m = v[i];
            counter = i+1;
        }
    }
    ans.push_back(m);
    counter--;
    int start=1,end=K;
    for(int i = 1;i<=N-K;i++)
    {
        if(counter == 0)
        {
            m = INT_MIN;
            for(int j = i;j<=i+K-1;j++)
            {
                
                if(v[j] > m)
                {
                    m = v[j];
                    counter = j - i +1;
                }
            }
            ans.push_back(m);
        }
        else 
        {
            if(v[i+K-1]>m)
            {
                m = v[i+K-1];
                counter = K;
            }
            ans.push_back(m);
        }
        counter--;
    }
    for(int i = 0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
/*
10 5
9 1 3 11 7 8 45 75 64 86
*/
