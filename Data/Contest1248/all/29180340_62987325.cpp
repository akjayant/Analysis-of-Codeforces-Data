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
    int n;
    cin>>n;
    ll ar[n], s=0;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        s+=ar[i];
    }
    sort(ar, ar+n);
    ll x=0;
    for(int i=0;i<n/2;i++)
    {
        x+=ar[i];
    }
    ll y=s-x;
    cout<<(x*x)+(y*y)<<endl;
}



