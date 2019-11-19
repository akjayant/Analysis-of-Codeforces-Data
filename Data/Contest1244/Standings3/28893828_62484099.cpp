#include <bits/stdc++.h>

#define task "C"
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define pb push_back
#define F first
#define S second

using ll = long long ;
using ld = long double;
using ull = unsigned long long ;

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int N=1e5+3;

ll nn,p,d,w;
ll x,y,t=0;

int main()
{
    //freopen(task".in","r",stdin);
    //freopen(task".out","w",stdout);
    cin >> nn >> p >> w >> d;
    ll chekcp=p%d,checkw=w%d;
    rep(i,0,d-1)
    {
        if(chekcp!=(i*checkw)%d) continue;
        rep(j,0,3) t++;
        ll X=p/w; X=i+(X/d)*d;
        if(X*w>p) X-=d;
        if(X<0) continue;
        rep(j,1,4) t++;
        if (t<0) continue;
        ll Y=(p - X * w ) / d;
        if(X + Y > nn) continue;
        cout<< X << ' ' << Y << ' ' << nn-X-Y;
        return 0;
    }
    cout << -1;
    return 0;
}
