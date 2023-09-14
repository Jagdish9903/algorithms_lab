#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c;
    cout<<"enter the no. of items : ";
    cin>>n;
    vector<pair<int,int>> v(n+1, {0,0});
    cout<<"enter the capacity : ";
    cin>>c;
    cout<<"enter the weight and profit of individuals : \n";
    for(int i=1;i<=n;i++)
    {
        cout<<"for item "<<i<<" : ";
        cin>>v[i].first;
        cin>>v[i].second;
    }
    sort(v.begin(),v.end());
    cout<<"\nweight and profit pairs : \n";
    for(auto i:v)
    {
        cout<<i.first<<" : "<<i.second<<"\n";
    }
    vector<vector<int>> dp(n+1, vector<int> (c+1, 0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(j < v[i].first)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], v[i].second + dp[i-1][j-v[i].first]);
            }
        }
    }
    cout<<"\nmaximum possible profit = "<<dp[n][c]<<"\n";
}
