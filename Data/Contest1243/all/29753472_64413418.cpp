#include<bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define per(a,b,c) for(int a=b;a>=c;a--)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
int n, m;

vector<int> g[N];
set<int> st1, st2;
set<int>::iterator it;
int vis[N];
int q[N];
void bfs(int s, int d){
    st1.clear(), st2.clear();
    rep(i,1,n) if(!vis[i] && i != s) st1.insert(i);
    int front, tail;
    front = tail = 0;
    q[tail++] = s; vis[s] = 1;
    while(front < tail){
        int u = q[front++];
        front %= N;
        int sz = g[u].size();
        for(int i = 0;i < sz; ++i){
            if(st1.count(g[u][i])){
                st1.erase(g[u][i]);
                st2.insert(g[u][i]);
            }
        }

        for(it = st1.begin(); it != st1.end();++it){
            q[tail++] = *it;
            tail %= N;
            vis[*it] = d;
        }
        st1.swap(st2);
        st2.clear();
    }
}

int main(){
    scanf("%d%d", &n, &m);
    int u, v;
    rep(i,1,m){
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    int d=1;
    rep(i,1,n) if(g[i].size() != n-1 && !vis[i]) bfs(i,d++);
    int ans = d-1, res = 0;
    rep(i,1,n){
        if(!vis[i]) res++;
    }
    ans += res-1;
    printf("%d\n", ans);
    return 0;
}

