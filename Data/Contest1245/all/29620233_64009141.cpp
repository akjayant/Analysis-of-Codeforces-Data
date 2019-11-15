#include<bits/stdc++.h>
#define DEBUG cerr << "Call out: " << __func__ << "\t" << "Line: " << __LINE__ << "\t :"
using namespace std;
#define MOD 1000000007
#define int long long
int f[101000];
string s;
signed main(){
	f[1] = 1;
	f[0] = 1;
	for (int i=2;i<=100000;i++)
		f[i] = (f[i-1] + f[i-2]) % MOD;
	cin >> s;
	if (s.find("m") != string::npos) cout << 0 << endl;
	else if (s.find("w") != string::npos) cout << 0 << endl;
	else{
		int siz = s.size();
		s += '$';
		int pl = 0;
		int lst = 0;
		long long ans = 1;
		for (int i=0;i<=siz;i++){
	//		cout << pl << ' ';
			if (lst == s[i]) pl ++;
			else{
				if (lst == 'u' || lst == 'n'){
					ans = ans * f[pl] % MOD;
				}
				pl = 1;
			}
			lst = s[i];
		}
		cout << ans << endl;
	}
}
