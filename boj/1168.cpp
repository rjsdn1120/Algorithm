#include<bits/stdc++.h>
using namespace std;

int seg[400010];

int init(int node,int s,int e)
{
    if(s==e) return seg[node]=1;
    int mid=(s+e)/2;
    return seg[node]=init(2*node,s,mid)+init(2*node+1,mid+1,e);
}
int q(int node,int s,int e,int x)
{
    if(s==e) return s;
    int mid=(s+e)/2;
    if(x<=seg[node*2]) return q(node*2,s,mid,x);
    else return q(node*2+1,mid+1,e,x - seg[node*2]);
}
void update(int node,int s,int e,int x)
{
    seg[node]--;
    if(s==e) return;
    int mid=(s+e)/2;
    if (x<=mid) update(node*2,s,mid,x);
    else update(node*2+1,mid+1,e,x);
}
int main()
{
    int n,k;
    cin>>n>>k;

    init(1,1,n);

    int x=1;
    int ans;
    printf("<");
    for(int i=0;i<n;i++)
    {
        int num= n-i;
        x+=k-1;
        x%=num;
        if(x==0) x=num;

        ans = q(1,1,n,x);
        update(1,1,n,ans);
        if(i==n-1) printf("%d",ans);
        else printf("%d, ",ans);
    }
    printf(">");

    return 0;
}

