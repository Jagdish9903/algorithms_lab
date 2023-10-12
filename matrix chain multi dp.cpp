#include<bits/stdc++.h>
using namespace std;
void print(int i, int j, int n, int *br, char &name)
{
    if(i == j)
    {
        cout<<name++;
        return;
    }
    cout<<"(";
    print(i,*((br + i*n)+j),n,br,name);
    print(*((br + i*n) + j) + 1, j, n, br, name);
    cout<<")";
}
int chain(vector<int> &p, int n)
{
    int dp[n][n] = {0};
    int br[n][n];
    for(int i=1;i<n;i++)
    {
        dp[i][i] = 0;
    }
    for(int l=2;l<n;l++)
    {
        for(int i = 1; i < n-l+1; i++)
        {
            int j = i + l -1;
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++)
            {
                int sum = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                if(sum < dp[i][j])
                {
                    dp[i][j] = sum;
                    br[i][j] = k;
                }
                dp[i][j] = min(dp[i][j], sum);
            }
            if(dp[i][j] == INT_MAX)
                dp[i][j]  = -1;
        }
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    char name = 'A';
    cout << "\nOptimal Parenthesization is : ";
    print(1, n - 1, n, (int*)br, name);
    return dp[1][n-1];
}
int main()
{
    int n;
    cout<<"enter the no. of elements in p : ";
    cin>>n;
    vector<int> p(n);
    cout<<"enter the elements of p : ";
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }
    int ans = chain(p, n);
    cout<<"\nmatrix chain multiplication optimal cost : "<<ans<<"\n";
}
