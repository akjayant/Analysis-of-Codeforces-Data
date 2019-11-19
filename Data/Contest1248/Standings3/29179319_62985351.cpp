#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int main(){
	int n;
	ll len=0,high=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	int mindex=0,maxdex=n-1;
	while(mindex<=maxdex){
		len+=a[maxdex];
		maxdex--;
		if(mindex>maxdex)break;
		high+=a[mindex];
		mindex++;
	}
	printf("%lld\n",len*len+high*high);
}