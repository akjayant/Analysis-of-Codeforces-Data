#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	int n;
	long long k;
	scanf("%d %lld", &n, &k);
	for(int i=0;i<n;i++){
		scanf("%lld", &a[i]);
	}
	sort(a, a+n);

	long long curmin=a[0], curmax=a[n-1];
	int i=0, j=n-1;
	while(i<j && k>0){
		while(i<n && a[i+1]<=curmin){
			i++;
		}
		while((j-1)>=0 && a[j-1]>=curmax){
			j--;
		}
		// printf("%d %d\n", i, j);
		if(j<=i){
			break;
		}
		if((i+1)==(n-j)){
			if(a[i+1]-a[i] > a[j]-a[j-1]){
				if(k>=(i+1)*(a[i+1]-a[i])){
					k-=(i+1)*(a[i+1]-a[i]);
					curmin=a[i+1];
				}
				else{
					curmin+=(k/(i+1));
					k=0;
				}
			}
			else{
				if(k>=(n-j)*(a[j]-a[j-1])){
					k-=(n-j)*(a[j]-a[j-1]);
					curmax=a[j-1];
				}
				else{
					curmax-=(k/(n-j));
					k=0;
				}	
			}
		}
		else if((i+1)<(n-j)){
			if(k>=(i+1)*(a[i+1]-a[i])){
				k-=(i+1)*(a[i+1]-a[i]);
				curmin=a[i+1];
			}
			else{
				curmin+=(k/(i+1));
				k=0;
			}
		}
		else{
			if(k>=(n-j)*(a[j]-a[j-1])){
				k-=(n-j)*(a[j]-a[j-1]);
				curmax=a[j-1];
			}
			else{
				curmax-=(k/(n-j));
				k=0;
			}
		}
		// printf("%d %d %lld %lld %lld\n", i, j, curmin, curmax, k);
	}

	printf("%lld\n", curmax-curmin);
	return 0;
}