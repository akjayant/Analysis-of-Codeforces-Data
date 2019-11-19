#include<bits/stdc++.h>
#define MP make_pair
#define PB emplace_back
using namespace std;
typedef long long ll;
template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0' || ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&& ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}
int T,n,m,i,p,q,a,b,c,d;
int main(){
	for (read(T);T--;){
		read(n);
		a=b=c=d=0;
		for (i=1;i<=n;++i){
			read(p);
			if (p&1) a++;
			else b++;
		}
		read(m);
		for (i=1;i<=m;++i){
			read(q);
			if (q&1) c++;
			else d++;
		}
		printf("%lld\n",1LL*a*c+1LL*b*d);
	}
	return 0;
}