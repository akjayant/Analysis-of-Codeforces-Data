#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2000+5;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1e9+7;

int pre[maxn];
inline void init(int N){
    for(int i = 0; i <= N; i++) pre[i] = i;
}
inline int Find(int x){
    return x == pre[x] ? x : pre[x] = Find(pre[x]);
}
inline void join(int x, int y){
    pre[Find(x)] = Find(y);
}

int n;
int x[maxn], y[maxn];
int c[maxn], k[maxn];

int gethas(int u, int v){
    return u*(n+1) + v;
}
inline void gethas(int has, int &u, int &v){
    u = has/(n+1); v = has%(n+1);
}
int main(){
    init(maxn-1);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &y[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &k[i]);
    typedef pair<ll,int> P;
    priority_queue<P, vector<P>, greater<P> > que;
    for(int i = 1; i <= n; i++){
        que.push(P(1ll*c[i], gethas(0, i)));
        for(int j = i+1; j <= n; j++){
            ll cost = 1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
            que.push(P(cost, gethas(i, j)));
        }
    }
    int u, v;
    ll ans = 0ll;
    vector<int> v0;
    vector<P> ve;
    while(que.size()){
        gethas(que.top().second, u, v);
        if(Find(u) == Find(v)) {
            que.pop(); continue;
        }else{
            ans += que.top().first; que.pop();
            join(u, v);
            if(u) ve.push_back(P(u, v));
            else v0.push_back(v);
        }
    }
    printf("%lld\n", ans);
    printf("%d\n", v0.size());
    for(int &i:v0) printf("%d ", i); puts("");
    printf("%d\n", ve.size());
    for(P &p:ve){
        printf("%lld %d\n", p.first, p.second);
    }
	return 0;
}
