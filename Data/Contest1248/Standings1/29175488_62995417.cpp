#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
typedef long long ll;
const int N = 1010;
ll read() {
	ll x = 0,f = 1;char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int ans,ansl,ansr,sum[N],n;
char s[N];
void solve(int l,int r) {
	swap(s[l],s[r]);
	swap(s[l + n],s[r + n]);
	int k = 0,mn = n;
	for(int i = 1;i < n + n;++i) {
		if(s[i] == '(') sum[i] = sum[i - 1] + 1;
		else sum[i] = sum[i - 1] - 1;
//		if(sum[i] < 0) return;
		mn = min(mn,sum[i]);
	}
	for(int i = n;i < n + n;++i) {
		if(sum[i] == sum[i - n] && mn >= sum[i - n]) k++;
	}
	
//	if(l == 7 && r == 8) {
//		for(int i = 1;i <= n + n;++i) 
//		printf("%d ",sum[i]);
//		puts("");
//	}
	
	if(k >= ans) ansl = l,ansr = r,ans = k;
	
	swap(s[l],s[r]);
	swap(s[l + n],s[r + n]);
}
int main() {
	n = read();
	scanf("%s",s + 1);
	
	for(int i = n + 1;i <= n + n;++i) s[i] = s[i - n];
	
	
	
	
	for(int i = 1;i <= n;++i) {
		for(int j = i;j <= n;++j) {
			solve(i,j);
		}
	}
	
	
	printf("%d\n%d %d\n",ans,ansl,ansr);
	return 0;
}
