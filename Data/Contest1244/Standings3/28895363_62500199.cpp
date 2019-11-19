#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 100005;

int n;
LL k, a[N], dh[N], dq[N];

int main(){
	scanf("%d%lld", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++){
		dq[i] = a[i] - a[i-1];
		dh[i] = a[i+1] - a[i];
	}
	int l = 1, r = n;
	LL diff = a[n] - a[1];
	while(1){
		if(dh[l] * l <= k){
			k -= dh[l] * l;
			diff -= dh[l];
			l++;
		}
		else{
			diff -= k / l;
			break;
		}
		if(l >= r)	break;
		if(dq[r] * (n + 1 - r) <= k){
			k -= dq[r] * (n + 1 - r);
			diff -= dq[r];
			r--;
		}
		else{
			diff -= k / (n + 1 - r);
			break;
		}
		if(l >= r)	break;
	}
	printf("%lld\n", diff);
	return 0;
}
