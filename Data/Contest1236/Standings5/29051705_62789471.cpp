/*input
2 2

*/
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define x first
#define y second
#define inf INT_MAX / 2ll
#define all(a) a.begin(), a.end()
#define db(a) cout << fixed << #a << " = " << a << endl;
#define ld long double
using namespace std;

ll mod = 1e9 + 7;
ll fpow(ll a, ll b){ //a ^ b
    if(b == 1)
        return (a % mod);

    ll pow = fpow(a, b / 2);
    ll rez = (pow * pow) % mod;

    if(b % 2 == 1)
        rez = (rez * a) % mod;

    return rez;
}
int main(){
	ll n, m;
	cin >> n >> m;

	ll vienas = (fpow(2, m) + mod - 1) % mod;
	ll visi = fpow(vienas, n);

	cout << visi << endl;


}
