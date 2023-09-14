#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
void greedy(int ind,int a[],int b[], vector<int> &s, int &cur,int count,vector<vector<int>> &ds)
{
    if(ind==n || cur>a[ind])
    {
        ds.push_back(s);
        ans = max(ans,count);
        return;
    }
        int tmp = cur;
        s.push_back(ind);
        cur = b[ind];
        count++;
        greedy(ind+1,a,b,s,cur,count,ds);
        s.pop_back();
        count--;
        cur = tmp;
        greedy(ind+1,a,b,s,cur,count,ds);
}
int main()
{
    cout<<"enter the total no. of activities : ";
    cin>>n;
    int a[n],b[n];
    int start = INT_MAX;
    int finish = 0;
    for(int i=0;i<n;i++)
    {
        cout<<"-----activity - "<<i+1<<"-----\n";
        cout<<"enter start time : ";
        cin>>a[i];
        if(a[i]<start)
            start = a[i];
        cout<<"enter finish time : ";
        cin>>b[i];
        if(b[i]>finish)
            finish = b[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                swap(b[j],b[j+1]);
            }
        }
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<"start time : "<<a[i]<<"\tfinish time : "<<b[i]<<"\n";
    int cur = start;
    vector<int> s;
    vector<vector<int>> ds;
    greedy(0,a,b,s,cur,0,ds);
    cout<<"DS : \n";
    for(auto i:ds)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"\nfollowing activities are selected : \n";
    for(auto i:ds)
    {
        for(auto j:i)
        {
            cout<<j<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\nmax activities = "<<ans<<"\n";
}
