#include<bits/stdc++.h>
#define maxn 100005
#define maxm 500005
#define inf 0x7fffffff
#define ll long long

using namespace std;
char str[maxn]; int res[maxn];

inline int read(){
    int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

int main(){
	int t=read();
	while(t--){
		memset(res,0,sizeof(res));
		int n=read(),a=read(),b=read(),c=read();
		int na=0,nb=0,nc=0; scanf("%s",str+1);
		for(int i=1;i<=n;i++){
			if(str[i]=='R') na++;
			if(str[i]=='P') nb++;
			if(str[i]=='S') nc++;
		}
		int ned=n/2+(n&1);
		if(min(na,b)+min(nb,c)+min(nc,a)>=ned){
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++){
				if(str[i]=='R' && b) res[i]='P',b--;
				if(str[i]=='P' && c) res[i]='S',c--;
				if(str[i]=='S' && a) res[i]='R',a--;
			}
			for(int i=1;i<=n;i++)
				if(!res[i]){
					if(a) res[i]='R',a--;
					else if(b) res[i]='P',b--;
					else res[i]='S',c--;
				}
			for(int i=1;i<=n;i++) cout<<(char)res[i];
			cout<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}
