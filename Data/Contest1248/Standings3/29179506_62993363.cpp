#include <iostream>
#include <algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
ll num[100000+10];
int main(){
	int N;
	ll ans,K;
	ans=K=0;
	cin>>N;
	for (int i=1;i<=N;i++){
		scanf("%d",&num[i]);
		ans+=num[i];
	}
	sort(num+1,num+N+1);
	for (int i=N;i>N/2;i--) K+=num[i];
	cout<<K*K+(ans-K)*(ans-K)<<endl;
	return 0;
}
