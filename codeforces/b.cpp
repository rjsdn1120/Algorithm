#include<bits/stdc++.h>
using namespace std;
int arr[200005];
long long pre[200005];

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        vector<int> v;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            sum+=x;
            v.push_back(x);
        }

        sort(v.begin(),v.end());
        for(int i=0;i<n;i++) pre[i+1]=pre[i] + v[i];
        long long ans=-1;
        for(int i=0;i<=k;i++)
        {
            long long temp = sum - pre[i*2] - (pre[n] - pre[n - (k-i)]);
            ans = max(temp,ans);
            // printf("%d %lld\n",t,temp);
        }
        
        cout<<ans<<"\n";
        
    }
}