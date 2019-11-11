//new.cpp
/*
Author : Hocky Yudhiono
Jum 01 Nov 2019 09:36:00  WIB
Current Local Time : 21:36:00

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

LL t; 

int main(){
    cin >> t;
    while(t--){
        LL a,b;
        cin >> a >> b;
        if(__gcd(a,b) != 1) cout << "Infinite" << endl;
        else cout << "Finite" << endl;
    }
    return 0;
}