#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define OnlineJudgeYourMomGay ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set(data_type) tree<data_type, null_type, less<data_type>,rb_tree_tag, tree_order_statistics_node_update>
#define scl(x) scanf("%lld",&x)
#define sc(x) scanf("%d"  ,&x)
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define F first
#define S second

using namespace __gnu_pbds;
using namespace std;

using ll  = long long;
using ld  = long double;
using ii = pair<int,int>;
const int N = 3e5 + 600;
const long long mod = 1e9 + 7;
const ll inf = LLONG_MAX;

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,-1,1};
void err(istream_iterator<string> it) {cerr << endl;}
template<typename T, typename... Args>void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}
ll sums() { return 0; }template<typename... Args>ll sums(ll a, Args... args) { return a + sums(args...); }
int Max(){return INT_MIN;}template<typename... Args>int Max(int a,Args... args){return max(a,Max(args...));}
int Min(){return INT_MAX;}template<typename... Args>int Min(int a,Args... args){return min(a,Min(args...));}
ll  gcd(){return 0;}template<typename... Args>ll gcd(ll a, Args... args){return __gcd(a,gcd(args...));}
template<typename T> void _R(T &x){ cin >> x;}
//void _R(int &x) { scanf("%d", &x); }
//void _R(ll &x) { scanf("%lld", &x); }
//void _R(double &x) { scanf("%lf", &x); }
//void _R(char &x) { scanf(" %c", &x); }
//void _R(char *x) { scanf("%s", x); }
void read(){}
template<typename T,typename... Args>void read(T &a, Args&... args){_R(a);read(args...);}


int main()
{
    int q;
    cin >> q;
    int n , arr[1006];
    while(q--){
            cin >> n;
            for(int i = 0; i < n; ++i)cin >> arr[i];
            sort(arr,arr + n);
            reverse(arr,arr + n);
            int ans = 1;
            for(int i = 0; i < n; ++i){
                ans = max(ans , min(i + 1,arr[i]));
            }
            cout << ans << '\n';
    }

    return 0;
}
