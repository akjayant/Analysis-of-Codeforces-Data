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

ll solve(ll w) {
    if (w == 1)
        return 0;
    else if (w == 2)
        return 2;
    
    ll f = 2;
    ll s = 4;
    REP(i, w-2) {
        ll temp = (f+s)%denom;
        f = s;
        s = temp;
    }
    
    return s - 2;
}

int main(int argc, const char * argv[])
{
    ll n,m; cin >> n >> m;
    ll result = (solve(m) + solve(n) + 2)%denom;
    cout << result;
    return 0;
}

