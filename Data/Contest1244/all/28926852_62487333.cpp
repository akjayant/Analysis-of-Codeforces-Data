//new.cpp
/*
Author : Hocky Yudhiono
Min 13 Okt 2019 04:56:50  WIB
Current Local Time : 16:56:50

getchar_unlocked > getchar > cin without sync > scanf > cin with sync
bool operator<(const MyStruct& rhs) const

On how to print Long Double to 5 decimal places :
printf("%.5Lf",ans);

On how to get random numbers :
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //For int
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); //For LL
cout << rng() << endl;
shuffle(isi.begin(),isi.end(),rng);
v.erase(unique(v.begin(),v.end()),v.end());

Don't forget to Modulo when you're doing rolling hash

__gcd(a,b)
__builtin_ffs(a) first on bit
__builtin_clz(a) count leading zero
__builtin_ctz(a) count trailing zero
__builtin_popcount(a) numbers of on bits

*/

//#include <unordered_map>
//#include <unordered_set>

//#include <random>
//#include <chrono>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

//using namespace __gnu_pbds;
using namespace std;

// #pragma comment(linker, "/stack:200000000")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<long long,long long> PLL;
// typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//If the time limit is strict, try not to use long double


#define fbo find_by_order
#define ook order_of_key
#define popf pop_front
#define pf push_front
#define popb pop_back
#define mp make_pair
#define pb push_back
#define remove erase
#define fi first
#define se second

//Remember to undefine if the problem is interactive
#define endl '\n'
#define DEBUG(X) cout << ">>> DEBUG(" << __LINE__ << ") " << #X << " = " << (X) << endl

const double eps = 1e-9;
const int INFMEM = 63;
const int INF = 1061109567;
const LL LINF = 4557430888798830399LL;
const double DINF = numeric_limits<double>::infinity();
const LL MOD = 1000000007;
const int dx[8] = {1,0,-1,0,1,1,-1,-1};
const int dy[8] = {0,1,0,-1,1,-1,1,-1};
const double PI = 3.141592653589793;

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
#define GETCHAR getchar_unlocked
inline void fastll(LL &input_number) 
{
    input_number = 0;
    int ch = GETCHAR();
    int sign = 1;
    while(ch < '0' || ch > '9'){
        if(ch == '-') sign=-1;
        ch = GETCHAR();
    }
    while(ch >= '0' && ch <= '9'){
        input_number = (input_number << 3)+(input_number << 1) + ch-'0';
        ch = GETCHAR();
    }
    input_number *= sign;
}

inline void open(string a){
    freopen((a+".in").c_str(),"r",stdin);
    freopen((a+".out").c_str(),"w",stdout);
}

inline void fasterios(){
    //Do not use if interactive
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

LL n;
LL ans[100005];
LL cost[4][100005];
LL memo[4][4][100005];
LL flatidx[100005];
LL realidx[100005];
vector <LL> edge[100005];

void dfs(LL pos, LL par){
    realidx[flatidx[pos]] = pos;
    for(int i = 0;i < edge[pos].size();i++){
        LL nx = edge[pos][i];
        if(nx == par) continue;
        flatidx[nx] = flatidx[pos]+1;
        dfs(nx,pos);
    }
    return;
}

void cant(){
    cout << -1 << endl;
    exit(0);
}

LL dp(LL a,LL b, LL pos){
    if(pos > n) return 0;
    LL &ret = memo[a][b][pos];
    if(ret != -1) return ret;
    bool sudah[4];
    memset(sudah,0,sizeof(sudah));
    sudah[a] = 1; sudah[b] = 1;
    ret = LINF;
    for(int i = 1;i <= 3;i++){
        if(sudah[i]) continue;
        ret = min(ret,dp(b,i,pos+1)+cost[i][realidx[pos]]);
    }
    return ret;
}

void backtrack(LL a, LL b, LL pos){
    if(pos > n) return;
    LL ret = dp(a,b,pos);
    bool sudah[4];
    memset(sudah,0,sizeof(sudah));
    sudah[a] = 1; sudah[b] = 1;
    for(int i = 1;i <= 3;i++){
        if(sudah[i]) continue;
        if(ret == dp(b,i,pos+1)+cost[i][realidx[pos]]){
            ans[realidx[pos]] = i;
            backtrack(b,i,pos+1);
            return;
        }
    }
}

int main(){
    fasterios();
    memset(memo,-1,sizeof(memo));
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> cost[1][i];
    for(int i = 1;i <= n;i++) cin >> cost[2][i];
    for(int i = 1;i <= n;i++) cin >> cost[3][i];
    for(int i = 1;i < n;i++){
        LL u,v; cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
    for(int i = 1;i <= n;i++){
        if(edge[i].size() > 2) cant();
    }
    for(int i = n;i >= 1;i--){
        if(edge[i].size() == 1){
            flatidx[i] = 1;
            dfs(i,-1);
            break;
        }
    }
    // for(int i = 1;i <= n;i++) cout << realidx[i] << " \n"[i == n];
    cout << dp(0,0,1) << endl;
    backtrack(0,0,1);
    for(int i = 1;i <= n;i++){
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}