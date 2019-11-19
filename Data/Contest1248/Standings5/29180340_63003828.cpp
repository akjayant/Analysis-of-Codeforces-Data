#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define br cout<<endl;
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 100005;
const int INF = 1e9+7;
const ll LINF = 1e18 + 7;

/***************************************************************************/

int main()
{
    ios::sync_with_stdio(0);
    ll n, m;
    cin>>n>>m;
    ll a[MAX], b[MAX];
    a[1]=2;
    a[2]=4;
    a[3]=6;
    for(int i=4;i<=n;i++)
    {
        a[i]=((2*a[i-1])%INF-a[i-3])%INF;
    }
    b[1]=a[n];
    b[2]=(a[n]+2)%INF;
    b[3]=(a[n]+4)%INF;
    for(int i=4;i<=m;i++)
    {
       b[i]=((2*b[i-1])%INF-b[i-3])%INF;
    }
    if(b[m]<0)
        b[m]+=INF;
    cout<<b[m]<<endl;
    return 0;
}



