#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N=100005;
int n,a[N],b[N],p,mi,mx,tot[N],ans;
long long k;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[i-1]=a[i];
	}
	sort(b,b+n);
	p=unique(b,b+n)-b;
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(b,b+p,a[i])-b;
		tot[a[i]]++;
	}
	mi=0,mx=p-1;
	ans=b[p-1]-b[0];
	while(k && mi<mx){
		if(tot[mi]<=tot[mx]){
			long long z=1ll*tot[mi]*(b[mi+1]-b[mi]);
			if(k>=z){
				k-=z;
				tot[mi+1]+=tot[mi];tot[mi]=0;
				ans-=b[mi+1]-b[mi];
				mi++;
				continue;
			}
			else{
				ans-=k/tot[mi];
				break;
			}
		}
		else{
			long long z=1ll*tot[mx]*(b[mx]-b[mx-1]);
			if(k>=z){
				k-=z;
				tot[mx-1]+=tot[mx];tot[mx]=0;
				ans-=b[mx]-b[mx-1];
				mx--;
				continue;
			}
			else{
				ans-=k/tot[mx];
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
