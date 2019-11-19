#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FOD(i,a,b) for(int i=(a);i>=(b);--i)
#define fs first
#define sc second

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int N=1e5+5;
int n;
int a[N];
int xx,yy;
ll ans;


int main()
{
    if (fopen("exam.inp","r"))
    {
        freopen("exam.inp","r",stdin);
        freopen("exam.out","w",stdout);
    }

    cin >> n;
    FOR(i,1,n) cin >> a[i];
    sort(a+1,a+n+1);
    xx=0;yy=0;
    int p=n/2;
    FOR(i,1,p) xx+=a[i];
    FOR(i,p+1,n) yy+=a[i];
    ans=1ll*xx*xx+1ll*yy*yy;
    cout << ans << endl;

    return 0;
}
