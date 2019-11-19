#include <iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int main(){
	int T;
	ll N,M,K;
	ll a,b;
	cin>>T;
	while (T--){
		scanf("%lld",&N);
		a=b=0;
		for (int i=1;i<=N;i++){
			scanf("%lld",&K);
			if (K%2==0) a++;
		}
		scanf("%lld",&M);
		for (int i=1;i<=M;i++){
			scanf("%lld",&K);
			if (K%2==0) b++;
		}
		cout<<a*b+(N-a)*(M-b)<<endl;
	}
	return 0;
}
