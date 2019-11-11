#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pll pair<ll, ll>
#define ppii pair<pii, pii>
using namespace std;
int n, a, b, c, ans[101], cnt[3];
string s;
vector<int> v[3];
int id(char x)
{
    if(x=='S') return 0;
    if(x=='R') return 1;
    if(x=='P') return 2;

}
void solve()
{
    for(int i=1; i<=n; i++) ans[i]=-1;
    for(int i=0; i<=2; i++) v[i].clear();
    int t, x[3];
    for(int i=1; i<=n; i++){
        t=id(s[i-1]);
        v[t].pb(i);
    }
    t=0;
    for(int i=0; i<=2; i++){
        x[i]=min((int)v[i].size(), cnt[i]);
        t+=x[i];
        cnt[i]-=x[i];
    }
    if(t<(n+1)/2){
        cout<<"NO"<<'\n';
        return;
    }
    for(int i=0; i<=2; i++){
        for(int j=1; j<=x[i]; j++){
            ans[v[i][j-1]]=i;
        }
    }
    t=1;
    for(int i=0; i<=2; i++){
        for(int j=1; j<=cnt[i]; j++){
            while(t<=n&&ans[t]!=-1) t++;
            ans[t]=i;
            t++;
        }
    }
    cout<<"YES"<<'\n';
    for(int i=1; i<=n; i++){
        if(ans[i]==0) cout<<'R';
        else if(ans[i]==1) cout<<'P';
        else cout<<'S';
    }
    cout<<'\n';
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("sol.inp", "r", stdin);
    //freopen("sol.out", "w", stdout);
    int test;
    cin>>test;
    while(test--){
        cin>>n;
        for(int i=0; i<=2; i++) cin>>cnt[i];
        cin>>s;
        solve();
    }
}
