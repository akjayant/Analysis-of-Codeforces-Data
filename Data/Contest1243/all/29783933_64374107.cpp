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
#define FAST {ios::sync_with_stdio(0);cin.tie(0);cout<<setprecision(30)<<fixed;}
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

// Functions

// Main
int main() {
    #ifdef SEM_LOCAL
        ifstream cin("sis.txt");
        ofstream cout("val.txt");
    #endif
    FAST
    //
    int qq; cin >> qq;
    FOR(asdasdf,0,qq)
    {
        int n; cin >> n;
        vector<int> kek(n);
        FOR(i,0,n) cin >> kek[i];

        sort(all(kek));
        reverse(all(kek));

        int ans = 0;
        FOR(i,0,n)
        {
            ans = max(ans, min(i+1, kek[i]));
        }

        cout << ans << '\n';
    }
}
