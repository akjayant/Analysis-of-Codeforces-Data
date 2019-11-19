#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

#define INF 2147483647
ll n;
char s[1100];
int main(int argc,char *argv[]){
	int T;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
		scanf("%s",s+1);
		ll ans=0;
		for(ll i=1; i<=n; i++) ans+=s[i]-48;
		ll l=1,r=n;
		for(l=1; l<=n; l++){if(s[l]=='1') break;}
		for(r=n; r>=1; r--){if(s[r]=='1') break;}
		if(r==0) r=-INF;
		if(l==n+1) l=INF;
		printf("%d\n",max(ans+n,max(n-l+1,r)*2));
	}
	return 0;
}
