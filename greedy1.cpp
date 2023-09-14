#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,count=0;
    vector<int> a = {100,50,20,10,5,2,1};
    cout<<"enter the amount : ";
    cin>>n;
    for(int i=0;i<a.size();i++)
    {
        if(n >= a[i])
        {
            int tmp = n/a[i];
            count += tmp;
            n = n % a[i];
            cout<<"Rs. "<<a[i]<<" * "<<tmp<<" notes\n";
        }
    }
    cout<<"\ntotal coins = "<<count<<"\n";
    return 0;
}
