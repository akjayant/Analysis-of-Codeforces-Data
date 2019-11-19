//Aleksander Łukasiewicz
#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int INF = 1000000009;

const int MAXN = 2000;

int n;
PII ver[MAXN + 3];
pair<pair<LL, int>, PII> tab[MAXN*MAXN + MAXN + 10];
int c[MAXN + 3], k[MAXN + 3];
LL ans;
vector<int> nodes;
vector<PII> edges;
int sets[MAXN + 3];
bool conn[MAXN + 3];


int Find(int x){
    if(sets[x] == x)
        return x;
    else
        return sets[x] = Find(sets[x]);
}

void Union(int x, int y){
    int fx = Find(x);
    int fy = Find(y);
    conn[fy] = (conn[fx] || conn[fy]);
    sets[fx] = fy;
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d %d", &ver[i].x, &ver[i].y);
    for(int i=1; i<=n; i++)
        scanf("%d", &c[i]);
    for(int i=1; i<=n; i++)
        scanf("%d", &k[i]);
    
    for(int i=1; i<=n; i++)
        sets[i] = i;
    
    int m = 0;
    for(int i=1; i<=n; i++)
        tab[m++] = mp(mp(c[i], 1), mp(i, 0));
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++){
            LL cost = (LL)(abs(ver[i].x - ver[j].x) + abs(ver[i].y - ver[j].y))*(LL)(k[i] + k[j]);
            tab[m++] = mp(mp(cost, 0), mp(i, j));
        }
    
    sort(tab, tab+m);
    for(int i=0; i<m; i++){
        if(tab[i].x.y == 0){//edge
            int u = tab[i].y.x;
            int v = tab[i].y.y;
            if((!conn[Find(u)] || !conn[Find(v)]) && Find(u) != Find(v)){
                Union(u, v);
                edges.pb(tab[i].y);
                ans += tab[i].x.x;
            }
        }
        else{//vertex
            int v = tab[i].y.x;
            if(!conn[Find(v)]){
                ans += tab[i].x.x;
                nodes.pb(v);
                conn[Find(v)] = true;
            }
        }
    }
    
    printf("%lld\n", ans);
    printf("%d\n", nodes.size());
    for(auto v : nodes)
        printf("%d ", v);
    puts("");
    printf("%d\n", edges.size());
    for(auto e : edges)
        printf("%d %d\n", e.x, e.y);
    
return 0;
}