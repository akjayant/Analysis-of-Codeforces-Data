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
const ll mod = int(1e9) + 7;

int n, m, k;
int a[N];

void YES() {
    cout << "YES\n";
}

void NO() {
    cout << "NO\n";
}

ll quickPower(int a, int n) {
	if (n == 0)
		return 1;
	if (n%2)
		return a * quickPower(a, n-1);
	ll wyn = quickPower(a, n/2);
	return wyn*wyn;
}

ll sqr(ll a) {
	return a*a;
}

ll policz(int n) {
    ll tyl =1, przod = 1;
    ll buff;

    for (int i=2; i<=n; i++) {
        buff = przod;
        przod = przod + tyl;
        tyl = buff;
        przod%=mod;
    }

    return przod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    //cout << policz(n) << " " << policz(m) << endl;

    ll wyn = policz(n)+policz(m)-1;
    wyn *=2;
    wyn%=mod;

    cout << wyn << endl;

}
