#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
 
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
 
typedef long long ll;
typedef long double LD;
//#define int ll
#define double LD
#define pb push_back
#define mp make_pair
#define REP(i,n) for (int i = 0; i < n; i++)
#define loop(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define mem(a, b) memset(a, b, sizeof a)
#define append push_back
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define print(x) cout << (x) << endl
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const double PI=acos(-1);
const int MOD = 1000000007;
const int FMOD = 998244353;
const double eps = 1e-9;

mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count()); 
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers.
 
void solve();
 
signed main(){
    FAST_IO;
    PRECISION(10);
 
    int t = 1;
    cin>> t;
    FOR(testcase,1,t+1){
        // printf("Case #%lld: ",testcase); 
        solve();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}   
 
void solve(){
    int n;
    cin>> n;
    string s, t;
    cin>> s >> t;
    vector<pair<int, int> > ans;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){
            bool flag = false;
            for(int j = i + 1; j < n; j++){
                if(t[j] == s[i]){
                    swap(s[j], t[j]);
                    ans.pb(mp(j, j));
                    ans.pb(mp(j, i));
                    swap(s[j], t[i]);
                    flag = true;
                    break;
                }
                else if(s[i] == s[j]){
                    swap(s[j], t[i]);
                    ans.pb(mp(j, i));
                    flag = true;
                    break;
                }
            }
            if(!flag){
                cout<< "No" << endl;
                return;
            }
        }
    }
    cout<< "Yes" << endl;
    cout << ans.size() << endl;
    for(auto u : ans){
        cout<< u.F + 1 << ' ' << u.S + 1 << endl;
    }
}