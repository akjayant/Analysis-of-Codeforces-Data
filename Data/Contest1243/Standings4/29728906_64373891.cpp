#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;
#define ts(x)                       to_string(x)
#define ti(x)                       stoi(x)
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define mine(v)                     *min_element(all(v))
#define maxe(v)                     *max_element(all(v))
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define SIZE(x)                     (int)x.size()
#define endl                        "\n"
inline ll input(){ll n; cin >> n ; return n;}

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const ll INF = 8e18;

ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? (a * pw(a * a % MOD, b / 2)) % MOD : pw(a * a % MOD, b / 2))); }

int v[MAXN];

int main(){
    fast_io;
    //cout << fixed << setprecision(15);
    //scanf("%d %d %f %lld %s %c", &x);
    //printf("%d %d %f %lld %s %c", x);
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        int ans = 1;
        for(int i = 1; i <= n; i++){
            ll cnt = 0;
            for(int j = 0; j < n; j++){
                if(v[j] >= i){
                    cnt++;
                }
                if(cnt >= i){
                    ans = max(ans, i);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}


