#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=1e5+5;
typedef long long ll;
ll k;
int a[maxn];
ll ln,rn;
int main(){
	scanf("%d%lld",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int l=1,r=n;
	ln=rn=1;
	while (k>0&&l!=r){	
		if (ln>=rn){
			if (k>=rn*(a[r]-a[r-1])){
				k-=rn*(a[r]-a[r-1]);
				rn++;
				r--;
			}else{
				a[r]-=k/rn;
				break;
			}
		}else{
			if (k>=ln*(a[l+1]-a[l])){
				k-=ln*(a[l+1]-a[l]);
				ln++;
				l++;
			}else{
				a[l]+=k/ln;
				break;
			}
			
		}
	}
	cout << a[r]-a[l];
}