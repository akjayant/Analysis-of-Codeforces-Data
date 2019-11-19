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
const int N = 305001;

ll n , p , w , d;
map<ll,int> vis;
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    cin >> n >> p >> w >> d;
    ll x , y , z;
    x=y=z=0;
    for(ll i = 0 ; i < 10000000 ; i++){
        if((p-i*d)%w==0){
            if(i + ((p-i*d)/w) <=n && i*d <= p){
                cout << ((p-i*d)/w) << ' ' << i << ' ' << (n-i-((p-i*d)/w)) << endl;
                return 0;
            }
        }
    }
    return puts("-1");



    return 0;
}
