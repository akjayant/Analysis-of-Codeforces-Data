#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(int argc, char const *argv[]){
	
	int n,t, dx,dy;

	scanf("%d", &n);
	for(int i=0;i<n;++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	t = (n+1) / 2;
	dx = 0;
	dy = 0;
	for(int i=0;i<t;++i) {
		dx += a[n-i-1];
	}
	t = n - t; 
	for(int i=0;i<t;++i) {
		dy += a[i];
	}
	printf("%I64d\n", 1LL * dx * dx + 1LL * dy * dy);
	return 0;
}	