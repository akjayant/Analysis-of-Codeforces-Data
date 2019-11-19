#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define int long long

int n,m,a,b,c,d,x;

signed main()
{
	int T;
	cin >> T;
	while(T --)
	{
		cin >> a >> b >> c >> d >> x;
		int p = (a-1)/c+1,q = (b-1)/d+1;
		bool fl = 0;
		for(int i = 1; i < x; i ++) {
			if(i >= p && (x-i) >= q) {
				cout<<i<<" "<<x-i<<"\n";
				fl = 1;
				break;
			}
		}
		if(!fl) {
			cout<<-1<<"\n";
		}
	}	
	return 0;
}