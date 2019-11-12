#include <string.h>
#include <unordered_map>

#include <sstream>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <set>

#include <map>
#include <vector>
#include <string>
#include <stdlib.h>

#define ll long long
#define clr(x) memset(x,0,sizeof(x))
#define _clr(x) memset(x,-1,sizeof(x))
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define frr(i,a,b) for(int i = a; i > b; --i)
#define pb push_back
#define sf scanf

#define pf printf
#define mp make_pair
#define N 1000000

using namespace std;

int mod = 1e9+7;

ll pw(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = (ret*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return ret;
}

void sol() {
    ll n,m;
    cin>>n>>m;
    ll ans = (pw(2,m) - 1 + mod)%mod;
    cout<<pw(ans,n)<<endl;
}

int main() {
    sol();
}