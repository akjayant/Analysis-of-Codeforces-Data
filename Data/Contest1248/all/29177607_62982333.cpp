#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int n,a[100050];
long long tot1,tot2,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n/2;i++) tot1+=a[i];
	for (int i=n/2+1;i<=n;i++) tot2+=a[i];
	ans=tot1*tot1+tot2*tot2;
	cout << ans << "\n";
	return 0;
} 
