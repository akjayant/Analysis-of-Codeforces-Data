#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // include pb_ds

using namespace std;
using namespace __gnu_pbds; // namespace for pb_ds

/* short forms */
#define Accelerate                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define cld(x, y) (((x) / (y)) + ((x) % (y) != 0)) //integer ceil division
#define tc(tt) \
    int tt;    \
    cin >> tt; \
    for (int _tt = 0; _tt < tt; _tt++) // testcase
#define all(cont) (cont).begin(), (cont).end()
#define sz(cont) (int)(cont).size()
#define endl '\n'
#define cout_p(x, p) cout << fixed << setprecision((p)) << x << endl //print with precision
#define dbg(x) cerr << #x << "is" << (x) << endl
#define leadzero(a) __builtin_clz(a)      // count leading zeroes
#define trailzero(a) __builtin_ctz(a)     // count trailing zeroes
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)

/* constants */
const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;

/* typedefs */
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;
typedef priority_queue<int, vector<int>> max_heap;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
    indexed_set; // integer set with indexing / pb_ds


/* main program */
int main()
{
    Accelerate;
    tc(tt) {
       int n;
       cin >> n;
       string s;
       cin >> s;
       int maxx = n;
       for(int i=0;i<n;i++) {
           if(s[i]=='1') {
               maxx = max({maxx,2*(i+1),2*(n-i)});
           }
       }
       cout << maxx << endl;
    }
    return 0;
}
