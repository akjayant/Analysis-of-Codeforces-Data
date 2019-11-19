#include <bits/stdc++.h>

using namespace std;

#define mx 100005
//#define int long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define fi first
#define se second
#define mod 1000000007
#define inf 1e18+19
#define pb push_back
#define si(x) scanf("%lld", &x)
#define mem(ara, x) memset(ara, x, sizeof ara)
#define read() freopen("in.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define fst ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

set <int> s, g[mx];
set <int> :: iterator it;
int ara[mx], sz[mx], vis[mx];

void initset(int n){
    for(int i = 1; i<=n; i++){
        ara[i] = i;
        sz[i] = 1;
        vis[i] = 0;
        g[i].clear();
    }
    s.clear();
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

vector <int> v;
priority_queue <pii, vector <pii>, greater <pii> > pq;


int32_t main(){
    //read();
    fst;
    int n, m;
    while(cin >> n >> m){
        initset(n);
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            g[a].insert(b);
            g[b].insert(a);
        }
        for(int i=1;i<=n;i++){
            s.insert(i);
            int l = g[i].size();
            pq.push({l, i});
        }
        while(!pq.empty()){
            pii p = pq.top();
            pq.pop();

            if(vis[p.se]) continue;
            queue <int> q;
            q.push(p.se);

            while(!q.empty()){
                int a = q.front();
                q.pop();

                if(vis[a]) continue;
                vis[a] = 1;

                for(it=s.begin();it!=s.end();it++){
                    if(g[a].count(*it) == 0){
                        if(!issameset(a, *it)){
                            unionset(a, *it);
                            v.pb(*it);
                            q.push(*it);
                        }
                    }
                }
                for(auto u: v) s.erase(u);
                v.clear();
            }
        }
        mem(vis, 0);
        int ans = 0;
        for(int i=1;i<=n;i++){
            int a = findset(i);
            if(!vis[a]){
                ans++;
                vis[a] = 1;
            }
        }
        cout << ans - 1 << endl;
    }
    return 0;
}















