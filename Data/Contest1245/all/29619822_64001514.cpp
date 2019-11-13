#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

#define repeat(n) for(register LL ______________ = (n); ______________ > 0; --______________)
#define loop(i, l, r) for(register LL i = (l), ________r = (r); i <= ________r; ++i)
#define iloop(i, l, r) for(register LL i = (l), ________r = (r); i < ________r; ++i)
#define rloop(i, r, l) for(register LL i = (r), ________l = (l); i >= ________l; --i)

typedef long long LL;

#ifdef CAI_WEI_HAN
#include "LOG.h"
#else
#define LOG(...) 1
#endif

signed main()
{
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
	#define cout cerr
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	constexpr char endl = '\n';
	
	int z;
	cin >> z;
	
	repeat(z) {
		int n, a, b, c;
		cin >> n >> a >> b >> c;
		
		string s;
		repeat(n) {
			char x;
			cin >> x;
			
			if(x == 'R' && b != 0) {
				b--;
				s += 'P';
			}
			
			else if(x == 'P' && c != 0) {
				c--;
				s += 'S';
			}
			
			else if(x == 'S' && a != 0) {
				a--;
				s += 'R';
			}
			
			else
				s += '?';
		}
		
		if(2 * (n-a-b-c) >= n) {
			cout << "Yes\n";
			for(auto& x : s)
			if(x == '?') {
				if(a) {
					x = 'R';
					a--;
				}
				else if(b) {
					x = 'P';
					b--;
				}
				else {
					x = 'S';
					c--;
				}
			}
			cout << s << endl;
		}
		
		else
			cout << "No\n";
	}
}