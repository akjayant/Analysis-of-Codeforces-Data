#include<bits/stdc++.h>
typedef long long LL;
int a[200000],n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	LL ansx=0;
	LL ansy=0;
	int op=1;int l=1;int r=n;
	for (int i=1;i<=n;i++){
		if (op%2){
			ansx+=a[r];
			r--;
			op++;
		}else {
			ansy+=a[l];
			l++;
			op++;
		}
		if (l>r)break;
	}
	//printf("%lld %lld\n",ansx,ansy);
	printf("%lld\n",ansx*ansx+ansy*ansy);
	return 0;
}