#include <bits/stdc++.h>

using namespace std;


void solve(){
	int n;
	scanf("%d", &n);
	char sc[1005];
	scanf(" %s", sc);
	bool exists = false;
	for(int i=0;2*i<n;i++){
		if(sc[i]=='1' or sc[n-1-i]=='1'){
			printf("%d\n",2*(n-i));
			return;
		}
	}
	printf("%d\n",n);
}


int main(){
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
	
	return 0;
}
