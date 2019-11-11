#include<bits/stdc++.h> 

using namespace std ; 

#define int long long 

const int N = 1e5 + 10 , mod = 1e9 + 7 ; 

int f[N] ; 

int32_t main() { 
	string s ;
	cin >> s ; 
	f[1] = 1 ; 
	f[2] = 2 ; 
	f[3] = 3 ; 
	for(int j = 4 ; j < N ; ++j)
		f[j] = (f[j - 1] + f[j - 2]) % mod ;
	int res = 1 ; 
	for(int i = 0 ; i < s.size() ; ) { 
		if(s[i] == 'm' || s[i] == 'w')
			return cout << 0 << endl , 0 ; 
		if(s[i] == 'u' || s[i] == 'n') { 
			int j = i ; 
			while(j < s.size() && s[j] == s[i])
				++j ; 
			j-- ; 
			(res *= f[j - i + 1]) ;  
			res %= mod ; 
			i = j + 1 ; 

		} else 
			i++ ; 
	}
	cout << res ; 
}
