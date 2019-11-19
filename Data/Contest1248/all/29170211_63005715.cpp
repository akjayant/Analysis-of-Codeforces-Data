#include<bits/stdc++.h>
#define fr(i,a,b) for(register int i = a;i <= b;++i)
#define int long long
#define mod 1000000007
#define N 100010
using namespace std;

int f[N][4];
int n,m,t;

inline int read(){
	int x = 0,f = 1;char c = getchar();
	while(!isdigit(c)){if(c == '-')f = -1;c = getchar();}
	while(isdigit(c)){x = x * 10 + c - '0';c = getchar();}
	return f * x;
}

inline void solve(){
	f[1][0] = f[1][1] = 1;
	f[2][0] = f[2][1] = f[2][2] = f[2][3] = 1;
	fr(i,3,t){
		f[i][0] = f[i - 1][2] % mod;
		f[i][3] = f[i - 1][1] % mod;
		f[i][2] = (f[i - 1][3] + f[i - 1][1]) % mod;
		f[i][1] = (f[i - 1][2] + f[i - 1][0]) % mod;
	}
}

signed main(){
	n = read(),m = read();t = max(n,m);
	solve();
	int ans1 = ((f[n][1] + f[n][2]) % mod + f[n][3] % mod + f[n][0]) % mod;
	int ans2 = ((f[m][1] + f[m][2]) % mod + f[m][3] % mod + f[m][0]) % mod;
	if(n == 1)ans1 = 2;
	if(m == 1)ans2 = 2;
	cout<<(ans1 + ans2 - 2 + mod)% mod;
	return 0;
}
