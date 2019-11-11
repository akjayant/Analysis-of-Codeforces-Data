/*
* @Author: wxyww
* @Date: 2019-11-01 22:54:50
* @Last Modified time: 2019-11-01 22:57:02
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int N = 100000 + 100,mod = 1e9 + 7;
ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int f[N];
char s[N];
int main() {
	scanf("%s",s + 1);
	int n = strlen(s + 1);
	f[0] = 1;
	for(int i = 1;i <= n;++i) {
		if(s[i] == 'w' || s[i] == 'm') {
			puts("0");return 0;
		}
		f[i] = f[i - 1];
		if(s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n')) {
			f[i] += f[i - 2];
			f[i] %= mod;
		}
	}
	cout<<f[n];
	return 0;
}