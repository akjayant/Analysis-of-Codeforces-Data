#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b){
	return a>b;
}

void solvre(){
	int n;
	scanf("%d", &n);
	int v[100100];
	for(int i = 0; i<n; i++){
		scanf("%d", &v[i]);
	}
	sort(v, v+n, comp);
	long long ans = 0;
	for(int i = 0; i<n; i++){
		long long x = i+1;
		long long y = v[i];
		x = min(x, y);
		ans = max(ans, x);
	}
	cout<<ans<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--) solvre();
}
