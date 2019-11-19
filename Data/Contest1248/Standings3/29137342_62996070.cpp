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
	int a[100005];
	a[1]=2;
	a[2]=4;
	for(int i=3;i<=100000;i++){
		a[i]=a[i-1]+a[i-2];
		a[i]%=mod;
	}
	int n,m;
	cin>>n>>m;
	int ans=a[n]+a[m]-2+mod;
	ans%=mod;
	cout<<ans<<endl;
}