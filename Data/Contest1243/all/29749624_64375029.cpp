using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define bb back()
#define ff front()
const ll inf=1e18;
const ll mod=998244353;
void boost(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
}
int main(){
boost();
int k,i,j;
cin>>k;
while (k--) {
	int n;
	cin>>n;
	int a[1001];
	for(i=1;i<=n;i++) {
		cin>>a[i];
	}
	int ans=0,q,r=1;
	sort(a+1,a+n+1);
	q=a[n];
	for(i=n-1;i>=1;i--) {
		q=min(q,a[i]);
		ans=min(n-i+1,q);
        r=max(r,ans);
	}
	cout<<r<<endl;
}
return 0;
}