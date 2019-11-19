#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define int long long int
#define mod 1000000007
void fast(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
main()
{
	fast();
	int n;
	cin>>n;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x1=0,x2=0;
	sort(a+1,a+n+1);
	if(n%2==1){
	for(int i=n;i>=(n+1)/2;i--){
		x2+=a[i];
	}
	for(int i=1;i<(n+1)/2;i++){
		x1+=a[i];
	}}
	else {
		for(int i=1;i<=n/2;i++){
			x1+=a[i];
			x2+=a[n-i+1];
		}
	}
	// cout<<x1<<" "<<x2<<endl;
	int ans=x1*x1+x2*x2;
	cout<<ans<<endl;
}