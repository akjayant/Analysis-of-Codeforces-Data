#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
void read(int &x){
	char c=getchar();
	int f=1;
	x=0;
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
int a[maxn];
signed main(){
	int i,j,k,m,n;
	read(n);
	for(register int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);
	int x=0,y=0;
	for(register int i=1;i<=n/2;i++)x+=a[i];
	for(register int j=n/2+1;j<=n;j++)y+=a[j];
	int ans=x*x+y*y;
	cout<<ans<<endl;
	return 0;
}
