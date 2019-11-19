#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,m,t,a[100000];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0 ; i<n ; i++)cin>>a[i];
	sort(a,a+n);
	ll s1=0,s2=0;
	for(int i=0 ; i<n/2 ; i++){
		s1+=a[i];
	}
	for(int i=n/2 ; i<n ; i++){
		s2+=a[i];
	}
	if(n%2==0){
		cout<<s1*s1+s2*s2;
		return 0;
	}
	cout<<max(s1*s1+s2*s2,(s1+a[n/2])*(s1+a[n/2])+(s2-a[n/2])*(s2-a[n/2]));
}