#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int maxn=105;
int n,a,b,c;
char s[maxn],t[maxn];
inline char out(){
	if(a){a--;return 'R';}
	if(b){b--;return 'P';}
	c--;return 'S';
}
int main(){
	int cas=read();
	while(cas--){
		n=read();
		a=read();b=read();c=read();
		scanf("%s",s+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			t[i]='A';
			if(s[i]=='R'){
				if(b){b--;ans++;t[i]='P';}
			}
			if(s[i]=='P'){
				if(c){c--;ans++;t[i]='S';}
			}
			if(s[i]=='S'){
				if(a){a--;ans++;t[i]='R';}
			}
		}
		if(ans>=(n+1)/2){
			puts("YES");
			for(int i=1;i<=n;i++){
				if(t[i]=='A')cout<<out();
				else cout<<t[i];
			}
			cout<<'\n';
			
		}else puts("NO");
	}
	return 0;
}
