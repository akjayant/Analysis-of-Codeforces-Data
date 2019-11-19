#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int T,n,m,a,b,c,d,k;
int p,q;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		p=a/c;
		if(a%c)	p++;
		q=b/d;
		if(b%d)	q++;
		if(p+q>k)
			printf("-1\n");
		else
			printf("%d %d\n",p,q);
	}
	return 0;
}
