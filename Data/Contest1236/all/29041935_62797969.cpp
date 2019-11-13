#include <cstdio>
#include <iostream>
using namespace std;

int n;
int ans[305];

int main() {
	cin >> n;
	ans[1]=1;
	for (int i=2;i<=n;i+=2) {
		ans[i]=ans[i-1]+(2*n-1);
		ans[i+1]=ans[i]+1;
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			printf("%d ",ans[j]);
			if (j%2) ans[j]++;
			else ans[j]--;
		}
		printf("\n");
	}
	return 0;
}