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
struct stk
{
    int sn = -1;
    int pos = -1;
};

bool operator< (stk a, stk b)
{
    if (a.sn == b.sn)
        return a.pos < b.pos;
    return a.sn < b.sn;
}

// Functions
vector<set<stk>> where;

// Main
int main() {
    #ifdef SEM_LOCAL
        ifstream cin("sis.txt");
        ofstream cout("val.txt");
    #endif
    FAST
    //
    ll n; cin >> n;

         if (n==1)
        cout << 1;
    else if (n==2)
        cout << 2;
    else if (n==3)
        cout << 3;
    else if (n==4)
        cout << 2;
    else if (n==5)
        cout << 5;
    else if (n==6)
        cout << 1;
    else if (n==7)
        cout << 7;
    else if (n==9)
        cout << 3;
    else {
        map<ll,ll> div;
        for(ll i = 2; i < 2e6; i++)
        {
            while (n%i == 0) {
                div[i]++;
                n /= i;
            }
        }
        if (n != 1)
        {
            div[n]++;
        }
    
        if (div.size() == 1)
        {
            for(auto a : div)
            {
                cout << a.first;
                break;
            }
        } else cout << '1';
    }
}
