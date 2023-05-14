#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        string s; cin>>s;
        map<char,int> m;
        for(auto i : s)
        {
            if(m.find(i)==m.end())
            {
                m[i]=1;
            }
            else m[i]+=1;
        }
        if(m.size()==1) cout<<"NO\n";
        else if(m.size()>2) cout<<"YES\n";
        else
        {
            bool flag=false;
            for(auto i : m)
            {
                if(i.second==1)
                {
                    flag=true;
                    break;
                }
            }
            if(flag) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
}