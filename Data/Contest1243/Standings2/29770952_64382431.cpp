#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int main()
{
    //freopen("test.in","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int k; cin>>k;
    while(k--)
    {
        int n; cin>>n;
        string s,t; cin>>s>>t;
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++)
        {
            if(s[i]==t[i]) continue;
            int k=-1;
            for(int j=i+1;j<n;j++) if(s[j]==s[i]) {k=j;break;}
            if(k!=-1)
            {
                ans.pb({k,i});
                swap(s[k],t[i]);
                continue;
            }
            for(int j=i+1;j<n;j++) if(t[j]==s[i]) {k=j;break;}
            if(k==-1) break;
            ans.pb({k,k});
            ans.pb({k,i});
            swap(s[k],t[k]);
            swap(s[k],t[i]);
        }
        if(s!=t)
            cout<<"No\n";
        else
        {
            cout<<"Yes\n";
            cout<<ans.size()<<'\n';
            for(auto p:ans) cout<<p.x+1<<' '<<p.y+1<<'\n';
        }
    }
    return 0;
}
