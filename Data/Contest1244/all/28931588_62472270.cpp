#include<bits/stdc++.h>

using namespace std;

typedef long long INT;

char s[1111];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int T;
	cin >>T;

	while(T--) {
		int n; cin >> n;
		scanf("%s", s+1);
		int ans = n;
		for(int i=1; i<=n; i++) if(s[i] == '1') {
			ans = max(ans, i * 2);
			ans = max(ans, (n - i + 1) * 2);
		}
		cout << ans << endl;
	}



	return 0;
}

                               