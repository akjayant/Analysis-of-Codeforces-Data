#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define deci(n) cout << fixed << setprecision(n);
#define mk make_pair
#define pb push_back
#define pp(a, b) pair <a, b>
#define ll long long int
#define ld long double
#define all(a) a.begin(), a.end()
 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> T printr(T p){ cout << p << '\n'; return 0; }
template <class T> T printe(T p){ cout << p << '\n'; exit(0); }
template <class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template <class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
 
const ll INF = (ll)(8e18);
const ll MOD = 1e9 + 7;

int findMaxLen(string s, int n){ 
    if (s.length() <= 1) return 0; 
    vector<int> longest(s.size(), 0); 
    int val = 0;
    for (int i = 1; i < (int)s.length() - 1; i++) { 
        if (s[i] == ')' && i - longest[i - 1] - 1 >= 0 && 
            s[i - longest[i - 1] - 1] == '(') { 
                longest[i] = longest[i - 1] + 2 + ((i - longest[i - 1] - 2 >= 0) ? longest[i - longest[i - 1] - 2] : 0); 
                if(longest[i] >= n){
                    if(longest[i] == n) val++;
                    else if(longest[i - n] > 0) val++;
                }
        } 
    } 
    return val; 
} 

int main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0, l = 1, r = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            swap(s[i], s[j]);
            int val = findMaxLen(s + s, n);
            if(val > ans){
                ans = val;
                l = i + 1;
                r = j + 1;
            }
            swap(s[i], s[j]);
        }
    }
    cout << ans << '\n';
    cout << l << ' ' << r << '\n';
    #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}