#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int t,n,m;

int read(){
    int s=0,w=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') w=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+ch-'0',ch=getchar();
    return s*w;
}

signed main(){
	t=read();
	while (t--){
		int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
		n=read();
		for (int i=1;i<=n;++i){
			int p=read();
			if (p&1) ++cnt1;else ++cnt2;
		}
		m=read();
		for (int i=1;i<=m;++i){
			int q=read();
			if (q&1) ++cnt3;else ++cnt4;
		}
		int ans=(cnt1*cnt3)+(cnt2*cnt4);
		printf("%lld\n",ans);
	}
	return 0;
}