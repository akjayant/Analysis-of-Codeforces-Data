#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;
inline char get(){
	static char buf[30000],*p1=buf,*p2=buf;
	return p1==p2 && (p2=(p1=buf)+fread(buf,1,30000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	register char c=get();register int f=1,_=0;
	while(c>'9' || c<'0')f=(c=='-')?-1:1,c=get();
	while(c<='9' && c>='0')_=(_<<3)+(_<<1)+(c^48),c=get();
	return _*f;
}
int n,m;
int a_j,a_o;//奇数和偶数 
int b_j,b_o;
signed main(){
	//freopen("1.txt","r",stdin);
	int t=read();
	while(t--){
		a_j=a_o=b_j=b_o=0;
		n=read();
		for(register int i=1;i<=n;i++){
			int cas=abs(read());
			//cout<<cas<<"<---"<<t<<endl;
			if(cas%2==0)a_o++;
			else a_j++;
		}
		m=read();
		for(register int i=1;i<=m;i++){
			int cas=abs(read());
			if(cas%2==0)b_o++;
			else b_j++;
		}
		cout<<a_j*b_j+a_o*b_o<<endl;
	}
	return 0;
}