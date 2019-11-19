#include <bits/stdc++.h>
#define ff first
#define ss second
#define endl '\n'
using namespace std;
const long long INF = (long long) 1e18;
const int mod = (int) 1e9+7;
const int MAXN = (int) 3e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll t, n;
string s;
void solve(){
    cin>>n>>s;
    ll fr = -1, sc = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            fr = i;
            break;
        }
    }
    for(int i = n  -1; i >= 0; i--){
        if(s[i] == '1'){
            sc = i;
            break;
        }
    }
    if(fr == -1){
        cout<<n<<endl;
    }else{
        ll ans = max(n, (sc - fr + 1)*2 + 2*max(n - 1 - sc, fr));
        cout<<ans<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    #ifdef Local
        freopen("../IO/int.txt","r",stdin);
        freopen("../IO/out.txt","w",stdout);
    #endif

    cin>>t;

    while(t--){
        solve();
    }

    #ifdef Local
        cout<<endl<<fixed<<setprecision(2)<<1000.0 * clock() / CLOCKS_PER_SEC<< " milliseconds ";
    #endif
}