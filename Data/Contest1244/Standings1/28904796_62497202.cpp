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
int T[200005],K[200005],C[200005];
int main()
{
    speed
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        if(c=='W')
            T[i]=2;
        else
            T[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        C[i]=-1;
        int x=(i-1+n)%n,y=(i+1)%n;
        if(T[i]==T[x]||T[i]==T[y])
            K[i]=T[i],C[i]=0;
    }
    queue<int> Q;
    for(int i=0;i<n;i++)
        if(C[i]==0)
            Q.push(i);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        int x=(u-1+n)%n,y=(u+1)%n;
        if(C[x]==-1)
        {
            C[x]=C[u]+1;
            K[x]=K[u];
            Q.push(x);
        }
        if(C[y]==-1)
        {
            C[y]=C[u]+1;
            K[y]=K[u];
            Q.push(y);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(C[i]!=-1&&C[i]<=k)
        {
            if(K[i]==1)
                cout<<"B";
            else
                cout<<"W";
        }
        else
        {
            if(T[i]==1)
            {
                if(k%2==1)
                    cout<<"W";
                else
                    cout<<"B";
            }
            else
            {
                if(k%2==1)
                    cout<<"B";
                else
                    cout<<"W";
            }
        }
    }
    return 0;
}
