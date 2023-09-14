#include<bits/stdc++.h>
using namespace std;
bool comp(const pair<pair<int,int>,int> &x, const pair<pair<int,int>,int> &y)
{
    return x.second < y.second;
}
int main()
{
    int n,sum = 0;
    cout<<"enter the no. of edges : ";
    cin>>n;
    vector<pair<pair<int,int>,int>> v,ans;
    set<int> s,a;
    int x,y,weight;
    cout<<"\nenter values like this (v1 v2 weight) :\n";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        cin>>y;
        cin>>weight;
        v.push_back(make_pair(make_pair(x,y),weight));
        s.insert(x);
        s.insert(y);
    }
    cout<<"initially the edges are : \n\n";
    for(int i=0;i<n;i++)
    {
        cout<<"edge : ("<<v[i].first.first<<" , "<<v[i].first.second<<") : "<<v[i].second<<"\n";
    }
    sort(v.begin(),v.end(),comp);
    cout<<"sorted edges are : "<<"\n\n";
    for(int i=0;i<n;i++)
    {
        cout<<"edge : ("<<v[i].first.first<<" , "<<v[i].first.second<<") : "<<v[i].second<<"\n";
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(count == s.size()-1)
            break;
        int x = v[i].first.first;
        int y = v[i].first.second;
        int z = v[i].second;
        if(a.find(x) != a.end() && a.find(y) != a.end() && a.size() != s.size())
            continue;
        if(a.find(x) == a.end() || a.find(y) == a.end() || s.size() == a.size())
        {
            a.insert(x);
            a.insert(y);
            sum += z;
            ans.push_back(make_pair(make_pair(x,y),z));
            count++;
        }
    }
    cout<<"so, the edges in minimum spanning tree : \n\n";
    for(int i=0;i<ans.size();i++)
    {
        cout<<"edge : ("<<ans[i].first.first<<" , "<<ans[i].first.second<<") : "<<ans[i].second<<"\n";
    }
    cout<<"\nTotal weight of MST = "<<sum<<"\n";
}
