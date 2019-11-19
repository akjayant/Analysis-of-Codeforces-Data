#include <bits/stdc++.h>
using namespace std;
int n , m , q , w;

int s[2] , t[2];

int main()
{
	cin >> q;
	while(q--)
	{
		s[0] = s[1] = t[0] = t[1] = 0;
		cin >> n;
		while(n--) {cin >> w ; s[w & 1] ++ ;}
		cin >> m;
		while(m--) {cin >> w ; t[w & 1] ++ ;}
		cout << 1ll * s[0] * t[0] + 1ll * s[1] * t[1] << endl;
	}
} 
