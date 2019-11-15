#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

template<class T>void byebye(T _rpl){cout<<_rpl<<endl;exit(0);}
int nextint(){int x;scanf("%d",&x);return x;}
ll nextll(){ll x;scanf("%lld",&x);return x;}
template<class T>T emax(T& t1,T t2){if(t1<t2)t1=t2;return t1;}
template<class T>T emin(T& t1,T t2){if(t1>t2)t1=t2;return t1;}

int read(){
	int f=1,ret=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ret=ret*10+(c-'0');c=getchar();}
	return ret*f;
}

int n,a,b,c,wins;
char s[105];
char ans[105];

void MAIN(){
	memset(ans,0,sizeof(ans));
	wins=0;
	n=read();
	a=read(),b=read(),c=read();
	scanf("%s",s);
	for(int i=0;i<n;++i){
		if(s[i]=='R'&&b>0)--b,wins++,ans[i]='P';
		if(s[i]=='P'&&c>0)--c,wins++,ans[i]='S';
		if(s[i]=='S'&&a>0)--a,wins++,ans[i]='R';
	}
	for(int i=0;i<n;++i){
		if(!ans[i]){
			if(a>0)ans[i]='R',--a;
			else if(b>0)ans[i]='P',--b;
			else ans[i]='S',--c;
		}
	}
	if(wins>=(n+1)/2)puts("YES"),puts(ans);
	else puts("NO");
}

int main(){
	int T=read();
	while(T--)MAIN();
	return 0;
}
