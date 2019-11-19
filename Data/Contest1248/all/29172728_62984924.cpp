#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,s1,s2;
int a[N];

int read(){
    int s=0,w=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') w=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+ch-'0',ch=getchar();
    return s*w;
}

signed main(){
	n=read();
	for (int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n/2;++i) s1+=a[i];
	for (int i=n/2+1;i<=n;++i) s2+=a[i];
	printf("%lld",s1*s1+s2*s2);
	return 0;
}