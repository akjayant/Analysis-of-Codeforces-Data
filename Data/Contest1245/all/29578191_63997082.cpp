#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
typedef pair<int,int>pa;
priority_queue<pa,vector<pa>, greater<pa> >q;

int n;
const int N=100010;
int cnt[N];

int main(){
#ifdef WK
	freopen("in.txt","r",stdin);
#endif
	int T;scanf("%d",&T);
	while(T--){
		LL aa,bb;
		scanf("%lld%lld",&aa,&bb);
		LL gcd=__gcd(aa,bb);
		if(gcd==1)puts("Finite");else puts("Infinite");
	} 

	return 0; 
} 