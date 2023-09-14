#include<bits/stdc++.h>
using namespace std;
vector<int> x,y;
long long mul(long long a,long long b)
{
    long long x1,x2,x3,a1=0,a2=0,b1=0,b2=0;
    string g = to_string(a);
    string h = to_string(b);
    while(g.size()>h.size())
    {
        h = '0' + h;
    }
    while(g.size()<h.size())
    {
        g = '0' + g;
    }
    //cout<<"m = "<<m<<"\n";
    //string s = to_string(m);
    //cout<<"s = "<<s<<"\n";
    int n =max(g.size(),h.size());
    //cout<<"n = "<<n<<"\n";
    if(n==1)
    {
        cout<<a<<" * "<<b<<" = "<<a*b<<"\n";
        return a*b;
    }
    else
    {
        int mid = n/2;
        int k=mid-1;
        string s1 = to_string(a),s2=to_string(b);
        //cout<<s1<<"\t"<<s2<<"\n";
        cout<<"\n";
        for(int i=0;i<s1.size()/2;i++)
        {
            a1 = a1 + pow(10,k)*(s1[i]-'0');
            cout<<"a1 = "<<a1<<"\t";
            b1 = b1 + pow(10,k)*(s2[i]-'0');
            cout<<"b1 = "<<b1<<"\t";
            a2 = a2 + pow(10,k)*(s1[i+mid]-'0');
            cout<<"a2 = "<<a2<<"\t";
            b2 = b2 + pow(10,k)*(s2[i+mid]-'0');
            cout<<"b2 = "<<b2<<"\n";
            k--;
        }
        x1 = mul(a1,b1);
        x2 = mul(a2,b2);
        x3 = mul(a1+a2,b1+b2);
        cout<<"x1 = "<<x1<<"\t";
        cout<<"x2 = "<<x2<<"\t";
        cout<<"x3 = "<<x3<<"\n";
        //return (x1 * pow(10,n) + (x3-x1-x2)*pow(10,int(n/2)) + x2);
    }
    return (x1 * pow(10,n) + (x3-x1-x2)*pow(10,n/2) + x2);

}
int main()
{
    long long a,b;
    cout<<"enter first number : ";
    cin>>a;
    cout<<"enter second number : ";
    cin>>b;
    string s1 = to_string(a),s2=to_string(b);
    int n = s1.size();
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        x.push_back(s1[i]-'0');
        y.push_back(s2[i]-'0');
    }
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<"\t";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<y[i]<<"\t";
    }
    cout<<"final ans = "<<mul(a,b)<<"\n";
   // digit2(x,y);
}
