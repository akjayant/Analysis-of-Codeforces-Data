#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ppi pair<pii,int>
#define pip pair<int,pii>
#define pdd pair<double, double>
#define f first
#define s second
#define MOD 1000000007
#define mkp make_pair
#define M_PI 3.14159265358979323846
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define LOR(i,l,r) for (ll i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define LORD(i,r,l) for (ll i=r;i>=l;i--)
#define INF 1000000000
#define CL(x) memset(x,0,sizeof(x))
#define DEB(x) cout << #x << " : " << x << '\n'
#define ALL(x) x.begin(), x.end()
#define SZ(x) x.size()
#define UI(x) (int)(x-'A')
#define LI(x) (int)(x-'a')
#define lc(x) x*2
#define rc(x) x*2+1
typedef long long ll;

#define MXN 100005
int N;
vector<int> G[MXN];
ll A[MXN][3];
ll mn = (1LL<<60);
vector<int> V;
int C[MXN], MC[MXN];

void dfs(int u, int p)
{
    V.pb(u);
    for(int v : G[u])if(v!=p)dfs(v, u);
}

void recur(int i, ll now)
{
    if(i==N)
    {
        if( now<mn )
        {
            FOR(j,0,N-1)MC[ V[j] ] = C[j];
            mn = now;
        }
        return;
    }
    int u = V[i];
    C[i] = 3-C[i-1]-C[i-2];
    now+=A[u][ C[i] ];
    recur( i+1, now );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    FOR(i,1,N)cin>>A[i][0];
    FOR(i,1,N)cin>>A[i][1];
    FOR(i,1,N)cin>>A[i][2];

    int u,v;
    FOR(i,1,N-1)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    FOR(i,1,N)if( SZ(G[i])>2 )
    {
        cout<<-1<<'\n';
        return 0;
    }
    int fs;
    FOR(i,1,N)
    {
        if( SZ(G[i])==1 )
        {
            fs = i;
            break;
        }
    }
    dfs(fs, -1);

    FOR(i,0,2)
    {
        C[0] = i;
        FOR(j,0,2)
        {
            if(i==j)continue;
            C[1] = j;
            recur(2, A[ V[0] ][i]+A[ V[1] ][j]);
        }
    }

    cout<<mn<<'\n';
    FOR(i,1,N)cout<<MC[i]+1<<' ';
    cout<<'\n';

    return 0;
}

