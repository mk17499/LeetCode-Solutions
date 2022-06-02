// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int arr[], int N) 
{
    // code here
        stack<pair<int,int> > st;
        vector<pair<int,int> > temp(N);

        int index = 0;
        for(int i = 0;i<N;i++)
        {
            if(st.empty())
                st.push({arr[i],i});
            else
            {
                if(arr[i]>=st.top().first)
                    st.push({arr[i],i});
    
                else
                {
                    temp[index].second = st.top().second;
                    temp[index].first = st.top().second;
                    st.pop();
                    while(!st.empty())
                    {
                        temp[index].first = st.top().second;
                        st.pop();
                    }
                    index++;
                    st.push({arr[i],i});
                }
            }
        }
        
        temp[index].second = st.top().second;
        temp[index].first = st.top().second;
        st.pop();
        while(!st.empty())
        {
            temp[index].first = st.top().second;
            st.pop();
        }
        index++;
        
        vector<vector<int> > ans;
        
        for(int i = 0;i<index;i++)
            if(temp[i].first!=temp[i].second)
                ans.push_back({temp[i].first,temp[i].second});
            
        if(ans.size() == 0)
            cout<<"No Profit\n";
        else
        {
            for(int i = 0;i<ans.size();i++)
                cout<<"("<<ans[i][0]<<" "<<ans[i][1]<<") ";
            cout<<"\n";
        }
}
