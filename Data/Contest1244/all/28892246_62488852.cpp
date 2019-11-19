//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mod 1000000007
#define fi first
#define se second
#define pii pair<int,int>
#define int long long
#define endl '\n'
#define pll pair<long long,long long>

using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const long long LONGLONG_MAX=1e17;
int c[3][100005];
vector<vector<int>>v;
int dp[100005][4][4];
int a[100005][4][4];
int dfs(int i,int j,int k,int par){
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int ans=LONGLONG_MAX,x=3;
    for(int l=0;l<3;l++){
        if(l==j||l==k)continue;
        int ans1=c[l][i];
        for(auto u:v[i]){
            if(u==par)continue;
            ans1+=dfs(u,k,l,i);
        }
        if(ans1<ans){
            ans=ans1;
            x=l;
        }
    }
    //cout<<x<<' ';
    a[i][j][k]=x;
    return dp[i][j][k]=ans;
}
int a1[100005];
void dfs1(int i,int j,int k,int par){
    a1[i]=a[i][j][k];
    for(auto l:v[i]){
        if(l==par)continue;
        dfs1(l,k,a[i][j][k],i);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cin>>c[i][j];
        }
    }
    v.resize(n);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(dp,-1,sizeof(dp));
    int x=0;
    for(int i=0;i<n;i++){
        if(v[i].size()>2){
            cout<<-1;
            return 0;
        }
        if(v[i].size()==1)x=i;
    }
    //cout<<LONGLONG_MAX;
    cout<<dfs(x,3,3,-1)<<endl;
    dfs1(x,3,3,-1);
    for(int i=0;i<n;i++){
        cout<<a1[i]+1<<" ";
    }
    return 0;
}