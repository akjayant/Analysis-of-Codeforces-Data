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

int main(int argc, const char * argv[])
{
    ll n; cin >> n;
    vector<ll> a(n, 0);
    REP(i, n) cin >> a[i];
    SORT(a);
    ll side1 = 0;
    REP(i, n/2) {
        side1 += a[i];
    }
    ll side2 = 0;
    FOR(i, n/2, n) {
        side2 += a[i];
    }
    cout << (side1*side1 + side2*side2);
    return 0;
}

