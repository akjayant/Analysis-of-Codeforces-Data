#include<bits/stdc++.h>
using namespace std;

const int N=1e6;
int p[N];
bool vis[N];
long long n;

int main(){
	for(int i=2;i<=N;i++){
		if(!vis[i]) p[++p[0]]=i;
		for(int j=1;j<=p[0] && i*p[j]<=N;j++){
			vis[i*p[j]]=true;
			if(i%p[j]==0) break;
		}
	}
	scanf("%I64d",&n);
	if(n==1){
		printf("1");
		return 0;
	}
	int tot=0;
	long long op;
	for(int i=1;i<=p[0];i++) if(n%p[i]==0){
		tot++;op=p[i];
		while(n%p[i]==0) n/=p[i];
	}
	if(n!=1) tot++,op=n;
	if(tot>=2) printf("1");
	else printf("%I64d\n",op);
}