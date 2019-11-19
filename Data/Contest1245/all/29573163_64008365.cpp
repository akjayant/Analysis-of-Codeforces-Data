// Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>

using namespace std;

#define double long double
#define Long long long
#define EPS 1e-12
#define PI acos(-1.0)

#define MAX 500000
#define MOD 1000000007

#define POS_INF (1LL << 60)
#define NEG_INF (-(1LL << 60))

#define RIGHT_MOST_INDEX (1 << 30)
#define LEFT_MOST_INDEX (-(1 << 30))

#define MEMSET(x,y) memset(x, y, sizeof(x))
#define PB push_back
#define MP make_pair
#define SORT(A) sort(A.begin(), A.end());
#define REVERSE(A) reverse(A.begin(), A.end());

struct edge
{
    int u, v;
    Long w;
    bool operator < ( const edge& p ) const
    {
        return w < p.w;
    }
};

int par[MAX+9];
vector<edge> EDGE_LIST, EDGE_LIST_Y;
vector<pair<int, int> >ANS;

int find_parent(int r)
{
    if(par[r] != r) par[r] = find_parent(par[r]);
    return par[r];
}

void init_mst_kruskal(int n)
{
    int i;
    for(i = 0; i <= n + 5; i++)  par[i] = i;
    EDGE_LIST.clear();
}

Long mst(int n)
{
    int i, j, u, v, siz, node_count;
    Long mst_length;

    mst_length = 0;
    node_count = 0;
    if(node_count == n - 1) return mst_length;

    sort(EDGE_LIST.begin(),EDGE_LIST.end());

    siz = EDGE_LIST.size();
    for(i = 0; i < siz; i++)
    {
        u = find_parent(EDGE_LIST[i].u);
        v = find_parent(EDGE_LIST[i].v);

        if(u != v)
        {
            par[u] = v;
            node_count++;
            mst_length += EDGE_LIST[i].w;

            ANS.PB(MP(EDGE_LIST[i].u, EDGE_LIST[i].v));
        }

        if(node_count == n - 1) return mst_length;
    }

    return POS_INF;
}

Long X[MAX+9];
Long Y[MAX+9];
Long K[MAX+9];
Long C[MAX+9];

int main()
{
    Long i,j,k,l,n,m,ans;

    cin>>n;
    for(i=1; i<=n; i++) cin>>X[i]>>Y[i];
    for(i=1; i<=n; i++) cin>>C[i];
    for(i=1; i<=n; i++) cin>>K[i];

    for(i=1; i<=n; i++)
    {
        edge aa;
        aa.u = n+1;
        aa.v = i;
        aa.w = C[i];

        EDGE_LIST.PB(aa);
    }

    for(i=1; i<=n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            edge aa;
            aa.u = i;
            aa.v = j;
            aa.w = ((abs(X[i] - X[j]) + abs(Y[i] - Y[j])) * (K[i] + K[j]));

            EDGE_LIST.PB(aa);
        }
    }

    EDGE_LIST_Y = EDGE_LIST;
    n++;
    init_mst_kruskal(n);

    EDGE_LIST = EDGE_LIST_Y;
    cout<<mst(n)<<endl;

    ans = 0;
    for(i=0; i<ANS.size(); i++) if(ANS[i].first == n || ANS[i].second == n) ans++;

    cout<<ans<<endl;
    for(i=0; i<ANS.size(); i++)
    {
        if(ANS[i].first == n || ANS[i].second == n)
        {
            cout<<min(ANS[i].first, ANS[i].second)<<" ";
        }
    }

    cout<<endl;

    ans = 0;
    for(i=0; i<ANS.size(); i++) if(ANS[i].first != n && ANS[i].second != n) ans++;

    cout<<ans<<endl;
    for(i=0; i<ANS.size(); i++)
    {
        if(ANS[i].first != n && ANS[i].second != n)
        {
            cout<<ANS[i].first<<" "<<ANS[i].second<<"\n";
        }
    }

    cout<<endl;

}
