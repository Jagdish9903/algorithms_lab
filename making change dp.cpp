#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter the no. of coins : ";
    cin>>n;
    vector<int> a(n+1,0);
    cout<<"enter values of coins : ";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int sum;
    cout<<"enter the amount : ";
    cin>>sum;
    vector<vector<int>> dp(n+1, vector<int> (sum + 1, 0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(i == 1)
            {
                dp[i][j] = 1 + dp[1][j-a[i]];
            }
            else if(j<a[i])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-a[i]]);
            }
        }
    }
    cout<<"\nminimum required coins = "<<dp[n][sum]<<"\n";
}
