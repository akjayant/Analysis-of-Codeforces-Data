#ifdef __APPLE__
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <random>
#else
#include <bits/stdc++.h>
#endif

using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef vector<long long int> VLLI;
typedef vector<pair<int, int> > VPI;
typedef long long ll;
typedef pair<int,int> PII;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int main() {
    ll n;
    cin >> n;
    ll d = 1;

    if (n <= 2) {
        cout << n << "\n";
        return 0;
    }

    vector<ll> primes;
    for (ll i = 2; i*i <= n; i+=d, d = 2) {
        int cnt = 0;
        while (n%i == 0) {
            n /= i;
            cnt++;
        }
        if (cnt > 0) {
            primes.pb(i);
        }
    }

    if (n > 1) {
        primes.pb(n);
    }

    if (primes.size() > 1) {
        cout << 1 << "\n";
    } else {
        cout << primes[0] << "\n";
    }
}

