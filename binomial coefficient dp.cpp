#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,r;
    cout<<"enter n : ";
    cin>>n;
    cout<<"enter r : ";
    cin>>r;
    vector<vector<int>> dp(n+1, vector<int> (r+1,1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    cout<<"\nc ("<<n<<", "<<r<<") = "<<dp[n][r]<<"\n";
}
