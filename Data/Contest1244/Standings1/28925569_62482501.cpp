#include<bits/stdc++.h>
#define M 100005
#define LL long long
using namespace std;
int n,A[M];
LL K;
int main(){
	cin>>n>>K;
	for(int i=1;i<=n;i++)cin>>A[i];
	sort(A+1,A+n+1);
	int l=1,r=n;
	while(l<r){
		while(l<n&&A[l]==A[l+1])l++;
		while(r>1&&A[r]==A[r-1])r--;
		if(l>=r)break;
		LL c1=l,c2=n-r+1;
		if(c1<c2){
			LL ned=c1*(A[l+1]-A[l]);
			if(K>=ned)K-=ned,l++;
			else{
				A[l]+=K/c1;break;
			}
		}else{
			LL ned=c2*(A[r]-A[r-1]);
			if(K>=ned)K-=ned,r--;
			else{
				A[r]-=K/c2;break;
			}
		}
	}
	printf("%d\n",l<r?A[r]-A[l]:0);
	return 0;
}