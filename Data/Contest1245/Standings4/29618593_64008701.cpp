#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef tuple<int, int, int> tiii;
typedef tuple<int, int, int, int> tiiii;
typedef set <int> si;
typedef map <int, int> mii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vector <int>> vvi;  
#define F(i, a, b) for(int i = a; i <= (int)b; i++)
#define f(i, a, b) for(int i = a; i >= (int)b; i--)
#define F2(i, a, b) for(int i = a; i <= (int)b; i+=2)
#define f2(i, a, b) for(int i = a; i >= (int)b; i-=2)
#define wh(n) int iteration = n; while(iteration--) 
#define For(t, it) for(auto it = (t).begin(); it != (t).end(); ++it)
#define IN insert
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define RS resize
#define GRAF(n) vvi gr; gr.resize(n+1); vector <bool> was; was.resize(n+1, 0);

ll const mod = 1e9 + 7;

ll fib[100004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
        #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
	#endif
	string s;
	ll ans = 1ll;
	fib[0] = 1ll;
	fib[1] = 1ll;
	F(i, 2, 100000){
		fib[i] = (fib[i-1] + fib[i-2]) %mod;
	}
	cin >> s;
	F(i, 0, s.size()-1){
		if(s[i] == 'm' || s[i] == 'w'){
			cout << 0;
			return 0;
		}
		if(s[i] == 'u' || s[i] == 'n'){
			int cnt = 1;
			while(i+1 < s.size() && s[i+1] == s[i]){
				i++;
				cnt++;
			}
			ans *= fib[cnt];
			ans %= mod;		
		} 	
	}
	cout << ans;
	return 0;
}