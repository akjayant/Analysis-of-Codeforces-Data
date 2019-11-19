#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int a[N],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int p=n;
	ll tx=0,ty=0;
	for(int i=1;i<=n;i++)
	if(i>=p)break;
	else {
		tx+=a[p];p--;
		ty+=a[i];
	}
	if(n%2)tx+=a[p];
	printf("%lld\n",tx*tx+ty*ty);
	return 0;
}