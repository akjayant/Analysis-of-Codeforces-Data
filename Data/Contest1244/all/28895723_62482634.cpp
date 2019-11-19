#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define M 1000000007
#define N 1000016
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define f first
#define s second
#define inf 9000000000000000000
ll a[N],b[N],c[N],ans,col[N];
vector<ll> v[N];
vector<ll> o = {0, 1, 2};

void dfs(ll x, ll ind=0, ll par=0) {

    col[x] = o[ind] + 1;
    if(o[ind]==0)
        ans += a[x];
    else if(o[ind]==1)
        ans += b[x];
    else
        ans += c[x];

    for(auto node: v[x]) {
        if(node==par)
            continue;
        dfs(node, (ind+1)%3, x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   ll n;
   cin>>n;
   for(ll i=1; i<=n; i++)
        cin>>a[i];
    for(ll i=1; i<=n; i++)
        cin>>b[i];
    for(ll i=1; i<=n; i++)
        cin>>c[i];

    ll flag = 0;
    for(ll i=1; i<n; i++) {
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        if(v[a].size()>2 || v[b].size()>2)
            flag = 1;
    }

    if(flag) {
        cout<<"-1\n";
        return 0;
    }

    ll root = 0;
    for(ll i=1; i<=n; i++) {
        if(v[i].size()==1) {
            root = i;
            break;
        }
    }

    ll maxi = inf;
    ll typ;
    ans = 0;
    dfs(root);
    if(ans<maxi) {
        maxi = ans;
        typ = 0;
    }

    o = {0, 2, 1};
    ans = 0;
    dfs(root);
    if(ans<maxi) {
        maxi = ans;
        typ = 1;
    }

    o = {1, 2, 0};
    ans = 0;
    dfs(root);
    if(ans<maxi) {
        maxi = ans;
        typ = 2;
    }

    o = {1, 0, 2};
    ans = 0;
    dfs(root);
    if(ans<maxi) {
        maxi = ans;
        typ = 3;
    }

    o = {2, 0, 1};
    ans = 0;
    dfs(root);
   if(ans<maxi) {
        maxi = ans;
        typ = 4;
    }

    o = {2, 1, 0};
    ans = 0;
    dfs(root);
    if(ans<maxi) {
        maxi = ans;
        typ = 5;
    }

    if(typ==0)
            o = {0, 1, 2};
        if(typ==1)
            o = {0, 2, 1};
        if(typ==2)
            o = {1, 2, 0};
        if(typ==3)
            o = {1, 0, 2};
        if(typ==4)
            o = {2, 0, 1};
        if(typ==5)
            o = {2, 1, 0};

    ans = 0;
    dfs(root);

    cout<<ans<<"\n";
    for(ll i=1; i<=n; i++)
        cout<<col[i]<<" ";

    return 0;
}
