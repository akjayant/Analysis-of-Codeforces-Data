#include <bits/stdc++.h>

using namespace std;

#define mx 2005
#define int long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define fi first
#define se second
#define mod 1000000007
#define inf 1e18+19
#define pb push_back
#define pi acos(-1)
#define si(x) scanf("%d", &x)
#define sil(x) scanf("%lld", &x)
#define sid(x) scanf("%lf", &x)
#define mem(ara, x) memset(ara, x, sizeof ara)
#define read() freopen("in.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define fst ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int x[mx], y[mx], k[mx], vis[mx], co[mx], id, mm, ara[mx], sz[mx];
vector <pii> e;
priority_queue <piii, vector <piii>, greater <piii> > q;
priority_queue <piii > q2;
vector <int> v;
set <pii> st;
set <int> g[mx];
set <int> :: iterator it2;;
set <pii> :: iterator it;

int concost(int i, int j){
    return (k[j] + k[i])*(llabs(x[i] - x[j]) + llabs(y[i] - y[j]));
}

void dfs(int u, int p){
    if(p==-1){
        id = u;
        mm = co[u-1];
    }
    if(mm > co[u-1]){
        id = u;
        mm = co[u-1];
    }
    if(vis[u]) {
        mm = 0;
        id = -1;
    }
    for(auto chi: g[u]){
        if(chi!=p){
            dfs(chi, u);
        }
    }
}

void initset(int n){
    for(int i = 1; i<=n; i++){
        ara[i] = i;
        sz[i] = 1;
    }
}

int findset(int i){
    if(ara[i] == i) return i;
    return ara[i] = findset(ara[i]);
}

bool issameset(int i, int j){
    return (findset(i)==findset(j));
}

void unionset(int i, int j){
    int a = findset(j);
    int b = findset(i);
    if(a==b) return;
    if(sz[a]>=sz[b]){
        sz[a]+=sz[b];
        ara[b] = a;
    }
    else{
        sz[b]+=sz[a];
        ara[a] = b;
    }
}

int32_t main(){
    //read();
    //write();
    fst;
    int n;
    while(cin >> n){
		mem(vis, 0);
		initset(n);
        for(int i=0;i<n;i++){
            cin >> x[i] >> y[i];
        }
        int m = inf, idx = -1;
        for(int i=0;i<n;i++){
            cin >> co[i];
            if(co[i] < m){
                m = co[i];
                idx = i+1;
            }
        }
        for(int i=0;i<n;i++){
            cin >> k[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i==j) continue;
                q.push(make_pair(concost(i, j), make_pair(i+1, j+1)));
            }
        }

        int ans = 0;
        while(!q.empty()){
            piii p = q.top();
            q.pop();
            if(!issameset(p.se.se, p.se.fi)){
                unionset(p.se.se, p.se.fi);
                q2.push(p);
                g[p.se.se].insert(p.se.fi);
                g[p.se.fi].insert(p.se.se);
                ans += p.fi;
            }
        }

        v.push_back(idx);
        ans += m;
        vis[idx] = 1;
        while(!q2.empty()){
            piii p = q2.top();
            q2.pop();

            int tmp;
            g[p.se.se].erase(p.se.fi);
            g[p.se.fi].erase(p.se.se);
            dfs(p.se.fi, -1);

            int a = mm;
            if(id!=-1) tmp = id;
            dfs(p.se.se, -1);

            int b = mm;
            if(id!=-1) tmp = id;

            if(a + b <= p.fi){
                ans -= p.fi;
                ans += a+b;
                vis[tmp] = 1;
                v.pb(tmp);
            }
            else{
                g[p.se.se].insert(p.se.fi);
                g[p.se.fi].insert(p.se.se);
                e.pb(p.se);
            }
        }
        cout << ans << endl;
        cout << ((int) (v.size())) << endl;
        for(auto u: v) cout << u << " ";
        cout << endl;
        v.clear();
        cout << ((int) (e.size())) << endl;
        for(auto u: e) cout << u.fi << " " << u.se << endl;
        cout << endl;
        e.clear();
        for(int i=1;i<=n;i++) g[i].clear();
    }
    return 0;
}










