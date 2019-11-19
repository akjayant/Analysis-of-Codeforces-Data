#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define debug(i) cout << i << endl;
#define debugarr(a) for(auto i : a) cout << i << " ";

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll, ll>
#define vpi vector<pi>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n;

        ll impar_n=0;
        ll par_n=0;
        ll impar_m=0;
        ll par_m=0;

        for(int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            if(x & 1LL) impar_n++;
            else par_n++;
        }
        cin >> m;
        for(int i = 0; i < m; i++) {
            ll x;
            cin >> x;
            if(x & 1LL) impar_m++;
            else par_m++;
        }
        ll ans = impar_n * impar_m + par_n * par_m;
        cout << ans << "\n";
    }
}
