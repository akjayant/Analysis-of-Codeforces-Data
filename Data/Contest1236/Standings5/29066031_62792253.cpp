#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
void read(int &x){
	char c=getchar();
	int f=1;
	x=0;
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
int ksm(int x,int y){
	int sum=1;
	while(y){
		if(y&1)sum=sum*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return sum;
}
signed main(){
	int i,j,k,m,n;
	read(n);read(m);
	int ans=ksm(ksm(2,m)-1,n)%mod;
	cout<<ans<<endl;
	return 0;
}
