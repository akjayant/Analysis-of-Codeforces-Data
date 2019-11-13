#include<bits/stdc++.h>
#define mod 1000000007
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,i,j;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        ll vis[n+10];
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            if(s1[i] == s2[i])
                vis[i]=1;
        }
        vector<pair<ll,ll> > ans;
        ll ok=1;
        for(i=0;i<n;i++)
        {
            if(vis[i])
                continue;
            ll f=0;
            char ch=s1[i];
            for(j=0;j<n;j++)
            {
                if(i == j || vis[j])
                    continue;
                if(s1[j] == ch)
                {
                    f=1;
                    swap(s1[j],s2[i]);
                    ans.pb({j,i});
                    vis[i]=1;
                    if(s1[j] == s2[j])
                        vis[j]=1;
                    else vis[j]=0;
                    break;
                }
            }
            if(f) continue;
            for(j=0;j<n;j++)
            {
                if(i == j || vis[j])
                    continue;
                if(s2[j] == ch)
                {
                    f=1;
                    swap(s1[i],s2[i]);
                    ans.pb({i,i});
                    swap(s1[i],s2[j]);
                    ans.pb({i,j});
                    vis[i]=1;
                    if(s1[j] == s2[j]) vis[j]=1;
                    break;
                }
            }
            if(!f)
            {
                ok=0;
                break;
            }
        }
        if(ok && ans.size() <= 2*n)
        {
            cout<<"Yes\n";
            cout<<ans.size()<<"\n";
            for(auto it:ans)
                cout<<it.F+1<<" "<<it.S+1<<"\n";
        }
        else cout<<"No\n";
    }
    return 0;
}