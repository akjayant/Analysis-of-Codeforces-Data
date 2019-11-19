#include <bits/stdc++.h>

using namespace std;

const int N=1e6+2,MOD=1e9+7;

typedef long long ll;

int c,n,m,x,y,u,v,tc,k,ans,l,r,q,b[N],d[N];

ll dp[60][4][4][4][4];

pair<int,int> a[N];

char s[N];

string le,re;

bool vis[N];

ll dist[2007][2007];

vector<int> calc;
vector<pair<int,int>> calc2;

ll solve(int idx, int a, int b, int c, int d) {
    if (idx >= n) 
        return r = 1;
    ll &r = dp[idx][a][b][c][d];
    if (~r) 
        return r;
    r = 0;
    int x=(a ? 0 : le[idx] - '0');
    int y=(b ? 1 : re[idx] - '0');
    int z=(c ? 0 : le[idx] - '0');
    int w=(d ? 1 : re[idx] - '0');
    for(int  i=x;i<=y;i++) {
        for(int j=z;j<= w;j++) {
            if (i != 1 || j != 1) {
                //cout << (int)(a || i > (le[idx]-'0')) << " ";
                //cout << (int)(b || i < (re[idx]-'0')) << " ";
                //cout << (int)(c || j > (le[idx]-'0')) << " ";
                //cout << (int)(d || j < (re[idx]-'0')) << endl;
                r += solve(idx+1, a || i > (le[idx]-'0'), b || i < (re[idx]-'0'), c || j > (le[idx]-'0'), d || j < (re[idx]-'0'));
            }
        }
    }
    return r;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("test.txt","r",stdin);
    #endif
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&a[i].first,&a[i].second);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&d[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j]=(ll)(d[i]+d[j])*(abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second));
    priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>>q;
    ll ans = 0;
    for(int i=0;i<n;i++){
        q.push({b[i],{i,-1}});
    }
    while((int)calc.size()+(int)(calc2.size())<n){
        pair<ll,pair<int,int>> p = q.top();
        int u = p.second.first , v = p.second.second; 
        ll cst = p.first;
        q.pop();
        if(vis[u])
            continue;
        vis[u]=true;
        ans+=cst;
        if(v==-1){
            calc.push_back(u);
        }
        else    
            calc2.push_back({u,v});
        for(int i=0;i<n;i++){
            if(vis[i])
                continue;
            q.push({dist[u][i],{i,u}});
        }
    }

    printf("%lld\n",ans );
    printf("%d\n",(int)(calc.size()));

    for(auto x : calc)
        printf("%d ",x+1 );
    printf("\n%d\n",int(calc2.size()));
    for(auto p : calc2)
        printf("%d %d\n",p.first+1,p.second+1);
}
