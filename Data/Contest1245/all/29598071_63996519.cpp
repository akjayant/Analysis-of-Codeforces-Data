#include<bits/stdc++.h>
const int mod = 1e9 + 7;
const int maxn = 100100;
char ch[maxn];
int f[maxn];
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> ch + 1; int n = strlen(ch + 1);
	f[0] = 1;
	for(int i = 1;i <= n;++i){
		if(ch[i] != 'w' && ch[i] != 'm') f[i] = f[i - 1];
		if(ch[i] == ch[i - 1] && (ch[i] == 'n' || ch[i] == 'u'))
			f[i] = (f[i] + f[i-2]) % mod;
	}
	std::cout << f[n] << '\n';
}
