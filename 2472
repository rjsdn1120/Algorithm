#include<bits/stdc++.h>
#define INF 1001001000
using namespace std;
int dist[3][100100];
bool ck[100100];
int n;
vector<vector<pair<int,int> > >adj(100100);
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
struct stu
{
    int i,a,b,c;
}ar[100100];
bool com(stu a,stu b)
{
    return a.a<b.a;
}
int a_idx[100100];
int tree[400100];
int p=1;
void update(int idx,int val)
{
    while(n>=p) p<<=1;
    int it=p+idx-1;
    if(tree[it]>=val)
    {
        tree[it]=val;
    }
    else return;
    it>>=1;
    while(it>=1)
    {
        tree[it]=min(tree[it*2],tree[it*2+1]);
        it>>=1;
    }
}
int find(int l,int r)
{
    int tmp=INF;
    int tl=p+l,tr=p+r;
    while(tl<=tr)
    {
        if(tl%2==1)
        {
            tmp=min(tmp,tree[tl]);
            tl++;
        }
        if(tr%2==0){tmp=min(tmp,tree[tr]);tr--;};
        tl>>=1,tr>>=1;
    }
    return tmp;
}
int main()
{
    cin>>n;
    int a[3];cin>>a[0]>>a[1]>>a[2];
    int m;cin>>m;
    fill(tree,tree+400100,INF);
    for(int i=0;i<m;i++)
    {
        int q,w,e;scanf("%d%d%d",&q,&w,&e);
        adj[q].push_back(make_pair(w,e));
        adj[w].push_back(make_pair(q,e));
    }
    for(int i=0;i<3;i++)
    {
        fill(dist[i],dist[i]+100010,INF);
        dist[i][a[i]]=0;
        pq.push(make_pair(0,a[i]));
        while(!pq.empty())
        {
            int x=pq.top().second,dis=pq.top().first;
            pq.pop();
            for(int j=0;j<adj[x].size();j++)
            {
                int nx=adj[x][j].first,ndis=adj[x][j].second;
                if(dist[i][nx]>dis+ndis)
                {
                    dist[i][nx]=dis+ndis;
                    pq.push(make_pair(dist[i][nx],nx));
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        ar[i].i=i;
        ar[i].a=dist[0][i];
        ar[i].c=dist[2][i];
    }
    vector<pair<int,int> > arr;
    for(int i=1;i<=n;i++)
    {
        arr.push_back(make_pair(dist[1][i],i));
    }
    sort(arr.begin(),arr.end());
    int idx=1;
    for(int i=0;i<n;i++)
    {
        if(i && arr[i-1].first==arr[i].first) ar[arr[i].second].b=idx-1;
        else ar[arr[i].second].b=idx++;
    }
    sort(ar+1,ar+n+1,com);
    ar[0].a=-1;
    for(int i=1;i<=n;i++)
    {
        int ii=i;bool flag=false;
        vector<pair<int,int> > up;
        while(ii<=n)
        {
            if(ar[i].a==ar[ii].a)
            {
                flag=true;
                int k=find(0,ar[ii].b-2);
                if(k<ar[ii].c) ck[ar[ii].i]=true;
                up.push_back({ar[ii].b,ar[ii].c});
                ii++;
            }
            else
            {
                if(!flag)
                {
                    int k=find(0,ar[i].b-2);
                    if(k<ar[i].c) ck[ar[i].i]=true;
                    up.push_back({ar[i].b,ar[i].c});
                }
                else i = ii -1;
                break;
            }
        }
        for(auto i : up) update(i.first,i.second);
    }
    int t;cin>>t;
    while(t--)
    {
        int v;scanf("%d",&v);
        if(ck[v]) puts("NO");
        else puts("YES");
    }
    return 0;
}
