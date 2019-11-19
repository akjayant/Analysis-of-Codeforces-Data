#include<bits/stdc++.h>
inline int read(){
	int x=0,w=1;
	char ch=0;
	while (ch<'0' || ch>'9'){
		ch=getchar();
		if (ch=='-') w=-1;	
	}
	while (ch<='9' && ch>='0'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
using namespace std;
typedef long long ll;
const int N=1e5+5;
int a,b,c,d,k;
int main(){
	//freopen("a.in","r",stdin);
	int T=read();
	while (T--){
		a=read(),b=read();
		c=read(),d=read(),k=read();
		int flag=0;
		for (int i=0;i<=k;++i){
			if (i*c>=a && (k-i)*d>=b){
				flag=1;
				printf("%d %d\n",i,k-i);
				break;
			}
		}
		if (!flag) puts("-1");
	}
	return 0;
}
