#include<bits/stdc++.h>
using namespace std;
int binarysearch(int a[],int low,int high,int key)
{
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if(key>a[mid])
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}
int main()
{
    int n,key;
    cout<<"enter the no. of elements : ";
    cin>>n;
    int a[n];
    cout<<"enter the elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the search key : ";
    cin>>key;
    sort(a,a+n);
    int index = binarysearch(a,0,n-1,key);
    if(index == -1)
    {
        cout<<"element not found!\n";
    }
    else
    {
        cout<<"element found at index "<<index<<"\n";
    }
    return 0;
}
