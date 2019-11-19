#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
//coded by _Int_
inline void in(int &x){
    x=0;int s=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'&&(s=-1),c=getchar();
    while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
    x*=s;
}
typedef long long ll;
const int N=2005;
int n,x[N],y[N],c[N],k[N],sum,fr[N],s[N],e[N],edge;
ll f[N],ans;
bool li[N],v[N];
int mabs(int tmp){
	return tmp>0?tmp:-tmp;
}
int main(){
	in(n);
	for(int i=1;i<=n;i++){
		in(x[i]);in(y[i]);
	}
	for(int i=1;i<=n;i++){
		in(c[i]);
		f[i]=c[i];
	}
	for(int i=1;i<=n;i++)
		in(k[i]);
	for(int num=1;num<=n;num++){
		int idx=-1,Min=0x7fffffff;
		for(int i=1;i<=n;i++){
			if(!v[i]&&f[i]<Min){
				Min=f[i];
				idx=i;
			}
		}
		ans+=f[idx];
		if(f[idx]==c[idx])li[idx]=1,sum++;
		else if(fr[idx]){
			s[++edge]=idx;
			e[edge]=fr[idx];
		}
		v[idx]=1;
		for(int i=1;i<=n;i++){
			ll u=1ll*(k[i]+k[idx])*(mabs(x[i]-x[idx])+mabs(y[i]-y[idx]));
			if(!v[i]&&f[i]>u){
				f[i]=u;
				fr[i]=idx;
			}
		}
	}
	cout<<ans<<endl<<sum<<endl;
	for(int i=1;i<=n;i++)
		if(li[i])
			cout<<i<<' ';
	cout<<endl<<edge<<endl;
	for(int i=1;i<=edge;i++)
		cout<<s[i]<<' '<<e[i]<<endl; 
	return 0;
}
