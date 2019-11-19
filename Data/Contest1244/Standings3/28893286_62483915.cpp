#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define fi first
#define ii pair<int,int>
#define iii pair<int, ii>
#define se second
#define double long double
#define mod 1000000007
#define popcount __builtin_popcountll
using namespace std;
const double PI = acos(-1.0);

ll c[3][100010];
vector<int>vv;
vector<int>v[100010];
void dfs(int node, int p){
    vv.pb(node);
    for(auto nx:v[node]){
        if(nx==p)continue;
        dfs(nx, node);
    }
}
int ans[2000200];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[0][i];
    for(int i=1;i<=n;i++)cin>>c[1][i];
    for(int i=1;i<=n;i++)cin>>c[2][i];
    for(int i=1;i<n;i++){
        int x, y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    int cc = 0;
    int st = 0;
    for(int i=1;i<=n;i++){
        if(v[i].size()==1)st = i;
        if(v[i].size()>2){
            cout<<-1<<endl;
            return 0;
        }
        if(v[i].size()==2)cc++;
    }
    dfs(st, st);
    vector<int>perm;
    perm.pb(0);
    perm.pb(1);
    perm.pb(2);
    ll amid = 1e18;
    vector<int>p;
    do{
        int idx = 0;
        ll s = 0;
        for(int i=0;i<n;i++){
            int cur = vv[i];
            s+=c[perm[idx]][cur];
            idx++; idx%=3;
        }
        if(amid>s){
            amid = s;
            p = perm;
        }
    }while(next_permutation(perm.begin(), perm.end()));
    cout<<amid<<endl;
    int idx = 0;
    for(int i=0;i<n;i++){
        int x = vv[i];
        ans[x] = p[idx] + 1;
        idx++; idx%=3;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" "; cout<<Endl;
    return 0;
}
