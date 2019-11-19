#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x){
	char c=getchar();
	int f=1;
	x=0;
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
int cnt1[2],cnt2[2];
signed main(){
	int i,j,k,m,n;
	int T;
	read(T);
	while(T--){
		cnt1[1]=cnt1[0]=cnt2[1]=cnt2[0]=0;
		read(n);
		for(register int i=1;i<=n;i++){
			int x;
			read(x);
			cnt1[x&1]++;
		}
		read(m);
		for(register int i=1;i<=m;i++){
			int x;
			read(x);
			cnt2[x&1]++;
		}
		//cout<<cnt1[1]<<" "<<cnt1[0]<<" "<<cnt2[1]<<" "<<cnt2[0]<<endl;
		int ans=cnt1[1]*cnt2[1]+cnt1[0]*cnt2[0];
		cout<<ans<<endl;
	}
	return 0;
}
