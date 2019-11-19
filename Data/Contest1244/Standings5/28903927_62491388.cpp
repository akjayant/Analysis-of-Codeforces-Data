#include<bits/stdc++.h>
using namespace std;
#define TRACE
#define M 1000000007
#define oo 1000000000000000007
#define F first
#define S second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
#define pb push_back
#define M6 5000009
#define M5 500009
#define pi 3.14159265
#define epsilon 1e-6
 
ll n,m,C1[M5],C2[M5],C3[M5],deg[M5],dp[M5][4][4],out[M5];

vector<ll> g[M5];
vector<ll> pre;

void dfs(ll cur, ll par) {
    pre.pb(cur);
    for(auto u: g[cur]) {
        if(u!=par) dfs(u,cur);
    }
}


int  main()
{
    ios_base::sync_with_stdio (0), cin.tie (0);
    //init();
 
    ll tc=1,t=0,i,j,k,a,b,c,d;
    //cin>>tc;
    while(t++<tc){
        cin>>n;
        for(i=1;i<=n;i++) cin>>C1[i];
        for(i=1;i<=n;i++) cin>>C2[i];
        for(i=1;i<=n;i++) cin>>C3[i];
        for(i=1;i<n;i++) {
            cin>>a>>b;
            g[a].pb(b); deg[a]++;
            g[b].pb(a); deg[b]++;
        }
        ll flag=1, d1=-1;
        for(i=1;i<=n;i++) {
            if(deg[i]>2) flag=-1;
            if(deg[i]==1) d1=i;
        }

        if(flag==1) {
            dfs(d1, -1);
            dp[0][1][2] = C1[d1];
            dp[0][1][3] = C1[d1];

            dp[0][2][1] = C2[d1];
            dp[0][2][3] = C2[d1];

            dp[0][3][2] = C3[d1];
            dp[0][3][1] = C3[d1];

            //cout<<d1<<" ";

            for(i=1;i<n;i++) {
                //cout<<pre[i]<<" ";
                dp[i][1][2] = C1[pre[i]]+dp[i-1][2][3];
                dp[i][1][3] = C1[pre[i]]+dp[i-1][3][2];

                dp[i][2][1] = C2[pre[i]]+dp[i-1][1][3];
                dp[i][2][3] = C2[pre[i]]+dp[i-1][3][1];

                dp[i][3][2] = C3[pre[i]]+dp[i-1][2][1];
                dp[i][3][1] = C3[pre[i]]+dp[i-1][1][2];

            }

            ll ans = dp[n-1][1][2]; a=1,b=2;
            if(dp[n-1][1][3]<ans) {
                ans = dp[n-1][1][3];
                a=1,b=3;
            }
            if(dp[n-1][2][3]<ans) {
                ans = dp[n-1][2][3];
                a=2,b=3;
            }
            if(dp[n-1][2][1]<ans) {
                ans = dp[n-1][2][1];
                a=2,b=1;
            }
            if(dp[n-1][3][1]<ans) {
                ans = dp[n-1][3][1];
                a=3,b=1;
            }
            if(dp[n-1][3][2]<ans) {
                ans = dp[n-1][3][2];
                a=3,b=2;
            }
            cout<<ans<<"\n";
            out[pre[n-1]]=a, out[pre[n-2]]=b;
            for(i=n-3;i>=0;i--) {
                //cout<<pre[i]<<" "<<a<<" "<<b<<" -> ";
                if(a==1 && b==2) out[pre[i]]=3,a=b,b=3;
                else if(a==1 && b==3) out[pre[i]]=2,a=b,b=2;
                else if(a==2 && b==1) out[pre[i]]=3,a=b,b=3;
                else if(a==2 && b==3) out[pre[i]]=1,a=b,b=1;
                else if(a==3 && b==1) out[pre[i]]=2,a=b,b=2;
                else if(a==3 && b==2) out[pre[i]]=1,a=b,b=1;

            }
            //cout<<"\n";
            for(i=1;i<=n;i++) cout<<out[i]<<" ";
        }
        else cout<<"-1";
    }
    return 0;
}

