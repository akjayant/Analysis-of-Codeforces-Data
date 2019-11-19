#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvvi> vvvvi;
typedef tuple<ll, ll, ll> iii;
typedef vector<iii> viii;
typedef pair<double, iii> diii;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    k = n;
    map<ll, int> fact;
    for (int i = 2; i <= sqrt(n); ++i) {
        while (k%i == 0) {
            fact[i] = 1;
            k /= i;
        }
    }
    if (k != 1) fact[k]++;
    if (fact.size() > 1) cout << "1\n";
    else {
        for (auto v : fact) cout << v.F << "\n";
    }
    return 0;
}