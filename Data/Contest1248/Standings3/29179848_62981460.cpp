#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define ll long long
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)−1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define ld long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

const int N = int(3e5) + 99;

ll n, m, k;

int main() {
    cin.tie(0);
    int t;
    cin >> t;
    for (int ii =0; ii<t; ii++) {
        cin >> n;
        ll licz[2] = {0,0}, kacz[2] = {0,0};
        for (ll i=0; i<n; i++) {
            cin >> k;
            licz[k%2]++;
        }

        cin >> m;
        for (ll i=0; i<m; i++) {
            cin >> k;
            kacz[k%2]++;
        }

        ll wyn = kacz[0]*licz[0] + kacz[1]*licz[1];

        cout << wyn << endl;
    }

}
