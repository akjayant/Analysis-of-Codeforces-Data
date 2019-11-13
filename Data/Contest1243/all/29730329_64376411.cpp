#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int vet[N];

int main(){
	int t;
	scanf("%d",&t);
	while (t-- > 0){
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; i++) scanf("%d", &vet[i]);
		sort(vet, vet+n, greater < int >());
		int ans = 1;
		int mn = vet[0];
		for (int i=1; i<n; i++){
			mn = min(vet[i], mn);
			ans = max(ans, min(i+1, mn) * min(i+1, mn));
		}
		printf("%d\n", (int)sqrt(ans));
	}
}
