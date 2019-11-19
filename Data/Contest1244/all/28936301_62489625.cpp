#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char s[N],s1[N];
int f[N],g[N];
int n;
long long k;
char get(char c){
	if (c=='W') return 'B'; else return 'W';
}
void solve() {
	f[1]=1;
	for (int i=2;i<=n;i++) if (s[i]!=s[i-1]) f[i]=f[i-1]; else f[i]=i;
	g[n]=n;
	for (int i=n-1;i>=1;i--) if (s[i]!=s[i+1]) g[i]=g[i+1]; else g[i]=i;
	bool p=0;
	if (s[1]!=s[n]) p=1;
	for (int i=1;i<=n;i++) {
	int l=f[i],r=g[i],lsum=0,rsum=0;
	if (l==1&&p) lsum=n-f[n]+i-1,l=f[n]; else lsum=i-f[i]-1; 
	if (r==n&&p) rsum=g[1]-1+n-i,r=g[1]; else rsum=g[i]-i-1;
	if (lsum<=rsum) {
	if (lsum+1<=k) s1[i]=s[l]; else {
	if (k&1ll) s1[i]=get(s[i]); else s1[i]=s[i];
	}
	} else {
	if (rsum+1<=k) s1[i]=s[r]; else {
	if (k&1ll) s1[i]=get(s[i]); else s1[i]=s[i];
	}
	} 
	}
	printf("%s",s1+1);
}
int main(){
	scanf("%d%lld",&n,&k);
	scanf("%s",s+1);
	bool p=1;
	if (s[1]==s[n]) p=0;
	for (int i=2;i<=n;i++) if (s[i]==s[i-1]) p=0;
	if (p) {
	if (k&1) {
	for (int i=1;i<=n;i++) s[i]=get(s[i]);
	}
	printf("%s",s+1);
	} else {
	solve();
	}
}