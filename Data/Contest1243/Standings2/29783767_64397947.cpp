#pragma GCC optimize ("unroll-loops", "no-stack-protector", "O3")
#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define forout(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define F first
#define S second
typedef long long ll;
using namespace std;
const int N = (int)1e5 + 5;
int fa[N], visit[N], cc[N], n, m, d = 0, cnt = 0;
vector<int> ke[N], group[N];
vector<pair<int,int> > E;
inline int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
inline void bfs(int s)
{
    static queue<int> q;
    q.push(s);
    fa[s] = find(s + 1);
    group[cnt].push_back(s);
    cc[s] = cnt;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        forv(v,ke[x])
            visit[v] = x;
        for(int i = find(1) ; i <= n ; i = find(i + 1))
        {
            if(visit[i] != x)
                fa[i] = find(i + 1), q.push(i), group[cnt].push_back(i), cc[i] = cnt;
        }
    }
    ++cnt;
}
string s[N];
inline void upd(int i, char c, int id)
{
    forv(j,group[i])
        s[id][j - 1] = c;
};
inline void gett2(int x, int id)
{
    d = max(id, d);
    if(x == 1 || x == 2)
        return;
    gett2(x / 2, id + 1);
    gett2(x - x / 2, id + 1);
}
inline void gett(int j, int x, int id)
{
    if(x == 1)
    {
        /*
        for(int i = id + 1 ; i < d ; ++i) upd(j, '0', i);
        */
    }
    else if(x == 2)
    {
        //upd(j, '0', id);
        upd(j + 1, '1', id);
    }
    else
    {
        int xx = x / 2;
        //for(int i = 0 ; i < xx ; ++i)
        forinc(i,xx,x-1)
            upd(j + i, '1', id);
        gett(j, xx, id + 1);
        gett(j + xx, x - xx, id + 1);
    }
}

void init()
{
    cin >> n >> m;
    forinc(i,0,m-1)
    {
        int a, b;
        cin >> a >> b;
        ke[a].push_back(b);
        ke[b].push_back(a);
        E.emplace_back(a, b);
    }
   forinc(i,1,n+1)
        fa[i] = i;
}
void solve()
{
    for(int i = 1 ; i <= n ; i = find(i + 1))
        bfs(i);
    gett2(cnt, 0);
    d++;
    forinc(i,0,n-1)
        s[0].push_back('0');
    forinc(i,0,d-1)
        s[i] = s[0];
    gett(0, cnt, 0);
    cout<<cnt-1<<"\n";
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int hameto=1;
    if(hameto==24)
        cerr<<"GOLDEN IOI";
    int hametoo=3;
    if(hametoo==4) cerr<<"GOLDEN IOI";
    init();
    solve();
}
