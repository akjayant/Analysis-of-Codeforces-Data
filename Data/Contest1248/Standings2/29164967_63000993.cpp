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

#define MXN 505
int N;
string str;

int cnt()
{
    int mxy = 0;
    int ynow = 0, ycnt = 0;
    FOR(i,0,N-1)
    {
        if( str[i]=='(' )
        {
            ynow--;
        }
        else
        {
            ynow++;
            if( ynow > mxy )
            {
                mxy = ynow;
                ycnt = 1;
            }
            else if( ynow==mxy )ycnt++;
        }
    }
    return ycnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>str;
    int lc=0;
    FOR(i,0,N-1)lc+=( str[i]=='(' );

    if( N%2 || lc!=N/2 )
    {
        cout<<0<<'\n';
        cout<<1<<' '<<1<<'\n';
        return 0;
    }
    int mx=0;
    pii mxp=mkp(1,1);

    FOR(i,1,N)FOR(j,i,N)
    {
        swap( str[i-1], str[j-1] );
        int res = cnt();
        if( res>mx )
        {
            mx = res;
            mxp = mkp( i,j );
        }
        swap( str[i-1], str[j-1] );
    }
    cout<<mx<<'\n';
    cout<<mxp.f<<' '<<mxp.s<<'\n';

    return 0;
}
