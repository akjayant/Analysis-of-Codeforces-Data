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
    int k, n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n;
        string s, t;
        cin >> s >> t;
        int equal = 0;
        vector<pair<int, pair<int, int>>> rem;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == t[i]) 
                equal++;
            else {
                rem.push_back({i, {s[i], t[i]}});
            }
        }


        if (equal != n-2)
            cout << "No" << "\n";
        else {
            assert(rem.size() == 2);
            if ((rem[0].se.fi == rem[1].se.fi and rem[0].se.second == rem[1].se.second)) {
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }
        }

    }
}

