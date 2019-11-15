// #include<bits/stdc++.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N, ar[1003];
		scanf("%d", &N);
		for(int i=0;i<N;++i)
			scanf("%d", &ar[i]);
		sort(ar, ar+N);
		int ans = 0, cnt = 0;
		for(int i=N-1;i>=0;--i) {
			++cnt;
			// printf("%d->%d,", ar[i], cnt);
			if(ar[i]>=cnt);
			else {
				--cnt;
				break;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}