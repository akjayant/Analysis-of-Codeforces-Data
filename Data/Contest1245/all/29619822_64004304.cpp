#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
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
	
	constexpr int P = 1e9 + 7;
	
	char s[100005];
	cin >> &s[1];
	
	int n = strlen(&s[1]);
	
	if(count(&s[1], &s[n]+1, 'm') || count(&s[1], &s[n]+1, 'w')) {
		cout << 0;
		return 0;
	}
	
	int f[100005];
	f[0] = 1;
	f[1] = 1;
	loop(i, 2, n)
		f[i] = (f[i-1] + f[i-2]) % P;
	
	int ans = 1;
	loop(i, 1, n)
	if(s[i] == 'u' || s[i] == 'n') {
		int j = i;
		while(j < n && s[j+1] == s[j])
			j++;
		
		ans = (LL)ans * f[j-i+1] % P;
		i = j;
	}
	
	cout << ans;
}