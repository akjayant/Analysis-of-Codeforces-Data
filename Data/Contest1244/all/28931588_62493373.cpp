#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

#define NN 200010

char s[NN];
int flag[NN];
int n, k;
int L[NN], R[NN];

int pre(int u) {
	if(u == 1) return n;
	return u - 1;
}

int nxt(int u) {
	if(u == n) return 1;
	return u + 1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	cin >> n >> k;
	scanf("%s", s + 1);
	int cnt = 0;
	
	for(int i=1; i<=n; i++) {
		if(s[pre(i)] == s[i] || s[i] == s[nxt(i)]) flag[i] = 1;
		cnt += flag[i];
	}
	
	if(!cnt) {
		if(k % 2) {
			for(int i=1; i<=n; i++) {
				if(s[i] == 'B') s[i] = 'W';
				else s[i] = 'B';
			}
		}
		printf("%s", s+1);
		return 0;
	}
	int pos = 1;
	while(!flag[pos]) pos = pre(pos);
	for(int i=1; i<=n; i++) {
		if(flag[i]) pos = i;
		L[i] = i - pos;
		if(L[i] < 0) L[i] += n;
	}
	
	pos = 1;
	while(!flag[pos]) pos = nxt(pos);
	R[1] = pos - 1;
	
	for(int i=n; i>=1; i--) {
		if(flag[i]) pos = i;
		R[i] = pos - i;
		if(R[i] < 0) R[i] += n;
	}
	
	for(int i=1; i<=n; i++) {
		int x = min(L[i], R[i]);
		if(x > k) {
			if(k % 2) {
				if(s[i] == 'W') s[i] = 'B';
				else s[i] = 'W';
			}
			putchar(s[i]);
		} else {
			if(x % 2) {
				if(s[i] == 'W') s[i] = 'B';
				else s[i] = 'W';
			}
			putchar(s[i]);
		}
	}
	return 0;
}

                             