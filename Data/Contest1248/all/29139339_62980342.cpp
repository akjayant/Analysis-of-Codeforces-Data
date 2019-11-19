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

ll t,x,n,m,mark1[3],mark2[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();
    #ifndef ONLINE_JUDGE
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    #endif // ONLINE_JUDGE
    cin>>t;
    while (t--) {
        cin>>n;
        mark1[0]=mark2[0]=mark1[1]=mark2[1]=0;
        for (int i=1;i<=n;i++){
            cin>>x;
            mark1[x%2]++;
        }
        cin>>m;
        for (int i=1;i<=m;i++) {
            cin>>x;
            mark2[x%2]++;
        }
        long long res=mark1[1]*mark2[1]+mark1[0]*mark2[0];
        cout<<res<<"\n";
    }
    return 0;
}
