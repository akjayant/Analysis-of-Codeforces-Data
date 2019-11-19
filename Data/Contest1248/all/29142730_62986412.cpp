#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m;
int a[maxn];
int cnta[3];
int b[maxn];
int cntb[3];

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		cnta[1] = cnta[2] = cntb[1] = cntb[2] = 0;
		scanf("%d", &n);
		for(register int i = 1; i <= n; i ++){
			scanf("%d", &a[i]);
			if(a[i] & 1)cnta[1]++;
			else cnta[2]++;
		}
		scanf("%d", &m);
		for(register int i = 1; i <= m; i ++){
			scanf("%d", &b[i]);
			if(b[i] & 1)cntb[1]++;
			else cntb[2]++;
		}
		//cout<<"f"<<cnta[1] <<" "<< cntb[1]<<" "<<cnta[2]<<" "<<  cntb[2]<<endl;
		printf("%lld\n", 1LL * cnta[1] * cntb[1] + 1LL * cnta[2] * cntb[2]);
	}
	return 0;
}