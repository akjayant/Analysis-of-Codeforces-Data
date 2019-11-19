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

int T,N;
string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int mx;
    cin>>T;
    while(T--)
    {
        cin>>N>>str;
        mx = 0;
        FOR(i,0,N-1)
        {
            if( str[i]=='1' )
            {
                mx = max( mx, max( i+1, N-i ) );
            }
        }
        if( !mx )cout<<N<<'\n';
        else cout<<mx*2<<'\n';
    }

    return 0;
}

