#include<bits/stdc++.h>
#define rep(q,a,b) for(int q=a,q##_end_=b;q<=q##_end_;++q)
#define dep(q,a,b) for(int q=a,q##_end_=b;q>=q##_end_;--q)
#define mem(a,b) memset(a,b,sizeof a )
using namespace std;
void in(int &r){
	static char c;
	r=0;
	bool flag=0;
	while(c=getchar(),!isdigit(c))if(c=='-')flag=1;
	do r=(r<<1)+(r<<3)+(c^48);
	while(c=getchar(),isdigit(c));
	if(flag)r=-r;
}
const int mod=1e9+7;
const int mn=100005;
char as[mn];
int len[mn];
int main(){
	scanf("%s",as+1);
	int n=strlen(as+1);
	rep(q,1,n)if(as[q]=='m'||as[q]=='w'){
		puts("0");
		return 0;
	}
	len[0]=1,len[1]=1;
	rep(q,2,n)len[q]=(len[q-1]+len[q-2])%mod;
	int st=0;
	int ans=1;
	rep(q,1,n)if(as[q]!='n'){
		if(st+1<=q-1)ans=1LL*ans*len[q-1-(st+1)+1]%mod;
		st=q;
	}
	if(st+1<=n)ans=1LL*ans*len[n-(st+1)+1]%mod;
	st=0;
	rep(q,1,n)if(as[q]!='u'){
		if(st+1<=q-1)ans=1LL*ans*len[q-1-(st+1)+1]%mod;
		st=q;
	}
	if(st+1<=n)ans=1LL*ans*len[n-(st+1)+1]%mod;
	cout<<ans<<endl;
	return 0;
}