#include <bits/stdc++.h>
  
#define pb push_back
#define fst first
#define snd second
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define open freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
   
typedef long long ll;
typedef long double ld;
    
using namespace std;

const int mod = 1e9 + 7;

signed main(){
    ios;
    string s;
    cin >> s;
    ll ans = 1;
    string now = "";
    vector<int> v;
    int it = -2;
    for (int i = 0; i < s.size(); i++){
    	if (s[i] == 'm' || s[i] == 'w'){
    		cout << 0;
    		return 0;
    	}
    	if (s[i] == 'u' || s[i] == 'n'){
    		now.pb(s[i]);
    		v.pb(i);
    	}
    }
    int cnt = 0;
    char chr = '&';
    ll fib[s.size() + 1];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= s.size(); i++){
    	fib[i] = fib[i - 1] + fib[i - 2];
    	fib[i] %= mod;
    }
    int mx = 0;
    for (int i = 0; i < now.size(); i++){
    	if (now[i] != chr || (v[i] != it + 1)){
    		ans *= fib[cnt];
    		ans %= mod;
    		cnt = 1;
    	}else{
    		cnt++;
    	}
    	mx = max(mx, cnt);
    	it = v[i];
    	chr = now[i];
    }
    ans *= fib[cnt];
    ans %= mod;
   	cout << ans << endl;
}