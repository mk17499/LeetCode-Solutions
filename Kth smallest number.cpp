#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int> &v,int i)
{
    int l,r;
    l = (i == 0 ? 1 : 2*i + 1);
    r = (i == 0 ? 2 : 2*i + 2);

    int min = i;
    if(l<v.size() && v[i]> v[l])
        min = l;
    else
        min = i;

    if(r<v.size() && v[min] > v[r])
        min = r;

    if(min!=i)
    {
        swap(v[min],v[i]);
        heapify(v,min);
    }
}
void build_heap(vector<int> &v,int N)
{
    for(int i = floor(N/2)-1;i>=0;i--)
        heapify(v,i);
}
int extract_min(vector<int> &v)
{
    int x = v[0];
    swap(v[0],v[v.size()-1]);
    v.pop_back();
    heapify(v,0);
    return x;
}
int solve(vector<int>& v,int N,int K)
{
    build_heap(v,N);
    int ans;
    for(int i = 0;i<K;i++)
        ans = extract_min(v);
    return ans;
}
  
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int N,K;
    cin>>N>>K;
    vector<int> v(N);


    for(int i = 0;i<N;i++)
        cin>>v[i];
    
    int ans = solve(v,N,K);
  
    cout<<ans<<endl;
  
  return 0;
}
