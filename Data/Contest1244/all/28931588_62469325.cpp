#include<bits/stdc++.h>

using namespace std;

typedef long long INT;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	INT n, p, d, w;
	cin >> n >> p >> w >> d;
	
	for(int i=0; i<=w; i++) if(p >= i * d and (p - i * d) % w == 0 and (p-i*d)/w+i<=n) {
		cout << (p-i*d)/w << ' ' << i << ' ' << n - (p-i*d)/w - i << endl;
		return 0;
	}
	
	puts("-1");
	

	return 0;
}

              