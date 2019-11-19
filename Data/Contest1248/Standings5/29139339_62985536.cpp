#include <bits/stdc++.h>
#define N 100005
#define task "t"
#define mu(x) x*x
#define sz size

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using piii=pair<int,pii>;
const int inf=1e9+7;

ll n,a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();
    #ifndef ONLINE_JUDGE
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    #endif // ONLINE_JUDGE
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long j=n,x=0,y=0,ok=1;
    for (int i=1;i<=j;) {
        if (ok) x+=a[j],j--;
        else y+=a[i],i++;
        ok^=1;
    }
    cout<<(ll) x*x+y*y;
    return 0;
}
