#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
const int tt=1e9+7;
int n,m;
int f[N];

int read(){
    int s=0,w=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') w=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+ch-'0',ch=getchar();
    return s*w;
}

signed main(){
	n=read();m=read();
	f[1]=2;f[2]=4;
	for (int i=3;i<=max(n,m);++i) f[i]=(f[i-1]+f[i-2])%tt;
	printf("%lld",(f[n]+f[m]-2)%tt);
	return 0;
}