#include <bits/stdc++.h>
#define mx 100007
using namespace std;

vector<int> adj[100007], con;
set<int> unv,unv2;
set<int> ::iterator it;
int cnt,n,m,k;

int par[mx], Size[mx];

struct edge
{
    int u, v;
};
vector<edge>vv;

void init( int n )
{
    for( int i=0; i<=n; i++ )
        par[i]= i, Size[i]= 1;
}

int Find( int u )
{
    if( par[u]==u )
        return u;
    return par[u]= Find( par[u] );
}

void unite( int u, int v )
{
    int paru= Find( u );
    int parv= Find( v );

    if( paru!=parv )
    {
        if( Size[paru]>Size[parv] )
            par[parv]= paru, Size[paru]+= Size[parv];
        else
            par[paru]= parv, Size[parv]+= Size[paru];
    }
}

void bfs( int x )
{
    unv.erase(x);
    queue<int>q;
    q.push(x);

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        vector<int> temp;

        for( it= unv.begin(); it!=unv.end(); it++ )
        {
            int v= (*it);

            if( !binary_search( adj[u].begin(),adj[u].end(),v ) )
            {
                temp.push_back(v);
                q.push(v);
                unite( u,v );
            }
        }

        for(int i=0; i<temp.size(); i++)
            unv.erase(temp[i]);
    }
}


int main()
{
    scanf("%d %d", &n, &m);

    init(n);

    for( int i=0;i<m;i++ )
    {
        int p,q;
        scanf("%d %d", &p,&q);

        adj[p].push_back(q);
        adj[q].push_back(p);

        edge ee;
        ee.u= p;
        ee.v= q;

        vv.push_back(ee);
    }

    for(int i=1; i<=n; i++)
        unv.insert(i),
        sort( adj[i].begin(), adj[i].end() );

    for( int i=1; i<=n; i++ )
    {
        if( unv.find(i)==unv.end() )
            continue;

        bfs(i);
    }

    int ans= 0;

    for( int i=0;i<m;i++ )
    {
        int u= vv[i].u;
        int v= vv[i].v;

        if( Find(u)!=Find(v) )
            unite( u,v ), ans++;
    }

    printf("%d\n", ans);
}
