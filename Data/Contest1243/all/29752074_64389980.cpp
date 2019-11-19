#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
typedef long double     ld;
typedef string          str;
#define all(x)			(x).begin(),(x).end()
#define Sort(x)			sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define endl            '\n'
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MAX1 = 1e5 + 7;

ll q, n, x, y, num[MAX1], mod = 1e9+7, flag;
string s, t;
vector <ll> mag;

void magh(ll n){
	for (int i = 2; i < sqrt(n); ++i){
		if (n%i == 0)	mag.push_back(i), mag.push_back(n/i);
	}
	if (sqrt(n) == int(sqrt(n)))	mag.push_back(int(sqrt(n)));
}

int main(){
	fast_io;
    cin >> n;
    magh(n);
    mag.push_back(n);
    x = mag[0];
    for (int i = 0; i < mag.size(); ++i)	x = __gcd(x, mag[i]);
    cout << x;
    return 0;
}
/*                now or never                         */
