#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10,p=1e9+7;
int inc(int a,int b) {
	a+=b;
	return a>=p?a-p:a;
}
int mul(int a,int b) {
	return 1LL*a*b%p;
}
int f[maxn];
int n;
char S[maxn];
int main() {
	scanf("%s",S+1);
	n = strlen(S+1);
	f[0]=f[1]=1;
	for(int i=2;i<=n;++i) {
		f[i]=inc(f[i-1],f[i-2]);
	}
	int cur = 1,ans = 1;
	for(int i=1;i<=n+1;++i) {
		if(S[i]=='w' || S[i]=='m') ans = 0;
		if(S[i-1]==S[i]){
			if(S[i]=='n'||S[i]=='u') {
			++cur;
			}
			else {
				ans = mul(f[cur],ans);
				cur = 1;
			}
		}
		else {
			ans = mul(f[cur],ans);
			cur = 1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
