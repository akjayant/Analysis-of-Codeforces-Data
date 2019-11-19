

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
deque<int> K[4][100005];
map<pii,int> M;
bool cmp(int a,int b)
{
    return a>b;
}
bool czy=false;
bool check(int x1,int x2,int y1,int y2)
{
    // cout<<"check "<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
    if(x1>x2||y1>y2)
        return false;
    for(int i=x1; i<=x2; i++)
        for(int j=y1; j<=y2; j++)
            if(!M[mp(i,j)])
            {
                czy=true;
                return true;
            }
    return false;
}
void funkcja(int x1,int x2,int y1,int y2)
{
    //  cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
    if(x1>x2||y1>y2)
        return;
    if(czy)
        return;
    for(auto v:K[0][x1])
    {
        if(v<y1)
        {
            K[0][x1].pop_front();
            continue;
        }
        if(v>y2)
            break;

        //cout<<"jeden"<<endl;
        if(check(x1,x2,v,y2))
            return;
        else
        {
            y2=v-1;
            break;
        }

    }
    if(y2>=y1)
    {
        for(auto v:K[1][y2])
        {
            //  cout<<"dwa"<<endl;
            if(v<x1)
            {
                K[1][y2].pop_front();
                continue;
            }
            if(v>x2)
                break;
            if(check(v,x2,y1,y2))
                return;
            else
            {
                x2=v-1;
                break;
            }

        }
    }
    if(x2>x1)
    {
        for(auto v:K[2][x2])
        {
            //cout<<"trzy"<<endl;
            if(v>y2)
            {
                K[2][x2].pop_front();
                continue;
            }
            if(v<y1)
                break;
            if(check(x1+1,x2,y1,v))
                return;
            else
            {
                y1=v+1;
                break;
            }

        }
    }
    if(y2>y1)
    {
        for(auto v:K[3][y1])
        {
            // cout<<"cztery"<<endl;
            if(v>x2)
            {
                K[3][y1].pop_front();
                continue;
            }
            if(v<x1)
                break;
            if(check(x1+1,v,y1,y2-1))
                return;
            else
            {
                x1=v;
                break;
            }

        }
    }
    funkcja(x1+1,x2-1,y1+1,y2-1);
}
int main()
{
    speed
    int n,m,k;
    cin>>n>>m>>k;
    // cout<<"ZYJE"<<endl;
    for(int i=1; i<=k; i++)
    {
        int a,b;
        cin>>a>>b;
        M[mp(a,b)]=1;
        K[0][a].pb(b);
        K[2][a].pb(b);
        K[1][b].pb(a);
        K[3][b].pb(a);
    }
    // cout<<"ZYJE"<<endl;
    for(int i=1; i<=n; i++)
    {
        // cout<<i<<endl;
        sort(K[0][i].begin(),K[0][i].end());
        sort(K[2][i].begin(),K[2][i].end(),cmp);
    }
    //cout<<"ZYJE"<<endl;
    for(int i=1; i<=m; i++)
    {
        sort(K[1][i].begin(),K[1][i].end());
        sort(K[3][i].begin(),K[3][i].end(),cmp);
    }
    // cout<<"ZYJE"<<endl;
    funkcja(1,n,1,m);
    //cout<<"ZYJE"<<endl;
    if(czy)
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}
