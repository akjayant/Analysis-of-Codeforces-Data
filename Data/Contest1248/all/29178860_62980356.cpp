#include<bits/stdc++.h>
using namespace std;

typedef long long LL;


const int N=1e5+10;


int a[N],b[N];

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n;
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		cin>>m;
		for(int i=1;i<=m;i++) scanf("%d",&b[i]);
		LL Ans=0;
		for(int i=1;i<=n;i++)
			if(a[i]&1) cnt1++;
		for(int i=1;i<=m;i++)
			if(b[i]&1) cnt2++;
		for(int i=1;i<=n;i++)
			if(a[i]&1) Ans+=cnt2;
			else Ans+=m-cnt2;
		for(int i=1;i<=m;i++)
			if(b[i]&1) Ans+=cnt1;
			else Ans+=n-cnt1;
		Ans/=2;
		cout<<Ans<<endl;
	}
}
		
	