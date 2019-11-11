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
ll MOD = 7 + (1e9);

// Functions
ll fib(ll n)
{
    ll a = 1;
    ll b = 1;
    ll c = 1;
    FOR(i,0,n)
    {
        c = a + b;
        c %= MOD;
        a = b;
        b = c;
    }
    return c;
}

// Main
int main() {
    //#ifdef SEM_LOCAL
    //    ifstream cin("tortsis.txt");
    //    ofstream cout("tortval.txt");
    //#endif
    FAST
    //
    ll ans = 1;
    string s; cin >> s; s.push_back(' ');
    int count = 0;

    FOR(i,0,s.size())
    {
        if (s[i] == 'u')
            count++;
        else
        {

            ans *= max(1ll,fib(count-1));
            ans %= MOD;
            count = 0;
        }
    }

    FOR(i,0,s.size())
    {
        if (s[i] == 'n')
            count++;
        else
        {

            ans *= max(1ll,fib(count-1));
            ans %= MOD;
            count = 0;
        }
    }

    FOR(i,0,s.size())
    {
        if (s[i] == 'm' || s[i] == 'w')
            ans = 0;
    }

    cout << ans % MOD;
}
