#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main(){
	sync
	long long n;
	cin >> n;
	long long ans=n;
	long long num=sqrt(n);
	for(long long i=2;i<=num;i++){
		if(n%i==0){
			ans=__gcd(ans,i);
			ans=__gcd(ans,n/i);
		}
	}
	if(ans!=0) cout << ans << "\n";
	else cout << n << "\n";
	return 0;
}