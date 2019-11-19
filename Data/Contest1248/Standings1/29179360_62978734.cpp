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
#include <cmath>
#include <set>

// Variables

// Functions

// Main
int main()
{
#ifdef SEM_LOCAL
    ifstream cin("tortsis.txt");
    ofstream cout("tortval.txt");
#endif
    FAST
    //

    int q; cin >> q;
    FOR(tests,0,q)
    {
        ll n,m; cin >> n;
        vector<ll> data = {0,0,0,0};
        FOR(i,0,n)
        {
            ll t; cin >> t;
            data[t % 2]++;
        }
        cin >> m;
        FOR(i,0,m)
        {
            ll t; cin >> t;
            data[2 + (t % 2)]++;
        }

        ll ans = 0;
        ans += data[0] * data[2];
        ans += data[1] * data[3];
        cout << ans << '\n';
    }

}
