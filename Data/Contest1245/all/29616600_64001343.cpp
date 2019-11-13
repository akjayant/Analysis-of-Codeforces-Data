/*
* @Author: wxyww
* @Date: 2019-11-01 22:42:35
* @Last Modified time: 2019-11-01 22:49:38
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
const int N = 110;
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
int a[4],b[4],pr[N];
char s[N];
int main() {
	int T = read();
	while(T--) {
		int n = read();
		
		for(int i = 1;i <= 3;++i) a[i] = read(),b[i] = 0;
		scanf("%s",s + 1);

		for(int i = 1;i <= n;++i) {
			if(s[i] == 'R') b[1]++;
			else if(s[i] == 'P') b[2]++;
			else b[3]++;
		}
		memset(pr,0,sizeof(pr));
		int ans = min(b[1],a[2]) + min(b[2],a[3]) + min(b[3],a[1]);
		if(ans < (n + 1) / 2) {puts("NO");continue;}
		puts("YES");
		for(int i = 1;i <= n;++i) {
			if(s[i] == 'R' && a[2]) {
				pr[i] = 2;a[2]--;
			}
			if(s[i] == 'P' && a[3]) {
				a[3]--;pr[i] = 3;
			}
			if(s[i] == 'S' && a[1]) {
				a[1]--;pr[i] = 1;
			}
		}

		for(int i = 1;i <= n;++i) {
			if(!pr[i]) {
				if(a[1]) {
					pr[i] = 1;a[1]--;
				}
				else if(a[2]) {
					pr[i] = 2;a[2]--;
				}
				else pr[i] = 3;a[3]--;
			}
			if(pr[i] == 1) putchar('R');
			if(pr[i] == 2) putchar('P');
			if(pr[i] == 3) putchar('S');
		}
		puts("");

	}

	return 0;
}