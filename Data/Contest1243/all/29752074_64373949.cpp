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

ll q, n, m, p, num[MAX1], mod = 1e9+7;

int main(){
	fast_io;
    cin >> q;
    while (q--){
    	cin >> n;
    	for (int i = 0; i < n; ++i)	cin >> num[i];
    	sort(num, num+n);
    	for (int i = 0; i < n/2; ++i)	swap(num[i], num[n-i-1]);
    	p = 0;
    	for (ll i = 0; i < n; ++i){
    		p = max(min(num[i], i+1), p);
		}
		cout << p << endl;
	}
    return 0;
}
/*                now or never                         */
