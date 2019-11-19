#include<bits/stdc++.h>
#define ll long long
#define fr(i,x,y) for(int i=(x);i<=(y);i++)
#define rf(i,x,y) for(int i=(x);i>=(y);i--)
#define frl(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;
const int N=200002;
const int p=998244353;
int n;
ll K;
int a[N];
ll c[N],d[N];

void read(int &x){ scanf("%d",&x); }
void read(ll &x){ scanf("%lld",&x); }

int main(){
	read(n);read(K);
	fr(i,1,n) read(a[i]);
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(a[l+1]==a[l]&&l<=n) l++;
	if (l>n) return puts("0"),0;
	while(a[r-1]==a[r]&&r>=1) r--;
	while(l<r){
		if (l<n-r+1){
			if (1LL*(a[l+1]-a[l])*l>K){
				printf("%lld\n",a[r]-(a[l]+K/l));
				return 0;
			}
			K-=1LL*(a[l+1]-a[l])*l;l++;
		} else{
			if (1LL*(a[r]-a[r-1])*(n-r+1)>K){
				printf("%lld\n",a[r]-K/(n-r+1)-a[l]);
				return 0;
			}
			K-=1LL*(a[r]-a[r-1])*(n-r+1);r--;
		}
	}
	puts("0");
	return 0;
}