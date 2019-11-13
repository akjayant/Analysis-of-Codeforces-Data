#include <bits/stdc++.h>

#define fr first
#define sc second
#define pb push_back
#define mk make_pair
#define all(s) s.begin(),s.end()
#define int long long

using namespace std;

const int N = (1e5 + 12);
const int mod = (1e9 + 7);
const int INF = (0x3f3f3f3f);

int ans = 1, fib[N];
main()
{
	int u = 0;
	string s;
	cin >> s;
	fib[1] = 1;
	fib[2] = 2;
	for(int i = 3;i <= s.size(); i++){
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] %= mod;
	}
	s = s + ".";
	bool f = true;
	for(int i = 0;i < s.size(); i++){
		if(s[i] == 'u' || s[i] == 'n'){
			int j, cnt = 1;
			for(j = i + 1;j < s.size(); j++){
				if(s[i] != s[j]){
					break;
				}
				cnt++;
			}
			i = j - 1;
			ans = ans * fib[cnt];
			ans = ans % mod;
		}
	}
	for(int i = 0;i < s.size(); i++){
		if(s[i] == 'm' || s[i] == 'w'){
			f = false;
			break;
		}
	}
	if(f){
		cout << ans;
	}
	else{
		cout << 0;
	}
	
}
