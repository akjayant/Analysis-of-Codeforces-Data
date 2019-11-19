#include <bits/stdc++.h>
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define setDP(arr) memset(arr,-1,sizeof arr)
#define oo 2000000000
#define inf 1000000000000000LL
#define M 1000000007
typedef long long ll;
using namespace std;
const int N = 105001;

ll n ;
ll c[3][N];
vector<vector<ll> > g;

vector<ll> v[3];
vector<int> v2;
vector<ll> prem;
int res[N];
void dfs(int node, int prt){
    for(int i = 0 ; i < 3 ; i++)
        v[i].push_back(c[i][node]);
    v2.push_back(node);
    for(int i = 0 ; i < g[node].size();i++)
        if(g[node][i]!=prt)
            dfs(g[node][i],node);
}

ll ans=1000000000000000;

ll check(vector<ll>&a){
    ll ret = 0;
    for(int i = 0 ; i < n ; i++)
        ret+=v[a[i%3]-1][i];
    return ret;
}

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    cin >> n;
    g.resize(n+1);
    for(int i = 0 ; i < 3 ; i++)
        for(int j = 1 ; j <= n ; j++)
            scanf("%lld",&c[i][j]);
    for(int i = 1,a,b; i < n ; i++){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        if(g[a].size()==3)return puts("-1");
        if(g[b].size()==3)return puts("-1");
    }
    for(int i = 1 ; i <= n ; i++){
        if(g[i].size()==1){
            dfs(i,-1);
            break;
        }
    }
    prem.push_back(1);
    prem.push_back(2);
    prem.push_back(3);
    do{
        ans = min(ans,check(prem));
    }while(next_permutation(all(prem)));
    cout << ans << endl;
    prem.clear();
    prem.push_back(1);
    prem.push_back(2);
    prem.push_back(3);
    do{
        if(check(prem)==ans){
            for(int i = 0 ; i < n ; i++){
                res[v2[i]]=prem[(i)%3];
            }
            for(int i = 1 ; i <= n ; i++){
                printf("%d ",res[i]);
            }
            return 0;
        }
    }while(next_permutation(all(prem)));
    cout << -1 << endl;




    return 0;
}
