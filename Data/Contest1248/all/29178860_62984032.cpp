#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
typedef long long LL;

int a[N];


int main() {
	int t;
	t=1;
	while(t--) {
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		LL S1=0,S=0;
		for(int i=1;i<=n/2;i++) S1+=a[i];
		for(int i=1;i<=n;i++) S+=a[i];
		LL Ans=S1*S1+(S-S1)*(S-S1);
		cout<<Ans<<endl;
	}
}
			