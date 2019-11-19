#include <bits/stdc++.h>
using namespace std;
long long n, a[100005], sumv, sumh, ans, mid;
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> n;
for (int i=0; i<n; i++) cin >> a[i];
sort(a, a+n);
if (n%2){
	mid=n/2;
	sumh=sumv=0;
	for (int i=0; i<mid; i++){
		sumh+=a[i];
	}
	for (int i=mid; i<n; i++){
		sumv+=a[i];
	}
	ans=sumv*sumv + sumh* sumh;
	
	mid=(n+1)/2;
	sumh=sumv=0;
	for (int i=0; i<mid; i++){
		sumh+=a[i];
	}
	for (int i=mid; i<n; i++){
		sumv+=a[i];
	}
	ans=max(ans, sumv*sumv + sumh* sumh);
}
else{
	mid=n/2;
	sumh=sumv=0;
	for (int i=0; i<mid; i++){
		sumh+=a[i];
	}
	for (int i=mid; i<n; i++){
		sumv+=a[i];
	}
	ans=sumv*sumv + sumh* sumh;
}
cout << ans;
return 0;
}

