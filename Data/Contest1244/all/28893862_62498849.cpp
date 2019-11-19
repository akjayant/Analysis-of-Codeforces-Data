#include <bits/stdc++.h>
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define setDP(arr) memset(arr,-1,sizeof arr)
#define oo 2000000000
#define inf 1000000000000000LL
#define M 1000000007
typedef long long ll;
using namespace std;
const int N = 1050001;

ll n , k;
int p[N],q[N];
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    cin >> n >> k ;
    if(k<(n*(n+1)*0.5)){
        return puts("-1");
    }
    for(int i = 1 ; i <= n ; i++)p[i]=q[i]=i;
    ll ans = n*(n+1)>>1;
    for(int i = 1, j = n ; i <= n && i<j ; i++){
        if(ans+j-i<=k){
            ans+=j;
            ans-=i;
            swap(p[i],p[j]);
            j--;

        }
    }
    cout << ans << endl;
    for(int i = 1 ; i <= n ; i++){
        printf("%d ",p[i]);
    }
    puts("");
    for(int i = 1 ; i <= n ; i++){
        printf("%d ",q[i]);
    }
    puts("");




    return 0;
}
