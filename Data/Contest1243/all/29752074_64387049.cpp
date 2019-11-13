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

int main(){
	fast_io;
    cin >> q;
    while (q--){
    	cin >> n >> s >> t;
    	x = -1;
    	y = -1;
    	flag = 0;
    	for (int i = 0; i < n; ++i){
    		if (s[i] != t[i] && x == -1)	x = i;
			else if (s[i] != t[i] && y == -1)	y = i;	
			else if (s[i] != t[i])	flag = 1;
		}
		if (flag){
			cout << "No\n";
			continue;
		}
		else if (y == -1){
			cout << "No\n";
		}
		else{
			swap(s[x], t[y]);
			if (s == t){
				cout << "Yes\n";
				continue;
			}
			swap(s[x], t[y]);
			swap(t[x], s[y]);
			if (s == t){
				cout << "Yes\n";
				continue;
			}
			swap(t[x], s[y]);
			cout << "No\n";
		}
	}
    return 0;
}
/*                now or never                         */
