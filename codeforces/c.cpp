#include<bits/stdc++.h>
using namespace std;
vector<int> arr;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        arr.clear();
        int n;cin>>n;
        int p=-1;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            if(x==p) continue;
            p=x;
            arr.push_back(x);
        }
        n=arr.size();
        int ans=n;
        for(int i=1;i<n-1;i++)
        {
            if(arr[i-1]<arr[i] && arr[i]<arr[i+1])
            {
                ans--;
            }
            else if(arr[i-1]> arr[i] && arr[i]>arr[i+1])
            {
                ans--;
            }
        }
        cout<<ans<<endl;       
    }
}