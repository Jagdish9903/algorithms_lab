#include<bits/stdc++.h>
using namespace std;
bool max_v_comp(pair<pair<double,double>,double> &a,pair<pair<double,double>,double> &b)
{
    return (a.first.second > b.first.second);
}
bool max_ratio_comp(pair<pair<double,double>,double> &a,pair<pair<double,double>,double> &b)
{
    return a.second > b.second;
}
double min_w(vector<pair<pair<double,double>, double>> &v, int c, int n)
{
    cout<<"\n\n------------------ min_v method : ------------------\n";
    sort(v.begin(),v.end());
    cout<<"\nweight and profit pairs : \n";
    for(auto i:v)
    {
        cout<<i.first.first<<", "<<i.first.second<<" : "<<i.second<<"\n";
    }
    double profit = 0, i = 0;
    while(c >= v[i].first.first)
    {
        profit += v[i].first.second;
        c -= v[i].first.first;
        i++;
    }
    profit += c * v[i].second;
    return profit;
}
double max_v(vector<pair<pair<double,double>, double>> &v, int c, int n)
{
    cout<<"\n\n------------------ max_v method : ------------------\n";
    sort(v.begin(),v.end(), max_v_comp);
    cout<<"\nweight and profit pairs : \n";
    for(auto i:v)
    {
        cout<<i.first.first<<", "<<i.first.second<<" : "<<i.second<<"\n";
    }
    double profit = 0, i = 0;
    while(c >= v[i].first.first)
    {
        profit += v[i].first.second;
        c -= v[i].first.first;
        i++;
    }
    profit += c * v[i].second;
    return profit;
}
double max_ratio(vector<pair<pair<double,double>, double>> &v, int c, int n)
{
    sort(v.begin(),v.end(), max_ratio_comp);
    cout<<"\n\n------------------ max_ratio method : ------------------\n";
    cout<<"\nweight and profit pairs : \n";
    for(auto i:v)
    {
        cout<<i.first.first<<", "<<i.first.second<<" : "<<i.second<<"\n";
    }
    double profit = 0, i = 0;
    while(c >= v[i].first.first)
    {
        profit += v[i].first.second;
        c -= v[i].first.first;
        i++;
    }
    profit += c * v[i].second;
    return profit;
}
int main()
{
    int n,c;
    cout<<"enter the no. of items : ";
    cin>>n;
    vector<pair<pair<double, double>, double>> v(n);
    cout<<"enter the capacity : ";
    cin>>c;
    cout<<"enter the weight and profit of individuals : \n";
    int a,b;
    for(int i=0;i<n;i++)
    {
        cout<<"for item "<<i<<" : ";
        cin>>a;
        cin>>b;
        v[i].first.first = a;
        v[i].first.second = b;
        v[i].second = b/(double)a;
    }
    double profit1 = min_w(v,c,n);
    cout<<"\nprofit by min_w method = "<<profit1<<"\n";
    double profit2 = max_v(v,c,n);
    cout<<"\nprofit by max_v method = "<<profit2<<"\n";
    double profit3 = max_ratio(v,c,n);
    cout<<"\nprofit by max_ratio method = "<<profit3<<"\n";
    //cout<<"\n\n--------------------------------------------------------\n";
    //cout<<"\n\nhence, max achievable profit = "<<max({profit1, profit2, profit3})<<"\n";
}
