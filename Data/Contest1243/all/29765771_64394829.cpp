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
    for (int x = 0; x < k; x++) {
        cin >> n;
        string s, t;
        cin >> s >> t;

        unordered_map<char, int> freq;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
            freq[t[i]]++;
        }
        
        bool poss = true;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second % 2 == 1) {
                poss = false;
                break;
            }
        }

        if (!poss) {
            cout << "No" << "\n";
            continue;
        }

        cout << "Yes" << "\n";

        vector<pair<int, int>> ans;

        for (int i = 0; i < n; i++) {
            if (s[i] == t[i])
                continue;

            int j;
            for (j = i+1; j < n; j++) {
                if (s[j] == s[i])
                    break;
            }

            if (j == n) {
                for (j = i+1; j < n; j++) {
                    if (t[j] == s[i])
                        break;
                }
                //cout << i << "\n";
                assert(j != n);
                ans.pb({j+1, j+1});
                swap(s[j], t[j]);
                ans.pb({j+1, i+1});
                swap(s[j], t[i]);
            } else {
                ans.pb({j+1, i+1});
                swap(s[j], t[i]);

            }
        }

        cout << ans.size() << '\n';
        for (auto x : ans) {
            cout << x.fi << " " << x.se << "\n";
        }

    }
}

