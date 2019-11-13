#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef unsigned long long ull;
typedef long long ll;
typedef double db;

#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define pi pair<int,int>
#define vi vector<int>
#define pL pair<ll,ll>
#define vL vector<ll>
#define vp vector<pi>
#define vpL vector<pL>

const int MX=300;
const ll inf=1e18;
const ll mod=1e9+7;

int g[MX+5][MX+5];

int main()
{
    FasterIO;
    int n;
    cin>>n;
    int c=1, x=1;
    while(x<=n*n)
    {
        if(c&1)
        {
            for(int i=1; i<=n; i++)
            {
                g[i][c]=x++;
            }
        }
        else
        {
            for(int i=n; i>=1; i--)
            {
                g[i][c]=x++;
            }
        }
        c++;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) cout<<g[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
