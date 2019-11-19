#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

template<class T>void byebye(T _rpl){cout<<_rpl<<endl;exit(0);}
int nextint(){int x;scanf("%d",&x);return x;}
ll nextll(){ll x;scanf("%lld",&x);return x;}

int read(){
	int f=1,ret=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ret=ret*10+(c-'0');c=getchar();}
	return ret*f;
}

int cnt1=0,cnt2=0;
int n,m;
ll ans=0;

void MAIN(){
	ans=cnt1=cnt2=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int x;
		scanf("%d",&x);
		if(abs(x)&1)cnt1++;
		else cnt2++;
	}
	scanf("%d",&m);
	for(int i=0;i<m;++i){
		int x;
		scanf("%d",&x);
		if(abs(x)&1)ans+=ll(cnt1);
		else ans+=ll(cnt2);
	}
	printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--)MAIN();	
	return 0;
}
