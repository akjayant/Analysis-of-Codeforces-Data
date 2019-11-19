#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N;
int A[100005];
ll ans1,ans2;

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);
	sort(A+1,A+N+1);
	for(int i=1;i<=N/2;i++) ans1+=A[i];
	for(int i=N/2+1;i<=N;i++) ans2+=A[i];
	printf("%I64d\n",ans1*ans1+ans2*ans2);
	
    return 0;
}
