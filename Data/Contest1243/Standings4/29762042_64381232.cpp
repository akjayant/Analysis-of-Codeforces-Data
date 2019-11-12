#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cstring>
#include <cassert>
 
#include <sstream>
#include <fstream>
#include <iostream>
#include <limits>
 
#include <stack>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;
 
#define mp make_pair
#define pb push_back
#define UNKNOWN -1
#define INF 1<<30LL
#define ff first
#define ss second
#define EPSILON 0.00000001
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repi(i, b, a) for(int i = (b) - 1; i >= (a); i--)
#define rp(i, a) rep(i, 0, a)
#define SET(x, a) memset((x), (a), sizeof(x))
#define ALL(vec) begin(vec), end(vec)
#define SORT(v) sort(ALL(v))
#define endl "\n"
#define SZ(v) int((v).size())
 
#define __DEBUG__
#ifdef __DEBUG__
    #define d(args...)  {cout << "> "; dbg,args; cout<<endl;}
#else
    #define d(args...)
#endif
#ifdef __DEBUG__
    #define dd(args...)  {dbg,args; cout << " ";}
#else
    #define dd(args...)
#endif
using namespace std;
 
//debugs everything
struct debugger{template<typename T> debugger& operator , (const T& v)
    {cout<<v<<" ";return *this;}}dbg;
 
 
typedef pair<int, int> ii;
typedef pair<int, ii> ip;
typedef pair<ii, int> pi;
typedef pair<ii, ii> pp;
typedef vector<ip> gip;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef pair<ll, ll> pll;
  

int main()
{
    int t;
    cin >> t;
    rp (i, t) {
        int n;
        cin >> n;
        string s, t;
        cin >> s;
        cin >> t;
        vi mis;
        rp (j, n) {
            if (s[j] != t[j]) mis.emplace_back(j);
        }
        int ss = mis.size();
        if (ss == 1 or ss > 2) cout << "NO\n";
        else if (ss == 0) cout << "YES\n";
        else {
            int ind1 = mis[0];
            int ind2 = mis[1];
            if (s[ind1] == s[ind2] and t[ind2] == t[ind1]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

