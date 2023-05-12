#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[100];
int main()
{
    int n,ans=0;cin>>n;
    for(int i=0;i<n;i++)
    {   
        cin>>arr[i];
    }
    for(ll i=0;i<n;i++)
    {
        int tmp=0;
        for(ll j=0;j<n;j++)
        {
            if(i==j) continue;
            ll p = i;
            ll q = j;
            if(p>q) swap(p,q);
            int k=p+1;
            for(; k<q;k++)
            {
                // (i-j)*(y-arr[i]) = (arr[i]-arr[j])*(x-i)
                if(((arr[p]-arr[q])*(k-p) + p*arr[p] - q*arr[p]) >= arr[k]*(p-q)) break;
            }
            if(k==q) tmp++;
        }
        // cout<<i<<' '<<tmp<<endl;
        ans=max(ans,tmp);
    }
    cout<<ans;
    return 0;
}