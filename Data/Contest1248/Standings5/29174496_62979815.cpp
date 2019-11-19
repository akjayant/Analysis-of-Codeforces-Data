#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FOD(i,a,b) for(int i=(a);i>=(b);--i)
#define fs first
#define sc second

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int N=1e5+5;
int tc,n,m;
int a[N];
int b[N];
int d1,d2;
ll ans;


int main()
{
    if (fopen("exam.inp","r"))
    {
        freopen("exam.inp","r",stdin);
        freopen("exam.out","w",stdout);
    }

    scanf("%d",&tc);
    while (tc--)
    {
        cin >> n;
        d1=0;
        d2=0;
        FOR(i,1,n)
        {
            cin >> a[i];
            if (a[i]%2==0) ++d1;
            else ++d2;
        }
        cin >> m;
        ans=0;
        FOR(i,1,m)
        {
            cin >> b[i];
            if (b[i]%2==0)
            {
                ans=ans+1ll*d1;
            }
            else ans=ans+1ll*d2;
        }
        cout << ans << endl;
    }


    return 0;
}
