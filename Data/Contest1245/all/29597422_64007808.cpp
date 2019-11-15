#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while('0'>ch || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while('0'<=ch && ch<='9'){x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();}
	return x*f;
}
const int mod=1e9+7;
int n,m,t,res,dp[100050];
char a[100005];
main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	if(!n || (n==1 && (a[1]>'z'|| a[1]<'a'))){
		cout<<0; return 0;
	}
	rep(i,1,n){
		if(a[i]=='m' || a[i]=='w'){
			cout<<0;return 0;
		}
	}
	dp[0]=dp[1]=1;
	rep(i,2,n){
		if((a[i]=='n' && a[i-1]=='n') || (a[i]=='u' && a[i-1]=='u')) dp[i]=(dp[i-2]+dp[i-1])%mod;//,cout<<i<<"DD"<<endl;
		else dp[i]=dp[i-1];
	//	cout<<dp[i]<<endl;
	}
	printf("%lld",dp[n]);
	return 0;
}