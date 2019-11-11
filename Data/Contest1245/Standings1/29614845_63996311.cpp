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



int main(){
	int T=read();
	while(T--){
		int a,b;
		a=read(),b=read();
		if(__gcd(a,b)==1)puts("Finite");
		else puts("Infinite");
	}
	return 0;
}
