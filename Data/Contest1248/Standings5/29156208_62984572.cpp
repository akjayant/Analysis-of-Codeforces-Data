#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll n,m;
int t;
long long w,h,ans;
const int N=1e5+10;
ll a[N];

bool cmp(ll x,ll y){
	return x>y;
}

 
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=(n+1)/2;i++){
		w+=a[i];
	}
	for(int i=(n+1)/2+1;i<=n;i++){
		h+=a[i];
	}
	ans=w*w+h*h;
	printf("%lld\n",ans);
	return 0;
} 