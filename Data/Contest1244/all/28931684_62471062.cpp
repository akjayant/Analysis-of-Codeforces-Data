#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int T,n,m,flg,minn,maxx,ans;
string a;
int main(){
	ios::sync_with_stdio(false);
	//scanf("%d",&T);
	cin>>T;
	while(T--){
		cin>>n>>a;
		flg=0,minn=2000,maxx=-1;
		for(int i=0;i<n;i++){
			if(a[i]=='1'){
				if(i<minn)
					minn=i;
				if(i>maxx)
					maxx=i;
				flg=1;
			}
		}
		if(flg==0)
			printf("%d\n",n);
		else{
			ans=min(minn*2,(n-maxx-1)*2);
			ans=n*2-ans;
			printf("%d\n",ans);
		}
	}
	return 0;
}
