// I am grateful to everyone who taught or motivated me to code.
// Without your support, nothing would have been done.
using namespace std;
#include <iomanip>
#include <iostream>
#include <fstream>
#ifdef SEM_LOCAL
bool DEBUG = true;
#else
bool DEBUG = false;
#endif
#define FAST {ios::sync_with_stdio(0);cin.tie(0);cout<<setprecision(10)<<fixed;}
#define FOR(a,b,c) for(int a=(b); a<(int)(c); ++a)
#define DB(a) if(DEBUG) cerr<<#a<<" "<<a<< "\n";
#define all(v) (v).begin(),(v).end()
using ll = long long;
using ull = unsigned long long;
int MAXINT=2e9;
ll MAXLL=9e18;

// Includes
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

// Variables
ll mod = (1e9) + 7;

// Functions
ll fib(ll n)
{
    ll pans = 0;
    ll ans = 1;
    FOR(i,0,n)
    {
        ll t = ans;
        ans = pans + ans;
        pans = t;
        
        ans %= mod;
        pans %= mod;
    }
    return ans;
}

// Main
int main() {
#ifdef SEM_LOCAL
    ifstream cin("tortsis.txt");
    ofstream cout("tortval.txt");
#endif
    FAST
    //


    ll a,b; cin >> a >> b;
    cout << (2 * (fib(a ) + fib(b) - 1 + mod)) % mod;


}
