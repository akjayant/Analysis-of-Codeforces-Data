#include<bits/stdc++.h>
using namespace std;
long long p[2],q[2];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,x;
		p[0]=p[1]=q[0]=q[1]=0;
		scanf("%d",&n);
		while(n--){
			scanf("%d",&x);
			p[x&1]++;
		}
		scanf("%d",&m);
		while(m--){
			scanf("%d",&x);
			q[x&1]++;
		}
		printf("%I64d\n",q[1]*p[1]+q[0]*p[0]);
	}
}