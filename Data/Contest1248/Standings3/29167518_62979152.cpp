#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <iomanip>

#define ll long long

#define FOR(i,a,b)        for(ll i=(a);i<(b);i++)
#define REP(i,n)        FOR(i,0,n)
#define SORT(v)            sort((v).begin(),(v).end())
#define UN(v)            SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)            memset(a,b,sizeof a)
#define pb                push_back

using namespace std;

//#define N 1000009
ll denom = 1e9+7;

ll solve(vector<ll>& p, vector<ll>& q) {
    ll pOdd = 0;
    ll pEven = 0;
    REP(i, p.size()) {
        if (p[i] % 2 == 0)
            pEven++;
        else
            pOdd++;
    }
    
    ll qOdd = 0;
    ll qEven = 0;
    REP(i, q.size()) {
        if (q[i] % 2 == 0)
            qEven++;
        else
            qOdd++;
    }
    
    return pOdd*qOdd + pEven*qEven;
}

int main(int argc, const char * argv[])
{
    ll t; cin >> t;
    vector<ll> result;
    REP(i, t) {
        ll n; cin >> n;
        vector<ll> p(n, 0);
        REP(j, n) cin >> p[j];
        ll m; cin >> m;
        vector<ll> q(m, 0);
        REP(j, m) cin >> q[j];
        result.push_back(solve(p, q));
    }
    REP(i, t) {
        cout << result[i] << endl;
    }
    return 0;
}

