/**
 *    author:  MySakure
 *    created: 20.10.2019 18:06:32       
**/
#include<bits/stdc++.h>
using namespace std;


const int maxn=550;
char x[maxn];
int a[maxn],dp[maxn];
int n,ansa=0,ansb=0,ans=0;
void solve(int l,int r){
	int Max=0,s=0,res=0;
	for(int i=1;i<=n;++i)dp[i]=a[i]+dp[i-1];
	for(int i=n;i>=1;--i){
		dp[i]=max(dp[i],dp[i+1]);
	}
	for(int i=0;i<=n;++i){
		s+=a[i];
		Max=max(s,Max);

		if(Max-s<=0&&x[i]=='('&&dp[i]-s<=0){
			// if(l==5&&r==10)
			// cerr<<"inx "<<i<<endl;
			res++;
		}
	}
	// if(l==5&&r==10){
	// 	for(int i=1;i<=n;++i)cout<<x[i]<<" ";
	// 	cout<<endl;
	// }
	//cerr<<"debug "<<n-l+1<<" "<<n-r+1<<" "<<res<<endl;
	if(res>=ans){
		ansa=l,ansb=r;
		ans=res;
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef mysakure 
	freopen("in2.txt","r",stdin);
#endif
	cin>>n;

	for(int i=1;i<=n;++i){
		char tmp;
		cin>>tmp;
		x[i]=tmp;
		if(tmp=='('){
			a[i]=1;
			ansa++;
		}
		else{
			a[i]=-1;
			ansb++;
		}
	}
	if(ansa!=ansb){
		cout<<0<<endl;
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	ansa=0,ansb=0;
	reverse(a+1,a+1+n);
	reverse(x+1,x+1+n);
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			swap(a[i],a[j]);
			swap(x[i],x[j]);
			solve(i,j);
			swap(a[i],a[j]);
			swap(x[i],x[j]);

		}
	}
	cout<<ans<<endl;
	cout<<n-ansa+1<<" "<<n-ansb+1<<endl;
	return 0;
}

