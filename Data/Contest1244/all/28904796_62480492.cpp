#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//typedef tree < int , null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> TREE;
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define pss pair<short,short>
#define pld pair<long double,long double >
#define ld long double
#define piii  pair<pii,int>
#define vii vector<pair<int,int> >
#define st first
#define nd second
#define pll pair<ll,ll>
#define speed ios::sync_with_stdio(false);cin.tie();cout.tie();
#define M_PI 3.14159265358979323846
//#define int long long
const int mod=1000000007;
//const int mod=998244353;
const int inf=1000000009;
const long long INF=1000000000000000009;
const long long big=1000000000000000;
const long double eps=0.0000000001;
using namespace std;
int T[100005][4],K[100005],A[100005];
vi P[100005];
vi W;
void dfs(int n,int p)
{
    W.pb(n);
    for(auto v:P[n])
        if(v!=p)
            dfs(v,n);
}
ll funkcja(int a,int b,int n)
{
    K[1]=a,K[2]=b;
    ll wynik=0;
    wynik+=T[W[0]][a]+T[W[1]][b];
    for(int i=3; i<=n; i++)
    {
        if(K[i-1]!=1&&K[i-2]!=1)
        {
            wynik+=T[W[i-1]][1];
            K[i]=1;
        }
        if(K[i-1]!=2&&K[i-2]!=2)
        {
            wynik+=T[W[i-1]][2];
            K[i]=2;
        }
        if(K[i-1]!=3&&K[i-2]!=3)
        {
            wynik+=T[W[i-1]][3];
            K[i]=3;
        }
    }
    return wynik;
}
int main()
{
    speed
    int n;
    cin>>n;
    for(int i=1; i<=3; i++)
        for(int j=1; j<=n; j++)
            cin>>T[j][i];
    for(int i=1; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        P[a].pb(b);
        P[b].pb(a);
    }
    int k;
    for(int i=1; i<=n; i++)
    {
        if(P[i].size()>=3)
        {
            cout<<-1;
            return 0;
        }
        if(P[i].size()==1)
            k=i;
    }
    dfs(k,0);
    ll wynik=INF;
    pii skad=mp(-1,-1);
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
    {
        if(i==j)
            continue;
        ll x=funkcja(i,j,n);
        if(wynik>x)
        {
            wynik=x;
            skad=mp(i,j);
        }
    }
    funkcja(skad.st,skad.nd,n);
    cout<<wynik<<"\n";
    for(int i=1;i<=n;i++)
        A[W[i-1]]=K[i];
    for(int i=1;i<=n;i++)
        cout<<A[i]<<" ";
    return 0;
}
