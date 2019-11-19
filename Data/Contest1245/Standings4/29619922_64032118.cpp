#include <bits/stdc++.h>
#define ENDL '\n'
#define F first
#define S second
#define PB push_back
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define FLOOR(a,b) (a-a%b) / b
#define NEXT(a) next_permutation(ALL(a))
#define T = 100000
#define N = 1000000000000000000
#define RANDOM(a) (rand()%a) + 1
#define TEST_CASES 20

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef unsigned long long int ulli;

lli MAX = 2005;

vector<lli> parent(MAX);
vector<bool> lit(MAX);

vector<lli> power(MAX);
vector<lli> km(MAX);

void make_set(lli u)
{
    parent[u] = u;
    lit[u] = false;
}

lli find_parent(lli u)
{
    if(u==parent[u])
        return u;
    parent[u] = find_parent(parent[u]);
    return parent[u];
}

bool same(lli u, lli v)
{
    return (find_parent(u)==find_parent(v));
}

bool littest(lli u, lli v)
{
    return (lit[find_parent(u)]&&lit[find_parent(v)]);
}

bool is_lit(lli u)
{
    return lit[find_parent(u)];
}

void litear(lli u)
{
    lit[find_parent(u)] = true;
}

void unite(lli u, lli v)
{
    u = find_parent(u);
    v = find_parent(v);
    parent[u] = v;
    lit[v] = lit[v]||lit[u];
    lit[u] = lit[v]||lit[u];
}

lli cost(pair<lli,lli> u, pair<lli,lli> v)
{
    pair<lli,lli> w = {abs(u.F-v.F),abs(u.S-v.S)};
    lli ans = (w.F+w.S);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    lli n;
    cin>>n;
    vector<pair<lli,lli>> coord(n+1);
    for(int i=1;i<=n;++i) make_set(i);
    for(int i=1;i<=n;++i)
        cin>>coord[i].F>>coord[i].S;
    for(int i=1;i<=n;++i)
        cin>>power[i];\
    for(int i=1;i<=n;++i)
        cin>>km[i];
    vector<pair<lli,pair<lli,lli>>> kruskal;
    for(int i=1;i<=n;++i)
    {
        kruskal.PB({power[i],{i,i}});
        for(int j=i+1;j<=n;++j)
            kruskal.PB({cost(coord[i],coord[j])*(km[i]+km[j]),{i,j}});
    }
    vector<lli> self;
    vector<pair<lli,lli>> nself;
    vector<lli> deb;
    sort(ALL(kruskal));
    lli total=0;
    for(auto it : kruskal)
    {
        lli u = it.S.F;
        lli v = it.S.S;
        lli c = it.F;
        if(u==v)
        {
            if(!is_lit(u))
            {
                total += c;
                litear(u);
                self.PB(u);
            }
            continue;
        }
        if(same(u,v) || littest(u,v))
            continue;
        unite(u,v);
        total += c;
        nself.PB({u,v});
        deb.PB(c);
    }
    cout<<total<<ENDL;
    cout<<self.size()<<ENDL;
        cout<<self[0];
        for(int i=1;i<self.size();++i)
            cout<<" "<<self[i];
        cout<<ENDL;
    cout<<nself.size()<<ENDL;
    for(int i=0;i<nself.size();++i)
        cout<<nself[i].F<<" "<<nself[i].S<<ENDL;
    return 0;
}








