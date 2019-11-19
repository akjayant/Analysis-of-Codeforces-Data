#include <bits/stdc++.h>

using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//
//using namespace __gnu_pbds;
//template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//class Timer {
//    clock_t start;
//    string name;
//public:
//    Timer() {name = "";start = clock();}
//    Timer(string s){name = s;start = clock();}
//    ~Timer() {fprintf(stderr, "%s: %.3gs\n", name.c_str(), 1.0*(clock() - start) / CLOCKS_PER_SEC);}
//};

//#define isValid(a, b) ((a) >= 0 && (a) < (b))
//int dr[]  =  {0, -1, -1, -1,  0,  1, 1, 1};
//int dc[]  =  {1,  1,  0, -1, -1, -1, 0, 1};

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define um unordered_map
#define us unordered_set
#define endl '\n'
#define what_is(x) cerr << fixed << setprecision(2) << boolalpha << #x << " = " << x << endl

const double EPS = 1e-9;
const double PI = acos(-1.0);

template<typename T> inline T sq(T a){return a*a;}
template<typename T1, typename T2> inline pair<T1, T2> mp(T1 a, T2 b){return make_pair(a, b);}
template<typename T1, typename T2> inline T1 safeMod(T1 a, T2 m){return (a%m + m)%m;}/*handling negative sign of remainder*/
template<typename T1, typename T2> inline bool isEq(T1 a, T2 b){return abs(a - b) < EPS;}
template<typename T1, typename T2, typename T3> inline bool isEq(T1 a, T2 b, T3 eps){return abs(a - b) < eps;}
template<typename T> inline bool isKthBitOn(T n, int k){assert(n <= numeric_limits<T>::max());assert(k<=numeric_limits<T>::digits);T ONE = 1;return bool((n & (ONE<<k)));}
template<typename T> inline void setKthBit(T& n, int k){assert(n <= numeric_limits<T>::max());assert(k<=numeric_limits<T>::digits);T ONE = 1;n = (n|(ONE<<k));}
//mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
//template<typename T> inline T nextRand(T lo, T hi){return uniform_int_distribution<T>(lo, hi)(rng);}

#define toRad(deg) ((deg)*PI/180.0)
#define toDeg(rad) ((rad)*180.0/PI)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const int MAX = 100010;
const int MOD = 1000000007;
const int precision = 10;

int ara[MAX];
int findrep(int n)
{
    if(n==ara[n])return n;
    return ara[n] = findrep(ara[n]);
}

bool sameSet(int u, int v)
{
    return findrep(u) == findrep(v);
}

set<int>graph[MAX];
bool vis[MAX];
set<int>rem;
void dfs(int u)
{
    vis[u] = true;
    rem.erase(u);
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
        vector<int>del;
        for(int x:rem){
            if(graph[u].count(x) == 0 && !sameSet(u, x)){
                ara[x] = u;
                vis[x] = true;
                del.pb(x);
                q.push(x);
            }
        }
        for(int x:del)rem.erase(x);
    }
}

int main()
{
    //assert(freopen("in.txt", "r", stdin));
    //assert(freopen("out.txt", "w", stdout));
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //cout << fixed << setprecision(precision);
    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    for(int i = 1; i <= n; i++){
        ara[i] = i;
        rem.insert(i);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i])dfs(i);
    }
    int cnt = 0;
    vector<int>reps;
    for(int i = 1; i <= n; i++){
        if(i == findrep(i)){
            cnt++;
            reps.pb(i);
        }
    }
    cout << max(cnt-1, 0) << endl;
//    cnt = 0;
//    for(int i = 1; i < reps.size(); i++){
//        if(graph[reps[i-1]].count(reps[i])){
//            cnt++;
//        }
//    }
//    cout << cnt << endl;
    return 0;
}
