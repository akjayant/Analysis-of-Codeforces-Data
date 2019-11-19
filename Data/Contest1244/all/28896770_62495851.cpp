#include<cstdio>
#include<algorithm>
using std::sort;
typedef long long ll;
const int N=1e5+5;
struct X{
	int z,s;
	bool operator<(const X &t)const{
		return z<t.z;
	}
}a[N];
int main(){
	int n;
	ll k;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",&a[i].z),a[i].s=1;
	int l=1,r=1;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i)
		if(a[i].z==a[r].z) ++a[r].s;
		else a[++r]=a[i];
	n=r;
	for(;l!=r&&k;){
		if(a[l].s<=a[r].s){
			if(k>=(a[l+1].z-a[l].z)*(ll)a[l].s){
				k-=(a[l+1].z-a[l].z)*(ll)a[l].s;
				a[l+1].s+=a[l].s;++l;
			}
			else{
				a[l].z+=k/a[l].s;
				k=0;
			}
		}
		else{
			if(k>=(a[r].z-a[r-1].z)*(ll)a[r].s){
				k-=(a[r].z-a[r-1].z)*(ll)a[r].s;
				a[r-1].s+=a[r].s;--r;
			}
			else{
				a[r].z-=k/a[r].s;
				k=0;
			}
		}
	}
	printf("%d",a[r].z-a[l].z);
	return 0;
}